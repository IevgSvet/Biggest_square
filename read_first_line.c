int		number_lines(char *str)
{
	int numb;

	numb = ft_atoi(str);
	return (numb);
}

int		ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	empty_char(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
	{
		if (!ft_is_digit(str[i]))
			break ;
		i++;
	}
	return (str[i]);
}

char	obstacle_char(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
	{
		if (!ft_is_digit(str[i]))
			break ;
		i++;
	}
	return (str[i + 1]);
}

char	full_char(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
	{
		if (!ft_is_digit(str[i]))
			break ;
		i++;
	}
	return (str[i + 2]);
}
