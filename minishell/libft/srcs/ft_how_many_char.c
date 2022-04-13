#include "libft.h"

int	ft_how_many_char(char *str, char c)
{
	int	i;
	int	rez;

	rez = 0;
	if (!str)
		return (rez);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			rez++;
		i++;
	}
	return (rez);
}
