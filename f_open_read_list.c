int		f_open_file(char *f_name, char **str)
{
	int fop;
	int i;

	fop = open(f_name, O_RDONLY);
	if (fop != (-1))
		f_read_file(fop, str);
	else
	{
		i = 0;
		while (f_name[i] != '\0')
		{
			write(1, &f_name[i], 1);
			i++;
		}
		write(2, ": No such file or directory\n", 28);
	}
	return (fop);
}

void	f_read_file(int fop, char **str)
{
	int		frd;
	t_list	*list;
	char	c;
	int		i;
	int		size;

	size = 0;
	i = 0;
	frd = 0;
	list = 0;
	while (read(fop, &c, sizeof(char)))
	{
		ft_list_push_back(&list, c);
		size++;
	}
	*str = malloc(sizeof(char) * size);
	while (list)
	{
		(*str)[i] = list->data;
		list = list->next;
		i++;
	}
	ft_list_clear(&list);
}

t_list	*ft_create_elem(char data)
{
	t_list *element;

	element = (t_list*)malloc(sizeof(t_list));
	if (element)
	{
		element->data = data;
		element->next = NULL;
	}
	return (element);
}

void	ft_list_push_back(t_list **begin_list, char data)
{
	t_list *new_elem;
	t_list *tmp;

	new_elem = ft_create_elem(data);
	if (new_elem)
	{
		if ((*begin_list) == NULL)
			*begin_list = new_elem;
		else
		{
			tmp = *begin_list;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = new_elem;
		}
	}
}

void	ft_list_clear(t_list **begin_list)
{
	t_list *tmp;

	while (*begin_list)
	{
		tmp = *begin_list;
		*begin_list = tmp->next;
		free(tmp);
	}
}
