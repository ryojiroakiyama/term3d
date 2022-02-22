#include "term3d.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>

int	kbhit(void)
{
	struct termios	oldt;
	struct termios	newt;
	int				ch;
	int				oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return (1);
	}
	return (0);
}

void	key_event(t_draw *draw)
{
	int	c;

	if (kbhit())
	{
		c = getchar();
		if (c == 'q')
			exit(EXIT_SUCCESS);
		else if (c == 'w')
			draw->scale += 0.2;
		else if (c == 's')
			draw->scale -= 0.2;
	}
}