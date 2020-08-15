/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjeraldi <pjeraldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:48:27 by pjeraldi          #+#    #+#             */
/*   Updated: 2019/08/04 23:17:27 by pjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 16

# include "Libft/libft.h"
# include <fcntl.h>

typedef struct			s_tetr
{
	char				**tetr;
	char				name;
	int					height;
	int					width;
	struct s_tetr		*start;
	struct s_tetr		*next;
}						t_tetr;

typedef struct			s_stock
{
	char				**four_line;
	char				alpha;
	int					new_line;
}						t_stock;

typedef struct			s_map
{
	char				**map;
	int					size;
}						t_map;

void					ft_print_error();
void					ft_free_map(t_map *map, int size_of_map);
t_map					*ft_create_map();
int						check_for_empty_file(char *name_of_file);
t_map					ft_set_dotmap(t_map *map_list);
t_map					ft_print_map(t_map *map_list);
void					ft_readformain(int argc, char **argv);
void					ft_free_str_array(char **array, int count);
void					ft_obrez_tetra(char **tetra);
char					**get_four_line(int fd);
int						valid_tetra(char **fl);
t_tetr					*ft_for_get_tetrs(t_stock *stock);
t_tetr					*ft_free_tetramins(t_tetr **list, char **four_line);
t_tetr					*get_tetrs(int fd);
void					ft_dom_truba_shatal(t_map *map_list, t_tetr *list);

#endif
