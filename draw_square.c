void	draw_square(char *str)
{
	int		wh[2];
	char	empty;
	char	obst;
	char	fill_symb;

	wh[1] = number_lines(str);
	if (wh[1] != 0)
	{
		wh[0] = str_len(str);
		if (wh[0] != 0)
		{
			empty = empty_char(str);
			obst = obstacle_char(str);
			fill_symb = full_char(str);
			if (check_valid_map(str, wh[1], empty, obst) == 1)
				cr_field_matrix(str, wh, empty, fill_symb);
			else
				write(2, "map error\n", 10);
		}
		else
			write(2, "map error\n", 10);
	}
	else
		write(2, "map error\n", 10);
}

void	fill_in_square(int *max_coords, int size, char **field_matr,
		char fill_s)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			field_matr[i + max_coords[0]][j + max_coords[1]] = fill_s;
			j++;
		}
	}
	i = 0;
	while (field_matr[i])
	{
		j = 0;
		while (field_matr[i][j])
		{
			write(1, &field_matr[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	bsq(int argc, char **argv)
{
	int		j;
	char	*str;
	char	*f_name;

	j = 1;
	while (j < argc)
	{
		f_name = argv[j];
		if (f_open_file(f_name, &str) != (-1))
		{
			draw_square(str);
			str = 0;
		}
		j++;
	}
}

void	read_from_cons(t_list *list, char **str)
{
	int		i;

	i = 0;
	while (list)
	{
		(*str)[i] = list->data;
		list = list->next;
		i++;
	}
	(*str)[i] = '\0';
	ft_list_clear(&list);
}
