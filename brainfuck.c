/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:37:38 by pabril            #+#    #+#             */
/*   Updated: 2016/02/03 10:58:53 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int i;
	int k;
	unsigned char *tab;

	k = 1;
	i = 0;
	tab = (unsigned char *)malloc(sizeof(unsigned char) * 2049);
	while (tab[i])
	{
		tab[i] = 0;
		i++;
	}
	tab[2048] = '\0';
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '+')
			(*tab)++;
		else if (argv[1][i] == '-')
			(*tab)--;
		else if (argv[1][i] == '<')
			tab--;
		else if (argv[1][i] == '>')
			tab++;
		else if (argv[1][i] == '.')
			write(1, &(*tab), 1);
		else if (argv[1][i] == '[' && *tab == 0)
		{
			i++;
			k = 1;
			while(argv[1][i] != ']' || k != 1)
			{
				if (argv[1][i] == '[')
					k++;
				else if (argv[1][i] == ']')
					k--;
				i++;
			}
		}
		else if (argv[1][i] == ']' && *tab != 0)
		{
			i--;
			k = 1;
			while (argv[1][i] != '[' || k != 1)
			{
				if (argv[1][i] == ']')
					k++;
				else if (argv[1][i] == '[')
					k--;
				i--;
			}
		}
		i++;
	}
}
