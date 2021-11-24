#include <iostream>
#include <fstream>

#include "CDBParser.h"
#include "jsoncons/json.hpp"

using namespace std;

void CDBParser::printSourceFiles(const string& cdbFile){
	
	ifstream infile;
	infile.open(cdbFile);

	if (infile.is_open())
	{
		try 
		{
			cout << "Reading compilation database json file...\n\n";
			jsoncons::json obj = jsoncons::json::parse(infile);
			cout << "Json file parsed\n";
			const auto& cdbEntities = obj.array_value();
			cout << "Json array received\n";

			std::vector<std::string> srcFilePaths;
			srcFilePaths.reserve(cdbEntities.size());

			cout << "Distinct source files in CDB:" << cdbEntities.size() << "\n\n";

			for (const auto& cdbEntity : cdbEntities) {
				cout << "Inserting file: " << cdbEntity["file"] << "\n";
				srcFilePaths.emplace_back(cdbEntity["file"].as_string());
			}

			cout << "\nFile list: \n";
			for (const auto& srcFile : srcFilePaths)
				cout << srcFile << "\n";
		}
		catch (const std::exception & e) {
			cout << "Error reading compilation database json file!\n";
			cout << e.what();
		}
		infile.close();
	}
	else {
		cout << "Cannot open compilation database json file\n";
	}
}
