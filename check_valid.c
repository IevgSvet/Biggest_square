int		shift_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	return (i);
}

int		str_len(char *str)
{
	int len_first;
	int i;

	i = shift_str(str);
	len_first = i;
	while (str[len_first] != '\n')
		len_first++;
	return (len_first - i);
}

int		ft_is_empty_char(char *str, char empty)
{
	int i;

	i = shift_str(str);
	while (str[i] != '\0')
	{
		if (str[i] == empty)
			return (1);
		i++;
	}
	return (0);
}

int		check_width_map(char *str, char empt_char, char obst_char)
{
	int i;
	int j;
	int len_first;

	len_first = str_len(str);
	i = shift_str(str) + len_first + 1;
	while (str[i] != '\0')
	{
		j = i;
		while (str[j] != '\n' && str[j] != '\0')
			j++;
		if ((j - i) != len_first)
			return (0);
		if (str[j] == '\0')
			break ;
		i = i + len_first + 1;
	}
	i = shift_str(str) + len_first;
	if (ft_is_empty_char(str, empt_char) == 0)
		return (0);
	else if (ft_is_empty_char(str, empt_char) == 1)
		while (str[++i] != '\0')
			if (str[i] != empt_char && str[i] != obst_char && str[i] != '\n')
				return (0);
	return (1);
}

int		check_valid_map(char *str, int given_height, char emp, char obs)
{
	int i;
	int my_height;

	if (check_width_map(str, emp, obs) == 0)
		return (0);
	i = shift_str(str);
	my_height = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			my_height++;
		i++;
	}
	if (given_height != 0 && my_height == given_height)
	{
		return (1);
	}
	return (0);
}
