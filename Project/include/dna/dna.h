#pragma once
#include <string>

class Dna
{
public:
	virtual std::string getDnaString() const = 0;
	// virtual const *Dna slice(unsigned int start, unsigned int end) const = 0;
};