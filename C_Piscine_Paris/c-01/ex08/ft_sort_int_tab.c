/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:13:46 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/16 16:13:48 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;
	int	min_ind;

	i = 0;
	j = 0;
	min_ind = 0;
	while (j < size)
	{
		i = j;
		min = tab[j];
		while (i < size)
		{
			if (tab[i] <= min)
			{
				min = tab[i];
				min_ind = i;
			}
			i++;
		}
		ft_swap(&tab[min_ind], &tab[j]);
		j++;
	}
}

/*
int main() {
	int *tab = (int[]){2,4,1,3,9,2, -1, 10};
	ft_sort_int_tab(tab, 8);
	for(int i=0;i<8;++i) {
  	printf("%d ", tab[i]);
	}
}*/