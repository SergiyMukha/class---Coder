#include<iostream>
#include<string>
#ifndef CODER_H
#define CODER_H

// Coder class header.

class Coder
{
public:
	Coder();
	Coder(const Coder&);
	Coder& operator=(const Coder&);
	Coder(Coder &&);
	Coder& operator=(Coder &&);
	~Coder();

	void set( const char* buf, int size );
	char* buf() const;
	int size() const;

	void encode();
	void decode();

private:
	char* m_buf;
	int m_size;
};


#endif // CODER_H
