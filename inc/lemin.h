/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:56:44 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/27 15:56:53 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"
# include "../ft_printf/inc/ft_printf.h"

typedef struct				s_path
{
	char					**room_names;
	int						len;
}							t_path;

typedef struct				s_explore_state
{
	int						explore;
	t_node					*current;
	t_node					*placeholder;
	char					*copy;
	int						replace_index;
}							t_explore_state;

typedef struct				s_room
{
	int						x_cord;
	int						y_cord;
	char					*name;
	int						type;
	struct s_room			**links;
	int						num_links;
}							t_room;

typedef struct				s_ant
{
	int						id;
	int						phase;
	t_path					*path;
	int						path_i;
}							t_ant;

typedef struct				s_layout
{
	int						num_ants;
	int						num_rooms;
	int						num_links;
	int						paths_shortest_len;
	int						num_paths;
	int						step;
	int						start;
	int						end;
	t_room					**rooms;
	t_ant					**ants;
	t_path					**paths;
	t_list					*path_current;
}							t_layout;

# define TRUE 1
# define FALSE 0
# define ANT_WAITING 0
# define ANT_TRAVELING 1
# define ANT_FINISHED 2
# define SCAN_NUMBER_ANTS_STEP 0
# define SCAN_ROOM_DETAIL_STEP 1
# define SCAN_ROOM_LINK_STEP 2
# define ERROR_CODE -1
# define START_ROOM 0
# define MID_ROOM 1
# define END_ROOM 2
# define NON_INDEX -1

t_list						*input_get(void);
void						handle_error(void);
t_layout					*input_check_format(t_list *input);
t_layout					*layout_init(void);
void						input_process(t_list *input, t_layout *layout);
int							is_room_detail(char *line);
int							is_link_detail(char *line);
int							is_ant_count(char *line);
int							input_is_comment(char *line);
void						input_process_room_details(t_list *input,
							t_layout *layout);
void						input_process_link_details(t_list *input,
							t_layout *layout);
void						input_check_format_error(t_list *input,
							t_layout *ret);
void						input_scan_for_endpoint(t_layout *layout,
							t_list *input, char *line);
void						input_get_check_format_step(t_layout *layout,
							char *line);
void						input_increment_room_or_link(t_layout *layout,
							char *line);
t_room						**room_append(t_room **room_ptr, t_room *room);
t_room						*room_get_by_name(t_layout *layout, char *name);
t_room						*room_get(char *input, int type);
int							room_is_not_redundant(t_list *path_current,
							char *room_name);
void						ants_initialize(t_layout *layout);
t_room						*room_get_start(t_layout *layout);
int							path_check_validity(t_list *path_current,
							char *name);
void						path_replace(t_layout *layout,
							int path_index, int new_index);
void						path_explore_preliminary_steps(
							t_layout *layout, t_explore_state *state,
							t_room *room, int len);
void						path_explore(t_layout *layout,
							t_room *room, int len);
void						paths_generate(t_layout *layout);
void						paths_sort(t_path **paths, int num_paths);
void						append_path_node(t_path *path,
							char *room);
int							path_append(t_layout *layout, int len);
int							path_compare(t_layout *layout, char	*room,
							int index);
void						ants_crawl(t_layout *layout);
void						ants_print_progress(t_layout *layout,
							int ants_queue);
int							ants_assign_path_and_get_queue(t_layout *layout,
							int ants_queue);
void						ants_progress_through_path(t_ant **ants,
							int ants_queue);
int							ants_finished_crossing(t_ant **ants,
							int num_ants);
int							is_link_detail(char *line);
int							is_room_detail(char *line);
int							is_ant_count(char *line);

#endif
