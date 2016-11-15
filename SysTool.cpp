#include "SysTool.h"
#include <ncurses.h>


const int SysTool::COLOR_HEAD{255};
const int SysTool::COLOR_BODY{46};
const int SysTool::COLOR_TAIL{2};
const int SysTool::COLOR_EMPTY{COLOR_BLACK};
const int SysTool::TIME_LOW{0};
const int SysTool::TIME_HIGH{300};
const int SysTool::TIME_DELTA{30};


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
	init_pair(COLOR_HEAD, COLOR_HEAD, COLOR_EMPTY);
	init_pair(COLOR_BODY, COLOR_BODY, COLOR_EMPTY);
	init_pair(COLOR_TAIL, COLOR_TAIL, COLOR_EMPTY);
}

void SysTool::setColor(int color)
{
	attron(COLOR_PAIR(color));
}

void SysTool::finish()
{
	endwin();
}
