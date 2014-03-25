#include "Game.h"
#include <iostream>

int main(int argc, char **argv)
{
	GameInst::Instance()->Init("SchoolRPG", 800, 600, false);

	return 0;
} 