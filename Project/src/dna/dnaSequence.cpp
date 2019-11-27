#include "dna/dnaSequence.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

DnaSequence::DnaSequence(const std::string str){
	setNucleotide(str.c_str());
}

void DnaSequence::setNucleotide(const char* str){
	size_t count = 0;
	while(str[count] != '\0') ++count;
	m_length = count;
	m_seq = (Nucleotide*) malloc(m_length * sizeof(Nucleotide));
	for (size_t i = 0; i < m_length; ++i)
		*(m_seq + i) = Nucleotide(*(str + i));
}

DnaSequence::DnaSequence(const char* str){
	try{
		setNucleotide(str);
	}
	catch (const char* msg){
		std::cout << msg << std::endl;
		m_length = 0;
		m_seq = NULL;
	}
}

DnaSequence::DnaSequence(const DnaSequence& other){
	*this = other;
}

// =========================================================

std::ostream& operator<< (std::ostream& os, const DnaSequence& dna){
	os << "length: " << dna.m_length << " - seq: ";
	for (size_t i = 0; i < dna.m_length; i++)
        os << dna.m_seq[i];
    return os;
}

std::string DnaSequence::getDnaString() const{
	std::string result = "";
	for (size_t i = 0; i < m_length; i++)
        result += m_seq[i].getChar();
    return result;
}

// =========================================================

bool DnaSequence::operator==(const DnaSequence& other){
	if (other.m_length != m_length) return false;
	for (size_t i = 0; i < m_length; ++i)
		if (*(m_seq + i) != *(other.m_seq + i))
			return false;
	return true;
}

bool DnaSequence::operator!=(const DnaSequence& other){
	if (*this == other) return false;
	return true;
}

DnaSequence& DnaSequence::operator=(const DnaSequence& other){
	m_length = other.m_length;
	m_seq = (Nucleotide*) malloc(m_length * sizeof(Nucleotide));
	for (size_t i = 0; i < other.m_length; ++i)
		*(m_seq + i) = Nucleotide(*(other.m_seq + i));
	return *this;
}

DnaSequence& DnaSequence::operator=(const char* str){
	try{
		setNucleotide(str);
	}
	catch (const char* msg){
		std::cout << msg << std::endl;
		m_length = 0;
		m_seq = NULL;
	}
	return *this;
}

DnaSequence& DnaSequence::operator=(const std::string& str){
	try{
		setNucleotide(str.c_str());
	}
	catch (const char* msg){
		std::cout << msg << std::endl;
		m_length = 0;
		m_seq = NULL;
	}
	return *this;
}

Nucleotide& DnaSequence::operator[] (unsigned int index){
	return m_seq[index];
}

const Nucleotide& DnaSequence::operator[] (unsigned int index) const{
	return m_seq[index];
}

// =========================================================

const Dna* DnaSequence::slice(unsigned int start, unsigned int end) const{
	char *seq = (char*) malloc (end - start + 1);
	*(seq + end - start) = '\0';
	for (unsigned int i = start; i < end; ++i)
	{
		*(seq + i - start) = (*(this))[i].getChar();
	}
	return new DnaSequence(seq);
}

const char* DnaSequence::getPaired() const {

	char *seq = (char*) malloc (m_length + 1);
	*(seq + m_length) = '\0';
	for (unsigned int i = 0; i < m_length; ++i)
	{
		*(seq + m_length - i - 1) = (*(this))[i].getPair();
	}
	return seq;
}

int DnaSequence::find(const DnaSequence& other) const{
	if (m_length < other.m_length)
		return -1;
	bool flag = true;
	for (size_t i = 0; i < m_length - other.m_length + 1; ++i)
	{
		for (size_t j = i; j < other.m_length + i; ++j)
		{
			// std::cout << m_seq[j] << other.m_seq[j-i] << std::endl;
			if (m_seq[j] != other.m_seq[j-i]){
				// std::cout << j << std::endl;
				flag = false;
				break;
			}
		}
		if (flag == true)
			return int(i);
		flag = true;
	}
	return -1;
}

// size_t DnaSequence::count(const DnaSequence& other) const{
// 	DnaSequence temp(*this);
// 	int index, count = 0;
// 	while (temp.m_length > 0){
// 		// std::cout << temp << std::endl;
// 		index = temp.find(other);
// 		// std::cout << index << std::endl;
// 		if (index != -1)
// 			++count;
// 		else
// 			return count;
// 		temp = *(dynamic_cast<DnaSequence*>(temp.slice(index+1, int(m_length))));
// 	}
// 	return count;
// }