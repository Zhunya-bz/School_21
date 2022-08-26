#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client {
    int id;
    int fd;
    struct s_client * next;
} t_client;

t_client * g_clients = NULL;

int sock_fd, g_id = 0;
fd_set read_sock, write_sock, curr_sock;
char str[42 * 4096], buf[42 * 4096 + 42], tmp[42 * 4096];

void fatal() {
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    close(sock_fd); // закрываем fd сокета
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        exit(1);
    }
    struct sockaddr_in servaddr, cli;
    int port = atoi(argv[1]);
    // обнуляем структурку сокетов и привязываем ее к порту и хосту
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 

    if (sock_fd = socket(AF_INET, SOCK_STREAM, 0) < 0)
        fatal();
    if (bind(sock_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        fatal();
    if (listen(sock_fd, 0) < 0)
        fatal();

    FD_ZERO(&curr_sock); //Инициализирует набор файловых дескрипторов fdset, чтобы иметь нулевые биты для всех файловых дескрипторов.
    FD_SET(sock_fd, &curr_sock); //Устанавливает бит для файлового дескриптора fd в наборе файловых дескрипторов fdset.            
    bzero(&tmp, sizeof(tmp)); // обнуляем временный массив для сообщений
    bzero(&str, sizeof(str)); // обнуляем массив для сообщений
    bzero(&buf, sizeof(buf)); // обнуляем буфер для сообщений

    while (1) {
        sock_write = sock_read = curr_sock;
        // Функция select() указывает, какой из указанных файловых дескрипторов готов к
        // чтению, готов к записи или имеет ожидающее состояние ошибки
        if (select(get_max_fd() + 1, sock_read, sock_write, NULL, NULL) < 0)
            continue;
            
    }
}