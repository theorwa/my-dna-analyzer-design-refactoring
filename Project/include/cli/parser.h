#include <string>
#include <vector>

class Parser
{
public:
	static std::string getMethod(std::string line);
	static std::vector<std::string> getParams(std::string line);
};