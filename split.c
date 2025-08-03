#include <stdlib.h>
#include <stddef.h>
#include "pipex.h"

size_t	countwords(char const *s, char c);
void	find_and_allocate_words(char const *s, char c, char **w, size_t w_i);
char	*allocate_word(char const *s, size_t begin, size_t end);
void	free_words(char **words, size_t count);

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_byte;
	const unsigned char	*src_byte;

	if (!dest || !src)
		return (dest);
	dest_byte = dest;
	src_byte = src;
	while (n > 0)
	{
		*dest_byte++ = *src_byte++;
		n--;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	const char	*begin;

	begin = s;
	while (*s)
		s++;
	return (s - begin);
}

char	**ft_split(char const *s, char c)
{
	char	**strings_array;
	size_t	nwords;
	size_t	i;

	i = 0;
	nwords = countwords(s, c);
	strings_array = malloc(sizeof(char *) * (nwords + 1));
	if (!strings_array)
		return (NULL);
	find_and_allocate_words(s, c, strings_array, 0);
	while (i < nwords)
	{
		if (!strings_array[i])
		{
			free_words(strings_array, nwords);
			return (NULL);
		}
		i++;
	}
	strings_array[nwords] = NULL;
	return (strings_array);
}

size_t	countwords(char const *s, char c)
{
	size_t	nwords;
	int		inword;

	nwords = 0;
	inword = 0;
	while (*s)
	{
		if (!inword && *s != c)
		{
			nwords++;
			inword = 1;
		}
		else if (inword && *s == c)
			inword = 0;
		s++;
	}
	return (nwords);
}

void	find_and_allocate_words(char const *s, char c, char **w, size_t w_i)
{
	size_t	wordbegin;
	size_t	i;
	size_t	slen;
	int		inword;

	wordbegin = 0;
	inword = 0;
	i = 0;
	slen = ft_strlen(s);
	while (i <= slen)
	{
		if (!inword && s[i] != c)
		{
			wordbegin = i;
			inword = 1;
		}
		else if (inword && (s[i] == c || s[i] == '\0'))
		{
			inword = 0;
			w[w_i] = allocate_word(s, wordbegin, i);
			w_i++;
		}
		i++;
	}
}

char	*allocate_word(char const *s, size_t begin, size_t end)
{
	char	*word;

	word = malloc(end - begin + 1);
	if (!word)
	{
		return (NULL);
	}
	ft_memcpy(word, s + begin, end - begin);
	word[end - begin] = '\0';
	return (word);
}

void	free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}