/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:08:14 by drtaili           #+#    #+#             */
/*   Updated: 2023/01/02 06:19:42 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (!dstsize)
		return (slen);
	while (i < slen && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)malloc(len * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s1, len * sizeof(char) + 1);
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	maxlen;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	maxlen = slen - start;
	if (len < slen - start)
		maxlen = len;
	sub = (char *)malloc(maxlen + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, maxlen + 1);
	return (sub);
}

static int	count_words(char const *s, char c)
{
	size_t	i;
	int		count;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	ft_free(char **ret, int k)
{
	int	j;

	j = 0;
	while (j < k)
	{
		free(ret[j]);
		j++;
	}
	free(ret);
}

static int	skip_c(char const *s, char c, int i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static int	ft_lenword(char const *s, char c, int i)
{
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**ret;
	int		word_count;

	word_count = count_words(s, c);
	ret = (char **)calloc(word_count + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	k = -1;
	i = 0;
	while (++k < word_count)
	{
		i = skip_c(s, c, i);
		j = ft_lenword(s, c, i);
		ret[k] = ft_substr(s, i, j - i);
		if (!ret[k])
		{
			ft_free(ret, k);
			return (NULL);
		}
		i = j;
	}
	return (ret);
}

int	ft_atoi(const char *str)
{
	int	r;
	int	i;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * (-1);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * s);
}

t_node *parsing(int argc, char **argv)
{
	t_node *head;
	char **splits;
	int	i;
	int j;

	head = NULL;
	i = 1;
	while (i < argc) 
	{
		splits = ft_split(argv[i], ' ');
		j = 0;
		while (splits[j])
		{
			push(&head, atoi(splits[j]));
			free(splits[j]);
			j++;
		}
		free(splits);
		i++;
	}
	return (head);
}
int main(int argc, char **argv)
{
	t_node *head = parsing(argc, argv);
	displaystack(head);
}
