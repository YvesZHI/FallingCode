#ifndef SYSTOOL_H_
#define SYSTOOL_H_


class SysTool
{
public:
	static int getCols();
	static int getLines();
	static int setPosition(int, int);
	static int print(const char *, char);
	static int refreshScreen();
	static int getchNonBlocking();
	static void init();
	static void setColor(int);
	static void finish();
	
	const static int COLOR_HEAD;
	const static int COLOR_BODY;
	const static int COLOR_TAIL;
	const static int COLOR_EMPTY;
	const static int TIME_LOW;
	const static int TIME_HIGH;
	const static int TIME_DELTA;
};

#endif
