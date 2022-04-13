#include "string.h"
#include "stdlib.h"
#include "unistd.h"

#define TYPE_DEF    0
#define TYPE_PIPE   1
#define TYPE_BREAK  2

typedef struct s_list {
	char **args;
	int length;
	int pipes[2];
	int type;
	struct s_list *next;
	struct s_list *prev;
}		t_list;

int ft_strlen(char *str){
	int i;
	for (i = 0; str[i]; i++);
	return (i);
}

int show_err(char *str) {
	write(2, str, ft_strlen(str));
	return (1);
}

int exit_fatal() {
	show_err("error: fatal\n");
	exit (1);
	return (1);
}

void *exit_fatal_ptr() {
	exit_fatal();
	return (NULL);
}

char *ft_strdup(char *str) {
	char *tmp = malloc(sizeof(char ) * (ft_strlen(str) + 1));

	if (!tmp)
		return (exit_fatal_ptr());
	for (int i = 0, len = ft_strlen(str); i <= len; i++)
		tmp[i] = str[i];
	return (tmp);
}

int add_arg(t_list *list, char *arg) {
	char **tmp = malloc(sizeof(char *) * (list->length + 2));
	int i;

	if (!tmp)
		return (exit_fatal());
	for (i = 0; i < list->length; i++)
		tmp[i] = list->args[i];
	tmp[i] = ft_strdup(arg);
	tmp[++i] = NULL;
	if (list->length)
		free(list->args);
	list->args = tmp;
	list->length++;
	return (0);
}

int add_list(t_list **list, char *arg) {
	t_list *tmp = (t_list *)malloc(sizeof(t_list));

	if (!tmp)
		return (exit_fatal());
	tmp->length = 0;
	tmp->args = NULL;
	tmp->type = TYPE_DEF;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (*list) {
		(*list)->next = tmp;
		tmp->prev = *list;
	}
	*list = tmp;
	return (add_arg(*list, arg));
}

int toFirst(t_list **list) {
	while (*list && (*list)->prev)
		*list = (*list)->prev;
	return (0);
}

int list_clear(t_list **list) {
	t_list *tmp;

	toFirst(list);
	while (*list) {
		tmp = *list;
		*list = (*list)->next;
		for (int i = 0; i < tmp->length; i++)
			free (tmp->args[i]);
		free (tmp->args);
		free (tmp);
	}
	return (0);
}

int parse_arg(t_list **list, char *arg) {
//	int is_break = 0;
//	if (strcmp((";", arg)) == 0)
//		is_break = 1;
	int is_break = (strcmp(";", arg) == 0);

	if (is_break && !*list)
		return (0);
	else if (!is_break && (!*list || (*list)->type > TYPE_DEF))
		return (add_list(list, arg));
	else if (!strcmp("|", arg))
		(*list)->type = TYPE_PIPE;
	else if (is_break)
		(*list)->type = TYPE_BREAK;
	else
		return(add_arg(*list, arg));
	return (0);
}

int exec_cmd(t_list *list, char **env) {
	int pid, res = 0;

	if (list && list->type == TYPE_PIPE)
		if (pipe(list->pipes) == -1)
			return (exit_fatal());
		pid = fork();
		if (pid < 0)
			return (exit_fatal());
		if (!pid) {
			if (list->type == TYPE_PIPE){
				if (dup2(list->pipes[1], 1) == -1)
					return (exit_fatal());
			}
			if (list->prev && list->prev->type == TYPE_PIPE) {
				if (dup2(list->prev->pipes[0], 0) == -1)
					return (exit_fatal());
			}
			res = execve(list->args[0], list->args, env);
			show_err("error: cannot execute ");
			show_err(list->args[0]);
			write(2, "\n", 1);
			exit(res);
		}
		else {
			waitpid(pid, &res, 0);
			if (list->type == TYPE_PIPE)
				close(list->pipes[1]);
			if (list->prev && list->prev->type == TYPE_PIPE)
				close(list->prev->pipes[0]);
			res /= 256;
		}
		return (res);
}

int exec_cmds(t_list **list, char **env) {
	int res = 0;

	toFirst(list);
	while (*list) {
		if (!strcmp("cd", (*list)->args[0])) {
			res = 0;
			if ((*list)->length < 2)
				res = show_err("error: cd: bad arguments\n");
			else if (chdir((*list)->args[1])) {
				res = show_err("error: cd: cannot change directory to ");
				show_err((*list)->args[1]);
				write(2, "\n", 1);
			}
		}
		else
			res = exec_cmd(*list, env);
		*list = (*list)->next;
	}
	return (res);
}

int main(int argc, char **argv, char **env) {
	t_list *list = NULL;
	int res = 0;

	for (int i = 1; i < argc; i++)
		parse_arg(&list, argv[i]);
	if (list)
		res = exec_cmds(&list, env);
	list_clear(&list);
	return (res);
}