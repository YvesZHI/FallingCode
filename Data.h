#ifndef DATA_H_
#define DATA_H_

#include "String.h"
#include "Generator.h"
#include "Char.h"
#include <deque>


class Data
{
public:
	Data();
	Data(int, const Char &);
	void init(Generator &);

	const Char * getElement(int pos) const
	{
		return &data[pos];
	}

	char getChar(int pos, const string & s = "string by default")
	{
		return s[pos];
	}

	template<typename ...StringType>
	void refresh(Generator & generator, int color_head, int color_body, int color_tail, int color_empty, StringType &&... st)
	{
		if (needNewString())
		{
			const auto & it = pieces.back();
			if (it.isEmpty())
			{
				pieces.emplace_back(generator.generateString(std::forward<StringType>(st)...));
			}
			else
			{
				pieces.emplace_back(generator.generateEmpty());
			}
		}
		const auto & it = pieces.front();
		if (it.getLen() + data.size() == it.getPos() + 1)
		{
			pieces.pop_front();
		}
		int size = data.size();
		int pos, len, head, num, color, delta;
		constexpr int SIZE = sizeof...(st);
		for (auto it = pieces.begin(); it != pieces.end(); ++it)
		{
			pos = it->getPos();
			len = it->getLen();
			head = (pos + 1 > size) ? (size - 1) : pos;
			num = (len - pos > 1) ? ((pos + 1 > size) ? size : (pos + 1)) : ((size - pos < 1) ? (len - pos + size - 1) : len);
			delta = pos - head;
			if (it->isEmpty())
			{
				data[size - 1 - head] = Char(generator.EMPTY, color_empty);
			}
			else
			{
				for (int i = 0; i < num; ++i)
				{
					if (delta == 0)
					{
						color = color_head;
					}
					else if (len - delta == 1)
					{
						color = color_tail;
					}
					else
					{
						color = color_body;
					}
					if (SIZE == 0)
					{
						data[size - 1 - head--] = Char(generator.generateChar(), color);
					}
					else
					{
						data[size - 1 - head--] = Char(getChar((pos + 1 > size) ? (pos - size + 1 + i) : i, std::forward<StringType>(st)...), color);
					}
					++delta;
				}
			}
			it->setPos(it->getPos() + 1);
		}
	}
private:
	std::deque<String> pieces;
	std::vector<Char> data;

	bool needNewString() const;
};

#endif
