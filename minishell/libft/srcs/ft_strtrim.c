#include "libft.h"

static size_t	ft_f_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_f_end(char const *s1, char const *set, size_t start)
{
	size_t	i;
	size_t	j;

	if (!s1[start])
		return (start);
	i = start;
	while (s1[i])
		i++;
	i--;
	while (i > start)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			break ;
		i--;
	}
	return (i);
}

/*
**	@brief	allocates and returns a copy of string 
**			with the characters specified in delimiters removed
**			from the beginning and the end of the string.
**	
**	@param	s1		pointer to string
**	@param	set		pointer to string of delimiters
**	@return	char*	pointer to new truncated string or NULL if allocation fail
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rez;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = ft_f_start(s1, set);
	end = ft_f_end(s1, set, start);
	rez = malloc((sizeof(char) * (end - start)) + 2);
	if (!rez)
		return (NULL);
	i = 0;
	while ((i + start) <= end)
	{
		rez[i] = s1[start + i];
		i++;
	}
	rez[i] = 0;
	return (rez);
}
