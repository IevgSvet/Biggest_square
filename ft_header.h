#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			data;
	struct s_list	*next;
}					t_list;

void				f_read_file(int fop, char **str);
int					f_open_file(char *f_name, char **str);
int					ft_begin(char c);
int					ft_atoi(char *c);
int					number_lines(char *str);
int					ft_is_digit(char c);
char				empty_char(char *str);
char				obstacle_char(char *str);
char				full_char(char *str);
int					str_len(char *str);
int					ft_is_empty_char(char *str, char empty);
int					check_width_map(char *str,
					char empt_char, char obst_char);
int					check_valid_map(char *str, int given_hight,
					char empt_char, char obst_char);
void				cr_field_matrix(char *str, int *wh,
					char empty, char fill_s);
void				cr_int_matrix(char **field_matr,
					int *wh, char empty, char fill_s);
void				fill_int_matrix(int **m, int *wh,
					char **field_matr, char fill_s);
void				find_coords(int **m, int *wh,
					char **field_matr, char fill_s);
void				fill_in_square(int *max_coords, int size,
					char **field_matr, char fill_s);
void				draw_square(char *str);
int					min(int i, int j, int k);
void				ft_list_push_back(t_list **begin, char data);
t_list				*ft_create_elem(char data);
void				ft_list_clear(t_list **begin_list);
void				bsq(int a, char **v);
void				read_from_cons(t_list *list, char **str);

#endif
