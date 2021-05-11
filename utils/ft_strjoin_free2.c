#include "../minishell.h"

size_t		ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	i = 0;
	while (dstsize != 0 && i < dstsize - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	int				src_size;
	unsigned int	dest_size;
	unsigned int	i;

	i = 0;
	src_size = 0;
	dest_size = 0;
	while (src[src_size])
		src_size++;
	while (dest_size < size && dest[dest_size])
		dest_size++;
	if (size <= dest_size)
		return (size + src_size);
	while (size != 0 && i < size - dest_size - 1 && src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (src_size + dest_size);
}

char		*ft_strjoin_free2(char *s1, char *s2)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strlcpy(dest, s1, len);
	ft_strlcat(dest, s2, len);
	free(s1);
	free(s2);
	return (dest);
}