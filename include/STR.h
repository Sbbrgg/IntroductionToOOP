#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------------------------------\n"

/////////////////////////////////////////////////////////////////////////
////////		Объявление класса (Class declaration)			/////////

class String
{
	int size;	//размер строки в байтах(с учётом '\0' (NULL - Terminator));;;;;;размер строки в символах без '\0'
	char* str;	//адрес стркои в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//				Operators
	String& operator=(const String& other);
	String& operator=(String&& other);
	char operator[](int i) const;
	char& operator[](int i);

	//				Methods:
	void print()const;
};

String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

////////	Конец объявление класса (Class declaration end)		/////////
/////////////////////////////////////////////////////////////////////////
