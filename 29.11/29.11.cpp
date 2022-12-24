#include <iostream>
using namespace std;

class MyString
{
public:
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
	MyString a;
	a.NewLine();
	a.Output();
}
