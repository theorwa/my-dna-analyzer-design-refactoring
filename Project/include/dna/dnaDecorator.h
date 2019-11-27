#include <dna/dna.h>
#include <string>

class DnaDecorator : public Dna
{
public:
	DnaDecorator (std::string name, int id, Dna *decoratedDna) : 
		m_decoratedDna(decoratedDna), m_name(name), m_id(id) { }
	std::string getDnaString() const;
protected:
	Dna *m_decoratedDna;
	std::string m_name;
	int m_id;
};

inline std::string DnaDecorator::getDnaString() const
{
	return m_decoratedDna->getDnaString();
}