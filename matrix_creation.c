void	cr_field_matrix(char *str, int *wh, char empty, char fill_s)
{
	char	**matr;
	int		i;
	int		j;

	i = 0;
	matr = malloc(sizeof(char *) * (wh[1] + 1));
	while (*str != '\n')
		str++;
	str++;
	while (i < wh[1])
	{
		matr[i] = malloc(sizeof(char) * (wh[0] + 1));
		j = 0;
		while (j < wh[0] && *str != '\n')
		{
			matr[i][j] = *str;
			j++;
			str++;
		}
		matr[i][j] = '\0';
		i++;
		str++;
	}
	matr[i] = 0;
	cr_int_matrix(matr, wh, empty, fill_s);
}

int		min(int i, int j, int k)
{
	if (i <= j && i <= k)
	{
		return (i);
	}
	else if (j <= i && j <= k)
	{
		return (j);
	}
	else
		return (k);
}

void	cr_int_matrix(char **field_matr, int *wh, char empty, char fill_s)
{
	int	**int_matr;
	int i;
	int j;

	int_matr = malloc(sizeof(int *) * (wh[1] + 1));
	i = 0;
	while (i < wh[1])
	{
		int_matr[i] = malloc(sizeof(int) * wh[0]);
		j = 0;
		while (j < wh[0])
		{
			if (field_matr[i][j] == empty)
				int_matr[i][j] = 1;
			else
				int_matr[i][j] = 0;
			j++;
		}
		i++;
	}
	fill_int_matrix(int_matr, wh, field_matr, fill_s);
}

void	fill_int_matrix(int **m, int *wh, char **field_matr, char fill_s)
{
	int i;
	int j;

	i = wh[1] - 2;
	while (i >= 0)
	{
		j = wh[0] - 2;
		while (j >= 0)
		{
			if (m[i][j] == 1)
			{
				m[i][j] = 1 + min(m[i + 1][j + 1], m[i][j + 1], m[i + 1][j]);
			}
			j--;
		}
		i--;
	}
	find_coords(m, wh, field_matr, fill_s);
}

void	find_coords(int **m, int *wh, char **field_matr, char fill_s)
{
	int i;
	int j;
	int size;
	int max_coords[2];

	i = 0;
	size = m[0][0];
	max_coords[0] = 0;
	max_coords[1] = 0;
	while (i < wh[1])
	{
		j = 0;
		while (j < wh[0])
		{
			if (m[i][j] > size)
			{
				size = m[i][j];
				max_coords[0] = i;
				max_coords[1] = j;
			}
			j++;
		}
		i++;
	}
	fill_in_square(max_coords, size, field_matr, fill_s);
}
