
#include "fillit.h"

void	ft_printtab(char ***tab)
{
	int num;
	int x;
	int y;

	num = 0;
	x = 0;
	y = 0;
	while (tab[num][x] != 0)
	{
	/*	while (tab[num][x][y] != '\0')
		{
			printf("%s", tab[num][x][y++]);
		}
	*/	x++;
	}
}
