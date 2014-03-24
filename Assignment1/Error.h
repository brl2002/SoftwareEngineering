#ifndef ERROR_H
#define ERROR_H

#include "SDL.h"
#include <string>

class Error
{
public:
	Error();
	~Error();

	static void log(std::ostream &os, const std::string &msg)
	{
		const char* error = SDL_GetError();
		if (error)
		{
			os << msg << " error: " << SDL_GetError() << std::endl;
		}
		else
		{
			os << msg << " error" << std::endl;
		}	
	}
private:
	
};

#endif