#include "titles.h"
#include <iostream>

bool isExclusion(std::string word)
{
	try
	{
		exclusions.at(word);
	}
	catch (std::out_of_range e)
	{
		return false;
	}

	return true;
}