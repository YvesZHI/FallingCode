#include "String.h"


String::String() : len{0}, empty{true}, pos{-1}
{
	// nothing to do
}

String::String(int l, bool e, int p) : len{l}, empty{e}, pos{p}
{
	// nothing to do
}
