/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:52:37 by yperonne          #+#    #+#             */
/*   Updated: 2021/12/15 13:41:20 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countset(char const *str, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
				k++;
		}
		i++;
	}
	return (k);
}

char	**filltab(char **tab, int nbrl, char const *str, char c)
{
	size_t	i;
	int		k;
	size_t	p;

	i = 0;
	k = 0;
	p = 0;
	while (k < nbrl)
	{
		if (str[i] != c && str[i])
		{
			while (str[i + p] != c && str[i + p])
				p++;
			tab[k++] = ft_substr(str, i, p);
			i = i + p - 1;
			p = 0;
		}
		i++;
	}
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;

	tab = NULL;
	if (!str)
		return (NULL);
	tab = ft_calloc((countset(str, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	tab[countset(str, c)] = (char *) '\0';
	tab = filltab(tab, countset(str, c), str, c);
	return (tab);
}

/*int	main(void)
{
	int		i;
	char	str[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. 
	Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, 
	ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, 
	varius a, semper congue, euismod non, mi.";
	char	**tabmain;

	i = 0;
	tabmain = ft_split(str, 'z');
	while (tabmain[i] != (char *)'\0')
	{
		printf("tabmain[%d] : %s\n", i, tabmain[i]);
		i++;
	}
	return (0);
}*/
