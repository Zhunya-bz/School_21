#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	int len = 0;
	while (s[i])
	{
		len++;
		i++;
	}
	return (len);
}

int main(int argc, char **argv)
{
	int i = 0;
	int k;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			int j = 0;
			while (j < i)
			{
				if (argv[1][i] == argv[1][j])
					break;
				j++;
			}
			if (i == j)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			int j = 0;
			while (j < ft_strlen(argv[1]))
			{
				if (argv[2][i] == argv[1][j])
					break;
				j++;
			}
			k = 0;
			while (k < i)
			{
				if (argv[2][i] == argv[2][k])
					break;
				k++;
			}
			if (j == ft_strlen(argv[1]) && (k == i))
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
