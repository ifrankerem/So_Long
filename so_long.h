#ifndef SO_LONG
# define SO_LONG

typedef struct s_map
{
	char	**map;
	int		column_number;
	int		line_number;
	int		move_count;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		e;
	int		p;
	int		c;
	void	*player;
	void	*exit;
	void	*coin;
	void	*background;
	void	*wall;
	void	*mlx_ptr;
	void	*win;
}			t_map;

# include "./get_next_line/get_next_line.h"
# include "./printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char		*get_next_line(int fd);
int			ft_printf(const char *format, ...);
t_map		*control(t_map *map);
void		map_free(t_map *map);
void		ft_error(t_map *map, int error_code);
t_map		*map_elements(t_map *map);
void		is_valid(t_map *map);
void		wallcontrol(t_map *map, int x, int y);
void		is_rectangle(t_map *map);
t_map		*info(t_map *map);
t_map		*read_map(t_map *map, char *filename);
int			file_name_control(char *av);
t_map		*open_window(t_map *map);
t_map		*cast_image(t_map *map);
void		movement(int keysym, t_map *map);
void		close_window(t_map *map);
int			movement_and_exit(int keysym, t_map *map);
void		player_move(t_map *map, int my, int mx);
void		fill_player(char **cpy_map, int x, int y);
void		flood_fill_player(char **cpy_map, t_map *map);
t_map		*player_info(t_map *map);
t_map		*exit_info(t_map *map);
char		**make_copy(t_map *map);
void		copy_mapcontrol(t_map *map, char **cpy_map);
void		free_cpymap(char **cpy_map);
t_map		*mapcontrol2(t_map *map);
void		fill_exit(char **cpy_map, int x, int y);

#endif