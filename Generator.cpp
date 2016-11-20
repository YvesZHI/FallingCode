#include "Generator.h"


vector<char> Generator::codeLib
{
	'#', '$', '&', '(', ')', '*', '+', '-', 
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'<', '>', '=', '?', '@', '!', '[', ']', '{', '}', '^', '_', '~',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
		'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
		'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
		'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
		's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
};

const char Generator::EMPTY{' '};

Generator::Generator()
{
	// nothing to do
}

Generator::Generator(int lines, float r) : e(time(0)), bdStrOrEmpty(r), uiCode(0, codeLib.size() - 1), uiLenString(lines / 9, lines * 3 / 4), uiLenEmpty(lines / 2, lines * 3 / 2)
{
	// nothing to do
}

String Generator::generateElement()
{
	if (bdStrOrEmpty(e))
	{
		return generateString();
	}
	return generateEmpty();
}

String Generator::generateString()
{
	return String(uiLenString(e), false);
}

String Generator::generateString(const string & str)
{
	return String(str.size(), false);
}

String Generator::generateEmpty()
{
	return String(uiLenEmpty(e), true);
}

char Generator::generateChar()
{
	return codeLib[uiCode(e)];
}
