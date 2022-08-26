#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_clients {
    int id;
    char msg[1024];
} t_client;

t_client clients[1024]; // массив из 1024 структур (тут хранятся подключенные клиенты)
int fdMax = 0; // максимальный fd нуэен для select
int idNext = 0; // id клиентов от 0,1,2...
fd_set fd_read, fd_write, curr_sock; 
char bufRead[65536]; // что читаем из сокета
char bufWrite[65536]; // что пишем из сокета

void ft_fatal() {
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    exit(1);
}

void sendAll(int notfd) {
    for (int i = 0; i <= fdMax; i++) {
        if (FD_ISSET(i, &fd_write) && i != notfd) {
            send(i, bufWrite, strlen(bufferWrite), 0);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        exit(1);
    }
    struct sockaddr_in servaddr; // инициализируем структуру для соединения
    int sockfd;
    int len;
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0)
        ft_fatal();

    FD_ZERO(&curr_sock);//Инициализирует набор файловых дескрипторов fdset, чтобы иметь нулевые биты для всех файловых дескрипторов.
    bzero(&servaddr, sizeof(servaddr)); 
    bzero(&clients, sizeof(clients)); // обнуляем стуктуру клиентов
    fdMax = sockfd;
    FD_SET(sockfd, &curr_sock);//Устанавливает бит для файлового дескриптора fd в наборе файловых дескрипторов fdset.
    
    // assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 

    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0)
        ft_fatal();
    if (listen(sockfd, 10) < 0) 
        ft_fatal();

    while (1) {
        fd_read = fd_write = curr_sock;
        // Функция select() указывает, какой из указанных файловых дескрипторов готов к
        // чтению, готов к записи или имеет ожидающее состояние ошибки
        if (select(fdMax + 1, fd_read, fd_write, NULL, NULL) < 0)
            continue;
        for (int fdI = 0; fdI <= fdMax; fdI++) {
            // существует ли ещё файловый дескриптор на чтение в наборе
            // и если это слушающий сокет
            if (FD_ISSET(fdI, &fd_read) && fdI == sockfd) {
                // функция извлекает первый запрос на соединение из очереди ожидающих соединений,
                // создаёт новый подключенный сокет, и выделяет для сокета новый файловый дескриптор,
                // который и возвращается. 
                int connfd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
                if (connfd < 0)
                    continue;
                fdMax = connfd > fdMax ? connfd : fdMax; // обновляем max fd 
                clients[connfd].id = idNext++; // присваиваем данному соединению id, начинающийся с 0
                FD_SET(connfd, &curr_sock); // добавляем новый сокет в пул
                sprintf(bufWrite, "server: client %d just arrived\n", clients[connfd].id); // пишем в bufWrite
                sendAll(connfd);
                break;
            }
            // читаем из сокета
            if (FD_ISSET(fdI, &fd_read) && fdI != sockfd) {
                // получение сообщений из сокета
                int res = recv(fdI, bufRead, strlen(bufRead), 0);
                if (res <= 0) {
                    sprintf(bufWrite, "server: client %d just left\n", clients[fdI].id);
                    sendAll(fdI);
                    FD_CLR(fdI, &curr_sock); // убрать fd из пула
                    close(fdI); // закрыть соединение
                    break;
                } else {
                    for (int i = 0, j = strlen(clients[fdI].msg); i < res; i++, j++) {
                        clients[fdI].msg[j] = bufRead[i]; // пишем в сообщение клиента, читая из буфера
                        if (clients[fdI].msg[j] == "\n") { // если доходим до конца строки, то
                            clients[fdI].msg[j] = "\0"; // зануляем
                            sprintf(bufWrite, "client %d: %s\n", clients[fdI].id, clients[fdI].msg); // пишем в буфер Письма
                            sendAll(fdI); // шлем всем
                            bzero(&clients[fdI].msg, strlen(clients[fdI].msg)); // обнуляем наше сообщение, чтобы записать туда новое и снова отослать в след итерации
                            j = -1; // идем с 0 в след сообщении, тогда как bufRead идет дальше
                        }
                    }
                    break;
                }
            }
        }    

    }    
}


