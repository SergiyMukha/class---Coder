//coder.cpp
#include<string.h>
#include "coder.h"


Coder::Coder() :m_buf(nullptr), m_size(0)
{
}
Coder::Coder(const Coder& other) : m_buf(nullptr), m_size(0)
{
	set(other.buf(), other.size());
}
Coder& Coder::operator=(const Coder& rhs)
{
	if (this != &rhs)
	{
		set(rhs.buf(), rhs.size());
	}
	return *this;
}

Coder::Coder(Coder && other) :m_buf(nullptr), m_size(0)
{
	m_buf = other.buf();
	m_size = other.size();
	other.m_buf = nullptr;

}
Coder& Coder::operator=(Coder && rhs)
{
	if (this != &rhs)
	{
		delete[]m_buf;
		m_buf = rhs.buf();
		rhs.m_buf = nullptr;
		m_size = rhs.size();
	}
	return *this;
}

Coder::~Coder()
{
	delete[]m_buf;
	m_buf = nullptr;
}
void Coder::set(const char* buf, int size)
{
	if (buf == 0 && size != 0)
		throw std::logic_error("lost first argument");
	if (buf != nullptr && size == 0)
		throw std::logic_error("lost second argument");
	if (size < 0 || size > std::numeric_limits<int>::max())
		throw std::logic_error("size is full");
	delete[] m_buf;
	m_buf = nullptr;
	m_buf = new char[size];
	memcpy(m_buf, buf, size);
	m_size = size;
}
char* Coder::buf() const
{
	return m_buf;
}
int Coder::size() const
{
	return m_size;
}
void Coder::encode()
{
	
	const char *key = "helloworld";
	int key_size = 10;
	char *temp = new char[m_size];
	memcpy(temp, m_buf, m_size);
	for (int i = 0; i != size; ++i)
	{
		m_buf[i] = temp[i] ^ key[i%key_size];
	}
	delete[] temp;
	temp = nullptr;
}
void Coder::decode()
{
	encode();
}
