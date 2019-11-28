#include <cli/parser.h>
#include <sstream>

std::string Parser::getMethod(std::string line)
{
	std::stringstream iss(line);
	std::string token;
	iss >> token;
	return token;
}

std::vector<std::string> Parser::getParams(std::string line)
{
	bool afterMethod = false;
	std::stringstream iss(line);
	std::string token;
	std::vector<std::string> tokens;
	while (iss >> token)
		if ( afterMethod )
			tokens.push_back(token);
		else
			afterMethod = true;
	return tokens;
}