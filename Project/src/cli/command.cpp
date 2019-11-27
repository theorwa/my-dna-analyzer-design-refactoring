#include <cli/command.h>
#include <dna/dnaSequence.h>
#include <dna/dnaDecorator.h>

Dna * CommandNew::execute(const std::vector<std::string> &params)
{
	std::cout << "execute new " << params.size() << std::endl;
	DnaSequence *dnaSequence = new DnaSequence("ATATA");
	return new DnaDecorator("seq1", 1, dnaSequence);
}

bool CommandNew::validateParams(const std::vector<std::string> &params)
{
	std::cout << "validate new " << params.size() << std::endl;;
	return true;
}