class Char
{
public:
	Char(char = '\0', int = -1);
	
	void setColor(int col)
	{
		color = col;
	}

	int getColor() const
	{
		return color;
	}

	char getChar() const
	{
		return ch;
	}
private:
	char ch;
	int color;
};
