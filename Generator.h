#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "String.h"
#include <vector>
#include <random>

using std::string;
using std::vector;


class Generator
{
public:
	Generator();
	explicit Generator(int, float = 0.3f);
	String generateElement();
	String generateString();
	String generateString(const string &);
	String generateEmpty();
	char generateChar();
	
	static const char EMPTY;
private:
	static vector<char> codeLib;

	std::default_random_engine e;
	std::bernoulli_distribution bdStrOrEmpty;
	std::uniform_int_distribution<int> uiCode;
	std::uniform_int_distribution<int> uiLenString;
	std::uniform_int_distribution<int> uiLenEmpty;
};

#endif
