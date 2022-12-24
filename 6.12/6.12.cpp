#include <iostream>
using namespace std;

class MyString
{
public:

	// Overloading the + operator for string concatenation
	MyString operator+(const MyString& SecondString)
	{
		size += SecondString.size;
		char* temp = new char[size];

		int i, j;
		for (i = 0; ptr[i] != '\0'; i++)
		{
			temp[i] = ptr[i];
		}

		for (j = 0; SecondString.ptr[j] != '\0'; j++)
			temp[i + j] = SecondString.ptr[j];

		temp[i + j] = '\0';

		return temp;
	}


	// Default constructor
	MyString()
	{
		size = 80;
		ptr = new char[size + 1];
		StringCount++;
	};


	// Constructor with Keyboard
	/*

	MyString(int a)
	{
		ptr = new char[150];
		cin.getline(ptr, 150);
		size = strlen(ptr);
		StringCount++;
	}

	*/

	// Constructor with constant string parameter
	MyString(const char* SecondString)
	{
		size = strlen(SecondString);
		ptr = new char[size + 1];
		strcpy_s(ptr, strlen(SecondString) + 1, SecondString);
		StringCount++;
	}

	// Constructor for an object of the same String class
	MyString(const MyString& SecondString)
	{
		size = SecondString.size;
		ptr = new char[size + 1];
		strcpy_s(ptr, size + 1, SecondString.ptr);
		StringCount++;
	}

	// Displaying values on the screen
	void Output()
	{
		if (ptr == nullptr)
		{
			return;
		}
		cout << ptr;
	}

	// Get Count Static Variable 
	static int GetCount()
	{
		return StringCount;
	}

	// Method to New String
	void NewLine()
	{
		delete[] ptr;
		ptr = new char[150];
		cin.getline(ptr, 150);
		size = strlen(ptr);
		StringCount++;
	}

	// Destructor 
	~MyString()
	{
		delete[] ptr;
		StringCount--;
	}

private:
	char* ptr;
	int size;
	static int StringCount;
};
int::MyString::StringCount = 0;

int main()
{
	MyString a("Hello");
	MyString b("World");
	MyString c = a + b;
	c.Output();
}
