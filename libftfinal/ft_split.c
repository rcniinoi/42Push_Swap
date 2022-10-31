/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:27:35 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/31 00:36:01 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s)
				s++;
			words++;
		}
	}
	return (words);
}

int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		len;
	int		words;
	int		i;
	int		j;

	words = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c && *s)
			s++;
		len = word_len(s, c);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		j = 0;
		while (*s != c && j < len && *s)
			arr[i][j++] = *s++;
		arr[i][j] = '\0';
		i++;
	}
	arr[words] = NULL;
	return (arr);
}

// static size_t	ft_strcnt(char	const *s, char c)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
// 			j++;
// 		i++;
// 	}
// 	if (s[0] && j == 0)
// 		j += 1;
// 	j += 1;
// 	return (j);
// }

// static void	ft_zero(char *s, char c)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = ft_strlen(s);
// 	while (i < len)
// 	{
// 		if (s[i] == c)
// 			s[i] = '\0';
// 		i++;
// 	}
// }

// static char	**ft_while(char **area, char *st, int cnt)
// {
// 	int	i;

// 	i = 0;
// 	if (cnt == 1)
// 	{
// 		area[0] = NULL;
// 		return (area);
// 	}
// 	while (cnt - 1 > i)
// 	{
// 		while (*st == '\0')
// 			st++;
// 		area[i] = ft_strdup(st);
// 		if (i == cnt - 2)
// 			break ;
// 		st += ft_strlen(area[i]);
// 		i++;
// 	}
// 	area[i + 1] = NULL;
// 	return (area);
// }

// static char	**ft_maltect(char *ns, char c)
// {
// 	char	**area;

// 	if (*ns == '\0')
// 	{
// 		area = (char **)malloc(sizeof(char *));
// 		if (!area)
// 			return (NULL);
// 	}
// 	else
// 	{
// 		area = (char **)malloc(ft_strcnt(ns, c) * (sizeof(char *)));
// 		if (!area)
// 			return (NULL);
// 	}
// 	return (area);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	*ns;
// 	char	**area;
// 	int		i;
// 	char	*st;
// 	int		cnt;

// 	printf("ssss ==== %s\n", s);
// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	ns = ft_strtrim(s, &c);
// 	area = ft_maltect(ns, c);
// 	st = ns;
// 	cnt = ft_strcnt(st, c);
// 	ft_zero(st, c);
// 	area = ft_while(area, st, cnt);
// 	free(ns);
// 	return (area);
// }
