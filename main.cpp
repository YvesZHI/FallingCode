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




	SysTool::init();
	Scene scene(SysTool::getCols(), SysTool::getLines());
	if (argc == 1)
	{
		scene.execute();
	}
	else if (argc == 2)
	{
		scene.execute(argv[1]);
	}
	else
	{
		std::cerr<<"Error"<<std::endl;
	}

	SysTool::finish();


	return EXIT_SUCCESS;
}
