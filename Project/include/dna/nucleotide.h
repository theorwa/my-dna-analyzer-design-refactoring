#ifndef _Nucleotide_
#define _Nucleotide_

#include <iostream>
#include <map>

typedef std::map<char, char> tMapPairs;

class Nucleotide{
public:
	Nucleotide(const Nucleotide&);
	Nucleotide(const char);
	bool operator==(const Nucleotide&);
	bool operator!=(const Nucleotide&);
	Nucleotide& operator=(const Nucleotide&);
	Nucleotide& operator=(const char);
	const char& getChar() const;
	const char& getPair() const;
	friend std::ostream& operator<< (std::ostream& os, const Nucleotide& nuc);
private:
	char m_char;
	static tMapPairs s_mapPaires;
	static tMapPairs init_map();
};

inline const char& Nucleotide::getChar() const { return m_char; }
inline const char& Nucleotide::getPair() const { return s_mapPaires[m_char]; }
inline Nucleotide::Nucleotide(const Nucleotide& other) : m_char(other.m_char) {}
inline Nucleotide::Nucleotide(const char letter) {
	if ( s_mapPaires.find(letter) == s_mapPaires.end() )
		throw "Nucleotide character not legal!";
	m_char = letter;
}

#endif