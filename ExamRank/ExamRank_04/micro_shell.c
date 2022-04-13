#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#define TYPE_PIPE 1
#define TYPE_BREAK 2
#define TYPE_NONE 0

typedef struct s_list
{
	char			**args;//массив строк команд до остановителя
	int 			count_cmd;//количество слов до остановителя
	int 			type;//тип остановителя в списке (идет последним)( | ; null)
	int 			fd[2];
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int count_words_before_pipe(char **argv)
{
	int i = 0;
	while (argv && argv[i] && strcmp(argv[i], ";") != 0 && strcmp(argv[i],
																  "|") != 0)
		i++;
	return (i);
}

int ft_error_fatal()
{
	write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(1);
	return (1);
}

char *ft_strdup(char *str)
{
	char *new_str;
	int i = 0;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
	{
		ft_error_fatal();
		return (NULL);
	}
	while (i < ft_strlen(str))
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int ft_check_type(char *last_type)
{
	if (!last_type)
		return (TYPE_NONE);
	if (!strcmp(last_type, "|"))
		return (TYPE_PIPE);
	if (!strcmp(last_type, ";"))
		return (TYPE_BREAK);
	return (0);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int parse_argv(t_list **lst, char **argv)
{
	t_list *new;
	int i = 0;

	new = malloc(sizeof(t_list));//малочим память под текущий новый лист
	if (!new)
		return (ft_error_fatal());
	new->count_cmd = count_words_before_pipe(argv);//считаем количество слов
	// до пайпа или ; или конца
	new->args = malloc((sizeof(char *) * (new->count_cmd + 1)));//выделяем
	// память под наши аргументы
	if (!new->args)
		return (ft_error_fatal());
	new->next = NULL;
	new->prev = NULL;
	while (i < new->count_cmd)//заполняем аргументы (считаем до количества слов)
	{
		new->args[i] = ft_strdup(argv[i]);
		i++;
	}
	new->args[i] = NULL;//последний обязательно занулим, иначе будет ошибка в
	// execve
	new->type = ft_check_type(argv[new->count_cmd]);//смотрим тип
	// остановки который идет после нашей команы
	ft_lstadd_back(lst, new); // добавляем наш новый лист в конец двусвязного
	// списка
	return (i);
}

void ft_error_cd(char *str)
{
	write(2, "error: cd: cannot change directory to ", ft_strlen("error: cd: "
																 "cannot change directory to "));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void ft_error_cd_arg()
{
	write(2, "error: cd: bad arguments\n", ft_strlen("error: cd: bad "
													 "arguments\n"));
}

void ft_error_exec(char *str)
{
	write(2, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void ft_cmd(t_list *lst, char **env)
{
	int pid;
	int status;

	if (lst && lst->type == TYPE_PIPE)//если встретили в текущем листе пайп, то открываем его
	{
		if (pipe(lst->fd) < 0)
			ft_error_fatal();
	}
	pid = fork();//создаем еще один процесс
	if (pid < 0)
		ft_error_fatal();
	if (pid == 0)//ребенок
	{
		if (lst->type == TYPE_PIPE)//если текущий пайп
		{
			if (dup2(lst->fd[1], 1) < 0)//подменяем stdout(1) в наш пайповый fd[1]
				ft_error_fatal();
		}
		if (lst->prev && lst->prev->type == TYPE_PIPE)//если предыдущий лист с типом пайпа
		{
			if (dup2(lst->prev->fd[0], 0) < 0)//подменяем stdin(0) в наш пайп fd[0]
				ft_error_fatal();
		}
		if ((execve(lst->args[0], lst->args, env) < 0))//выполняем команду
			ft_error_exec(lst->args[0]);//в случае ошибки
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);//джем ребенка
		if (lst->type == TYPE_PIPE)//закрываем фдешники
			close(lst->fd[1]);
		if (lst->prev && lst->prev->type == TYPE_PIPE)
			close(lst->prev->fd[0]);
	}
}

void ft_exec(t_list *lst, char **env)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)//итерируемся по каждому листу
	{
		if (!strcmp("cd", tmp->args[0]))//если встретили команду cd
		{
			if (tmp->count_cmd != 2) //проверяем то что у cd не может быть
				// меньше или больше 2 параметров (первый-cd, второй-путь)
				ft_error_cd_arg();
			else if (chdir(tmp->args[1]) < 0)//выполняем cd
				ft_error_cd(tmp->args[1]);
		}
		else
			ft_cmd(tmp, env);//в остальных случаях выполняем встроенные команды
		tmp = tmp->next;
	}
}

void print_lst(t_list *lst)
{
	t_list *tmp;
	int i = 0;

	tmp = lst;
	while (tmp)
	{
		i = 0;
		while (i < tmp->count_cmd)
			printf("%s\n", tmp->args[i++]);
		printf("%d\n", tmp->type);
		tmp = tmp->next;
	}
}

void free_all(t_list *lst)
{
	int i = 0;
	t_list *tmp;

	tmp = lst;
	while (tmp->next)//чистим до последнего
	{
		i = 0;
		while (i < tmp->count_cmd)
			free(tmp->args[i++]);
		free(tmp->args);
		tmp = tmp->next;
		if (tmp->prev)
			free(tmp->prev);
	}
	i = 0;//чистим последний
	while (i < tmp->count_cmd)
		free(tmp->args[i++]);
	free(tmp->args);
	free(tmp);
}

int main(int argc, char **argv, char **env)
{
	t_list *lst = NULL;
	int i = 1;

	argv[argc] = NULL;
	while (i < argc)
	{
		if (!strcmp(";", argv[i]))
		{
			i++;
			continue;
		}
		i += parse_argv(&lst, &argv[i]);//подаем указатель на текущий argv
		// .потом будет отсчет с [0]
		if (!argv[i])
			break ;
		else
			i++;
	}
//	print_lst(lst);// выводим список аргументов
	if (lst) //если список листов не пустой то выполняем команды
		ft_exec(lst, env);
	free_all(lst);//чистка всего
//	while (1);
	return (0);
}