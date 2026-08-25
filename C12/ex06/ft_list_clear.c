#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		if (free_fct && begin_list->data)
			(*free_fct)(begin_list->data);
		free(begin_list);
		begin_list = tmp;
	}
}


#include <stdio.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int	i;
	int	len;
	char	*dest;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_string_data(void *data)
{
	printf("Freeing data: %s\n", (char *)data);
	free(data);
}

int	main(void)
{
	t_list	*node1 = (t_list *)malloc(sizeof(t_list));
	t_list	*node2 = (t_list *)malloc(sizeof(t_list));

	node1->data = ft_strdup("First Node");
	node2->data = ft_strdup("Second Node");
	node1->next = node2;
	node2->next = NULL;
	printf("Clearing list\n");
	ft_list_clear(node1, &free_string_data);
	printf("List cleared\n");
	return (0);
}
