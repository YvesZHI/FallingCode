#include "Data.h"


Data::Data() : data{}, pieces{}
{
	// nothing to do
}

Data::Data(int size, const Char & c) : data(size, c), pieces{String(size, true, size - 1)}
{
	// nothing to do
}

void Data::init(Generator & g)
{
	pieces.emplace_back(g.generateEmpty());
}

bool Data::needNewString() const
{
	const auto & last = pieces.back();
	if (last.getLen() == last.getPos())
	{
		return true;
	}
	return false;
}
