#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	3
#define TYPE_PIPE	4
#define TYPE_BREAK	5

typedef struct s_data
{
	char			**av;
	int				size;
	int				type;
	int				fd[2];
	struct s_data	*prev;
	struct s_data	*next;
} t_data;

/* utils */

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		len;
	int		i;
	char	*rez;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	rez = malloc(sizeof(char) * (len + 1));
	if (!rez)
		return (NULL);
	i = 0;
	while (i < len)
		rez[i] = str[i], i++;
	rez[i] = 0;
	return (rez);
}

void	ft_putstr_fd(char *str, int fd, int endl)
{
	write(fd, str, ft_strlen(str));
	if (endl)
		write(fd, "\n", 1);
}

/* errors */

void	exit_fatal(void)
{
	ft_putstr_fd("error: fatal", STDERR, 1);
	exit(EXIT_FAILURE);
}

void	exit_execv(char *str)
{
	ft_putstr_fd("error: cannot execute ", STDERR, 0);
	ft_putstr_fd(str, STDERR, 1);
	exit(EXIT_FAILURE);
}

int	exit_cd_arg()
{
	ft_putstr_fd("error: cd: bad arguments", STDERR, 1);
	return (EXIT_FAILURE);
}

int	exit_change(char *str)
{
	ft_putstr_fd("error: cd: cannot change directory to ", STDERR, 0);
	ft_putstr_fd(str, STDERR, 1);
	return (EXIT_FAILURE);
}

/* parsing */

void	ft_lstadd_back(t_data **beg, t_data *new)
{
	t_data	*tmp;

	if (!(*beg))
		*beg = new;
	else
	{
		tmp = *beg;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int	ft_size_av(char **av)
{
	int i;

	i = 0;
	while (av && av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
		i++;
	return (i);
}

int	ft_check_end(char *av)
{
	if (!av)
		return (TYPE_END);
	else if (strcmp(av, "|") == 0)
		return (TYPE_PIPE);
	else if (strcmp(av, ";") == 0)
		return (TYPE_BREAK);
	return (0);
}

int	ft_pars_av(t_data **beg, char **av)
{
	int		size;
	t_data	*new;
	int		i;

	size = ft_size_av(av);
	if (!(new = malloc(sizeof(t_data))))
		exit_fatal();
	if (!(new->av = malloc(sizeof(char *) * (size + 1))))
		exit_fatal();
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	i = 0;
	while (i < size)
		new->av[i] = ft_strdup(av[i]), i++;
	new->av[i] = NULL;
	new->type = ft_check_end(av[new->size]);
	ft_lstadd_back(beg, new);
	return (new->size);
}

/* exec */

void	ft_exec_cmd(t_data *tmp, char **env)
{
	pid_t	pid;
	int		state;
	int		pipe_open;

	pipe_open = 0;
	if (tmp->type == TYPE_PIPE || (tmp->prev && tmp->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(tmp->fd))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0) // child
	{
		if (tmp->type == TYPE_PIPE && dup2(tmp->fd[1], STDOUT) < 0)
			exit_fatal();
		if (tmp->prev && tmp->prev->type == TYPE_PIPE && dup2(tmp->prev->fd[0], STDIN) < 0)
			exit_fatal();
		if ((execve(tmp->av[0], tmp->av, env)) < 0)
			exit_execv(tmp->av[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &state, 0);
		if (pipe_open)
		{
			close(tmp->fd[1]);
			if (!tmp->next || tmp->type == TYPE_BREAK)
				close(tmp->fd[0]);
		}
		if (tmp->prev && tmp->prev->type == TYPE_PIPE)
			close(tmp->prev->fd[0]);
	}
}

void	ft_cd(t_data *beg, char **env)
{
	t_data *tmp;

	tmp = beg;
	while (tmp)
	{
		if (strcmp("cd", tmp->av[0]) == 0)
		{
			if (tmp->size < 2)
				exit_cd_arg();
			else if (chdir(tmp->av[1]))
				exit_change(tmp->av[1]);
		}
		else
			ft_exec_cmd(tmp, env);
		tmp = tmp->next;
	}
}

void	ft_clear(t_data *beg)
{
	t_data	*tmp;
	int		i;

	while (beg)
	{
		tmp = beg->next;
		i = 0;
		while (i <beg->size)
			free(beg->av[i]), i++;
		free(beg->av), free(beg);
		beg = tmp;
	}
	beg = NULL;
}

/* main */
int	main(int ac, char **av, char **env)
{
	t_data	*beg;
	int		i;

	// i = 0;
	// while (i < ac)
	// 	printf("%s\n", av[i]), i++;
	// exit(0);
	beg = NULL;
	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			if (strcmp(av[i], ";") == 0)
			{
				i++;
				continue ;
			}
			i += ft_pars_av(&beg, &av[i]);
			if (!av[i])
				break ;
			else
				i++;
		}
		// while (beg)
		// {
		// 	printf("=================\n");
		// 	for (i = 0; i < beg->size; i++)
		// 		printf("%s\t", beg->av[i]);
		// 	printf("\nTYPE: %d\n", beg->type);
		// 	printf("SIZE: %d\n", beg->size);
		// 	printf("curr: %p\n", beg);
		// 	printf("next: %p\n", beg->next);
		// 	printf("prev: %p\n", beg->prev);
		// 	printf("=================\n");
		// 	beg = beg->next;
		// }
		if (beg)
			ft_cd(beg, env);
		ft_clear(beg);
	}
	return (0);
}