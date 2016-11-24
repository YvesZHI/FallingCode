#include "SysTool.h"
#include <ncurses.h>


const int SysTool::COLOR_HEAD{255};
const int SysTool::COLOR_TAIL{2};
const int SysTool::COLOR_EMPTY{COLOR_BLACK};
const int SysTool::TIME_LOW{0};
const int SysTool::TIME_HIGH{300};
const int SysTool::TIME_DELTA{30};

int SysTool::colorBody{46};


int SysTool::getCols()
{
	return COLS;
}

int SysTool::getLines()
{
	return LINES;
}

int SysTool::setPosition(int x, int y)
{
	return move(x, y);
}

int SysTool::print(const char * format, char ch)
{
    return printw(format, ch);
}

int SysTool::refreshScreen()
{
	return refresh();
}

int SysTool::getchNonBlocking()
{
	return getch();
}

void SysTool::init()
{
	initscr();
	curs_set(0);
	timeout(0);
	noecho();
	start_color();
	for (int i = 0; i <= 256; ++i)
	{
		init_pair(i, i, COLOR_EMPTY);
	}
}

void SysTool::setColor(int color)
{
	attron(COLOR_PAIR(color));
}

void SysTool::setColorBody(int cb)
{
	colorBody = cb % 257;
}

int SysTool::getColorBody()
{
	return colorBody;
}

void SysTool::finalize()
{
	endwin();
}
