#pragma once
#include <dna/dna.h>
#include <string>
#include <vector>


class ICommand
{
public:
	virtual std::string getName() = 0;
	virtual Dna * execute(const std::vector<std::string> &params) = 0;
	virtual bool validateParams(const std::vector<std::string> &params) = 0;
};



class CommandNew : public ICommand
{
public:
	std::string getName();
	Dna * execute(const std::vector<std::string> &params);
	bool validateParams(const std::vector<std::string> &params);
};

inline std::string CommandNew::getName() { return "new command"; }