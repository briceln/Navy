/*
** navy.h for navy in /home/brice/Documents/PSU/PSU_2016_navy
**
** Made by Brice Lang-Nguyen
** Login   <brice.lang-nguyen@epitech.eu>
**
** Started on  Mon Jan 30 12:18:17 2017 Brice Lang-Nguyen
** Last update Sat Feb 11 22:02:08 2017 Sadisadou
*/

#ifndef NAVY_H_
#define NAVY_H_


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include "lib.h"
#include "../lib/my/my_printf.h"

typedef struct s_coord {
  int	x;
  int	y;
}	t_coord;


int	my_printf(const char*, ...);
void	my_free(char **);
int	check_map(char*);
void	my_help();
int	player1(int);
int	player2(int, char*);
void	game1(char*);
void	game2(char*, int);
int	openerr(int);
char**	create_map();
void	map(char **);
int	ennemy_pid(int, int);
void	handleSignal(int, siginfo_t*, void*);
int	the_game(int, char**, char**);
void	aff1(char **, char**);
int	char_is_num(char);
int	char_is_char(char);
int	is_low_alpha(char);
void	attacker1(int, char**, char**);
void	attacker2(int, char**, char**);
int	is_valid(char*);
int	enemy_pid(int, int);
t_coord	*receive_coord(char**);
int	send_coord(char*);
char	**load_map(char*);
int	map_pos(char**, t_coord*);
#endif
