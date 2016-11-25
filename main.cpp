#include "Scene.h"
#include <iostream>
#include <sstream>


int main(int argc, char ** argv)
{
	std::cout<<"------------------------------------------"<<std::endl;
	std::cout<<"|                                        |"<<std::endl;
	std::cout<<"|           MATRIX Version 1.0           |"<<std::endl;
	std::cout<<"|                                        |"<<std::endl;
	std::cout<<"|                                        |"<<std::endl;
	std::cout<<"|                                        |"<<std::endl;
	std::cout<<"|           type p to pause/unpause      |"<<std::endl;
	std::cout<<"|           type q to quit               |"<<std::endl;
	std::cout<<"|           type j to increase speed     |"<<std::endl;
	std::cout<<"|           type k to decrease speed     |"<<std::endl;
	std::cout<<"|                                        |"<<std::endl;
	std::cout<<"|           Enter to start...            |"<<std::endl;
	std::cout<<"|                                        |"<<std::endl;
	std::cout<<"|                                        |"<<std::endl;
	std::cout<<"------------------------------------------"<<std::endl;

	std::cin.get();

	if (argc == 1)
	{
		SysTool::init();
		Scene scene(SysTool::getCols(), SysTool::getLines());
		scene.execute();
	}
	else if (argc == 2)
	{
		std::string arg(argv[1]);
		bool isColor = true;
		for (auto it : arg)
		{
			if (!std::isdigit(it))
			{
				isColor = false;
				break;
			}
		}
		if (isColor)
		{
			std::istringstream iss(argv[1]);
			int color;
			iss >> color;
			SysTool::setColorBody(color);
			SysTool::init();
			Scene scene(SysTool::getCols(), SysTool::getLines());
			scene.execute();
		}
		else
		{
			SysTool::init();
			Scene scene(SysTool::getCols(), SysTool::getLines());
			scene.execute(argv[1]);
		}
	}
	else if (argc == 3)
	{
		std::istringstream iss(argv[2]);
		int color;
		iss >> color;
		SysTool::setColorBody(color);
		SysTool::init();
		Scene scene(SysTool::getCols(), SysTool::getLines());
		scene.execute(argv[1]);
	}
	else
	{
		std::cerr<<"Error"<<std::endl;
	}
	SysTool::finalize();


	return EXIT_SUCCESS;
}
