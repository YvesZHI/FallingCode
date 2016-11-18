#include "Column.h"


Column::Column() : column{}, pieces{}
{
	// nothing to do
}

Column::Column(int size, Char c) : column(size, std::move(c)), pieces{String(size, true, size - 1)}
{
	// nothing to do
}

void Column::init(Generator & g)
{
	pieces.emplace_back(g.generateEmpty());
}

bool Column::needNewString() const
{
	const auto & last = pieces.back();
	if (last.getLen() == last.getPos())
	{
		return true;
	}
	return false;
}
