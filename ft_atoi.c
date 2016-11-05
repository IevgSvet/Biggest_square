int		ft_begin(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int		ft_atoi(char *c)
{
	int i;
	int flag;
	int numb;

	i = 0;
	numb = 0;
	flag = 1;
	while (ft_begin(c[i]))
		i = i + 1;
	if (c[i] == '-')
		flag = -1;
	if (c[i] == '-' || c[i] == '+')
		i = i + 1;
	while (i >= 0)
	{
		if (c[i] >= '0' && c[i] <= '9')
			numb = 10 * numb + (c[i] - '0');
		else
			break ;
		i = i + 1;
	}
	numb = numb * flag;
	return (numb);
}
