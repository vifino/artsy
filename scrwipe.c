// ┓━┓┏━┓┳━┓┓ ┳o┳━┓┳━┓
// ┗━┓┃  ┃┳┛┃┃┃┃┃━┛┣━
// ━━┛┗━┛┇┗┛┗┻┇┇┇  ┻━┛
// scrwipe: It's dirty.
// Usage: scrwipe
// Have fun. - vifino
// ISC (C) vifino 2018

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define WIPE "///"
#define WIPEL 3
#define SECS 1

// Escapes.
#define ESC "\x1B["
#define MOVETO "%i;%iH"

// Other
#define SEC 1000000
#define WPL (WIPEL + 1)

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main(int argc, char* argv[]) {
	// get window size.
	struct winsize winsz;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &winsz);
	int w = winsz.ws_col;
	int h = winsz.ws_row;
	int steps = w + h + WPL;

	useconds_t sleeptime = (SECS * SEC) / (steps);
	int p, x, y;
	for (p = 0; p < steps; p++) {
		for (y = 0; y <= h; y++) {
			x = (p - y);
			if (x >= 0 && x <= w) {
				char wb[WPL + 1] = WIPE;
				wb[MIN(WPL, w - x)] = 0;
				printf(ESC MOVETO " %s", y, x, wb);
				fflush(stdout);
			}
		}
		usleep(sleeptime);
	}

	printf(ESC "2J" ESC "H");
	fflush(stdout);

	return 0;
}
