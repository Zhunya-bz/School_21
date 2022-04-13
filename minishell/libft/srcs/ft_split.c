#include "libft.h"

/*
**	@brief	counts the number of substrings in a string
**	
**	@param	s		pointer to string
**	@param	c		delimiter character
**	@return	int		counts substrings
*/
int	ft_count_words(char const *s, char c)
{
	size_t	i;
	int		wrd;

	wrd = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			wrd++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (wrd);
}

static void	ft_free_all(char **rez, int fl)
{
	fl = (-1) * fl;
	while (fl != 0)
	{
		free (rez[fl]);
		rez[fl] = NULL;
		fl--;
	}
	free (rez[0]);
	free (rez);
	rez = NULL;
}

static int	ft_conadd_let(char const *s, char c, char **rez)
{
	int		i;
	int		j;
	char	*rit;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	rit = malloc(sizeof(char) * (i + 1));
	if (!rit)
		return (0);
	j = 0;
	while (*(s + j) && j < i)
	{
		rit[j] = *(s + j);
		j++;
	}
	rit[j] = 0;
	*rez = rit;
	return (1);
}

static int	ft_add_newwr(char const *s, char c, int i, char **rez)
{
	int		j;
	int		wrd;
	int		k;

	k = 1;
	wrd = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			if (wrd == i)
				break ;
			wrd++;
			while (s[j] && s[j] != c)
				j++;
		}
	}
	if (s[j])
		k = ft_conadd_let(&s[j], c, rez);
	if (!k || wrd != i)
		return (-i);
	return (1);
}

/*
**	@brief	creates array of strings obtained by splitting ’s’ 
**			using the character ’c’ as a delimiter.
**	
**	@param	s		pointer to string
**	@param	c		delimiter character
**	@return	char**	pointer to new array of strings, terminated by a NULL
*/
char	**ft_split(char const *s, char c)
{
	int		wrd;
	int		i;
	int		fl;
	char	**rez;

	if (!s)
		return (NULL);
	wrd = ft_count_words(s, c);
	rez = malloc(sizeof(rez) * (wrd + 1));
	if (!rez)
		return (NULL);
	i = 0;
	while (i < wrd)
	{
		fl = ft_add_newwr(s, c, i, &rez[i]);
		if (fl != 1)
		{
			ft_free_all(rez, fl);
			return (NULL);
		}
		i++;
	}
	rez[i] = NULL;
	return (rez);
}
