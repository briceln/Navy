#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "my.h"

int	g_pid;


int	char_is_char(char c)
{
  if (c > 64 && c < 91)
    return (1);
  return (0);
}

int	char_is_num(char c)
{
  if (c > 47 && c < 58)
    return (1);
  return (0);
}

void	handleSignal(int sig, siginfo_t *info, void *context)
{
  if (sig == SIGUSR1)
    g_pid = info->si_pid;
  if (context != NULL)
    return ;
}

int	game(int argc)
{
  int	state;

  state = 0;
  while (!state)
    {
      if (argc != 0)
	state = 1;
    }
  return (0);
}


int			connection(int argc, char **argv)
{
  struct sigaction	action;

  printf("my_pid: %i\n", getpid());
  action.sa_sigaction = &handleSignal;
  action.sa_flags = SA_SIGINFO;
  if (argc == 2)
    {
      printf("waiting for enemy connexion...\n");
      sigaction(SIGUSR1, &action, NULL);
      pause();
      kill(g_pid, SIGUSR1);
      printf("enemy connected\n\n");
    }
  else if (argc == 3)
    {
      kill(atoi(argv[1]), SIGUSR1);
      sigaction(SIGUSR1, &action, NULL);
      pause();
      printf("Connected\n\n");
    }
  game(argc);
  return (0);
}

int	coord_to_int(char *coord)
{
  int	res;

  res = 0;
  if (my_strlen(coord) != 2)
    return (-1);
  //verif(alpha et num)
  if (char_is_num(coord[0]) && char_is_char(coord[1]))
    {
      res = coord[0] - 48;
      res += coord[1] - 65;
    }
  else if (char_is_char(coord[0]) && char_is_num(coord[1]))
    {
      res = coord[0] - 65;
      res += (coord[1] - 48 - 1) * 8;
    }
  return (res);
}



char	*load_map(char *file)
{
  int	fd;
  char	*coord;
  char	*map;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((coord = malloc(sizeof(char) * 4 * 8 + 1)) == NULL)
    return (NULL);
  read(fd, coord, 32);
  close(fd);
  if ((fd = open("map/EmptyMap.txt", O_RDONLY)) == -1)
    return (NULL);
  if ((map = malloc(sizeof(char) * 18 * 10)) == NULL)
    return (NULL);
  read(fd, map, 18 * 10);
  close(fd);
  //  coord_to_map();
  free(coord);
  return (map);
}


int	main(int argc, char **argv)
{
  char	*map;
  
  printf("%i\n", coord_to_int("B2"));
  if (argc != 2 && argc != 3)
    return (84);
  if ((map = load_map(argv[argc - 1])) == NULL)
    return (84);
  printf("%s\n", map);
  connection(argc, argv);
  free(map);
  return (EXIT_SUCCESS);
}
