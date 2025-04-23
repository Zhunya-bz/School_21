/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:12:40 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/16 12:12:42 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;

	div = *a / *b;
	*b = *a % *b;
	*a = div;
}

/*
int main() {
	int *div;
	int *mod;
	int divv = 9;
	int modd = 5;
	div = &divv;
	mod = &modd;
	ft_ultimate_div_mod(div, mod);
	printf("%d %d", *div, *mod);
}*/