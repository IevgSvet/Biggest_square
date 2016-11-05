int		main(int argc, char **argv)
{
	char		*str;
	t_list		*list;
	char		c;
	int			size;

	str = 0;
	if (argc > 1)
	{
		bsq(argc, argv);
	}
	else
	{
		size = 0;
		while (read(0, &c, sizeof(char)))
		{
			ft_list_push_back(&list, c);
			size++;
		}
		str = malloc(sizeof(char) * size);
		read_from_cons(list, &str);
		draw_square(str);
	}
	return (0);
}
