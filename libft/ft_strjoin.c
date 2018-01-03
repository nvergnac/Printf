/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:33:54 by pclement          #+#    #+#             */
/*   Updated: 2017/11/16 14:24:27 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*fresh_str;

	if (!(s1 && s2))
		return (NULL);
	if (!(fresh_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		fresh_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		fresh_str[i + j] = s2[j];
		j++;
	}
	fresh_str[i + j] = '\0';
	return (fresh_str);
}
