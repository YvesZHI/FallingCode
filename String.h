#ifndef STRING_H_
#define STRING_H_


class String
{
public:
	String();
	String(int, bool, int = 0);

	int getLen() const
	{
		return len;
	}

	void setLen(int l)
	{
		len = l;
	}

	int getPos() const
	{
		return pos;
	}

	void setPos(int p)
	{
		pos = p;
	}

	bool isEmpty() const
	{
		return empty;
	}

	void setEmpty(bool e)
	{
		empty = e;
	}
private:
	int len;
	bool empty;
	int pos;
};

#endif
