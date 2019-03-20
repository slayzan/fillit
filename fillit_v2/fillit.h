#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct		s_tra
{
	char		**tet,
	int		x;
	int		y;
	char		letter;
	struct s_tra	*next;
	struct t_tra	*prev;
}			t_tra;

int			main(int argc, char **argv);

#endif
