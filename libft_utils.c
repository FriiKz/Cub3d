/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:54:09 by lbusi             #+#    #+#             */
/*   Updated: 2023/11/28 18:32:59 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;
	size_t	c;

	c = 0;
	i = ft_strlen(s1) - 4;
	while ((s2[c] == s1[i]) && (s1[i] != '\0'))
	{
		c++;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[c]);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	unsigned const char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	while (n--)
		*s1++ = *s2++;
	return (dst);
}

char	*ft_strdup(char *s1)
{
	size_t	lenght;
	char	*s2;

	lenght = ft_strlen(s1);
	s2 = malloc(lenght + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, lenght);
	s2[lenght] = '\0';
	return (s2);
}

int	ft_atoi(const char *str)
{
	unsigned int		i;
	unsigned long int	num;
	int					neg;

	num = 0;
	neg = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10 + (str[i] - '0'));
		i++;
	}
	if (num > 9223372036854775807 && neg == -1)
		return (0);
	if (num > 9223372036854775807 && neg == 1)
		return (-1);
	return (num * neg);
}
