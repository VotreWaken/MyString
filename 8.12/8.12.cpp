#include <iostream>
using namespace std;

class MyString
{
public:


	// Overloading the ++ prefix operator (Adding x to the beginning)
	/*

	char* operator++()
	{
		size++;
		char* temp = new char[size];
		for (int i = 0; i < size; i++)
		{
			temp[i + 1] = ptr[i];
		}
		temp[0] = 'x';

		delete[] ptr;
		ptr = new char[size + 1];
		Mystrcpy_s(ptr, strlen(temp) + 1, temp);
		return temp;
	}

	*/

	// Overloading the ++ prefix operator (Adding x to the end)
	MyString operator++()
	{
		size++;
		char* temp = new char[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = ptr[i];
		}

		delete[] ptr;
		ptr = new char[size + 1];
		temp[size - 1] = 'x';
		temp[size] = '\0';
		Mystrcpy_s(ptr, strlen(temp) + 1, temp);
		return temp;
	}

	// Overloading the -- prefix operator (Deletion from the beginning)

	/*

	MyString operator--()
	{
		size--;
		char* temp = new char[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = ptr[i + 1];
		}
		ptr = new char[size + 1];
		temp[size] = '\0';
		Mystrcpy_s(ptr, strlen(temp) + 1, temp);
		return temp;
	}

	*/

	// Overloading the + operator (Adding x to the beginning depending on int value)

	/*

	MyString operator+(int value)
	{
		size += value;
		char* temp = new char[size];
		int i = 0;
		for (i = 0; i < value; i++)
		{
			temp[i] = 'x';
		}

		for (int j = 0; j < size; j++,i++)
		{
			temp[i] = ptr[j];
		}
		delete[] ptr;
		ptr = new char[size + 1];
		Mystrcpy_s(ptr, strlen(temp) + 1, temp);
		return temp;
	}

	*/

	// Overloading the + operator (Adding x to the end depending on int value)
	MyString operator+(int value)
	{
		size += value;
		char* temp = new char[size];
		int i = 0;
		for (i = size; i > size - value - 1; i--)
		{
			temp[i] = 'x';
		}

		for (int j = 0; j < size - value; j++, i++)
		{
			temp[j] = ptr[j];
		}
		delete[] ptr;
		temp[size] = '\0';
		ptr = new char[size + 1];
		Mystrcpy_s(ptr, strlen(temp) + 1, temp);
		return temp;
	}

	// Overloading the - operator (Deletion from the end depending on int value)
	MyString operator-(int value)
	{
		size -= value;
		char* temp = new char[size];

		for (int i = 0; i < size; i++)
		{
			temp[i] = ptr[i];
		}
		temp[size] = '\0';
		ptr = new char[size + 1];
		Mystrcpy_s(ptr, strlen(temp) + 1, temp);
		return temp;
	}


	// Overloading the -- prefix operator (Deletion from the end)
	MyString operator--()
	{
		size--;
		char* temp = new char[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = ptr[i];
		}
		delete[] ptr;
		ptr = new char[size + 1];
		temp[size] = '\0';
		Mystrcpy_s(ptr, strlen(temp) + 1, temp);
		return temp;
	}


	// Strlen Function
	int MyStrlen(const char* UserString)
	{
		int count = 0;
		while (*UserString != '\0')
		{
			count++;
			UserString++;
		}
		return count;
	}

	// Strcpy Function (secure)
	char* Mystrcpy_s(char* UserString, int Size, const char* SecondUserString)
	{
		if (Size > MyStrlen(UserString))
		{
			cout << "Error Buffer too small\n";
			return 0;
		}

		int i;
		for (i = 0; i < Size - 1; i++)
		{
			UserString[i] = SecondUserString[i];
		}
		UserString[i] = '\0';
		return UserString;
	}

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
	++a;
	a.Output();
	cout << endl;
	MyString b("World");
	--b;
	b.Output();
	cout << endl;
	MyString c = a + 5;
	c.Output();
	cout << endl;
	MyString d = b - 2;
	d.Output();
}
