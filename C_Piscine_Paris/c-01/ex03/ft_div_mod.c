/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekanaeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:37:31 by ekanaeva          #+#    #+#             */
/*   Updated: 2025/01/16 11:37:32 by ekanaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int main() {
	int *div;
	int *mod;
	int divv;
	int modd;
	div = &divv;
	mod = &modd;
	ft_div_mod(11, 3, div, mod);
	printf("%d %d", *div, *mod);
}*/
