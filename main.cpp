// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CDBParser.h

int main(int argc, char* argv[])
{
	const std::string& cdbFile = argv[1];

	CDBParser cdb;
	cdb.printSourceFiles(cdbFile);

	return 0;
}
