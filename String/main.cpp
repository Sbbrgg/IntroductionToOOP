#include <iostream>
using namespace std;

class String
{
	int length;
	char* str;
public:
	int get_length()const
	{
		return length;
	}
	char* get_str()const
	{
		return str;
	}

	//				Constructors
	String(int lenght = 0)
	{
		this->length = lenght;
		this->str = nullptr;
		if (lenght > 0)
		{
			this->str = new char[lenght + 1] {};
			str[lenght] = '\0';
		}
	}
	String(const char* string)
	{
		this->length = 0;
		this->str = nullptr;
		while (string[length] != 0)
			length++;
		if (length > 0)
		{
			str = new char[length + 1];
			for (int i = 0; i < length; i++)
				this->str[i] = string[i];
			this->str[length] = '\0';
		}
	}
	String(const String& other)
	{
		this->length = other.length;
		str = new char[this->length + 1];
		for (int i = 0; i <= this->length; i++)
			str[i] = other.str[i];
	}
	~String()
	{
		delete[] str;
		str = nullptr;
	}
	//				Operators
	String& operator=(const String& other)
	{
		length = other.length;
		str = new char[length + 1] {};
		for (int i = 0; i < length; i++)
			str[i] = other.str[i];
		return* this;
	}
	String operator+(const String& other)
	{
		String result;
		result.length = this->length + other.length;
		result.str = new char[strlen(this->str) + strlen(other.str) + 1];
		for (int i = 0; i < strlen(this->str); i++)
			result.str[i] = this->str[i];
		for (int i = 0; i < strlen(other.str); i++)
			result.str[this->length + i] = other.str[i];
		result.str[result.length] = '\0';
		return result;
	}
};
	std::ostream& operator<<(std::ostream& os, const String& obj)
	{
		for (int i = 0; obj.get_str()[i] != '\0'; i++)
			os << obj.get_str()[i];
		return os;
	}

void main()
{
	setlocale(LC_ALL, "");
	String s1 = "Hello ";
	String s2 = "World";
	String s3 = s1 + s2;

	cout << s3 << endl; // Выведет "HelloWorld"

	String s4;
	s4 = s1;
	cout << s4 << endl; // Выведет "Hello"
}