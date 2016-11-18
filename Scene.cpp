#include "Scene.h"


Scene::Scene(int cols, int lines, int time) : COLS{cols}, generator{lines}, millisec(time), scene(lines, nullptr), column(cols, Column(lines, Char(Generator::EMPTY, SysTool::COLOR_EMPTY)))
{
	std::for_each(scene.begin(), scene.end(), [=](Char **& p){ p = new Char *[cols]; });
	for (int i = 0; i < column.size(); ++i)
	{
		column[i].init(generator);
		for (int j = 0; j < scene.size(); ++j)
		{
			scene[j][i] = const_cast<Char *>(column[i].getElement(lines - j - 1));
		}
	}
}

Scene::~Scene()
{
	std::for_each(scene.begin(), scene.end(), [](Char **& p){ delete[] p; });
}

void Scene::showScene()
{
	for (int i = 0; i < scene.size(); ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			SysTool::setColor(scene[i][j]->getColor());
			SysTool::setPosition(i, j);
			SysTool::print("%c", scene[i][j]->getChar());
		}
		SysTool::refreshScreen();
	}
}
