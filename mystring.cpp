// CLASS IMPLEMENTED: my_string (see mystring.h for documentation)
// INVARIANT for the my_string class:
// 1. The string is stored as a null-terminated string in the dynamic array
//    that characters points to.
// 2. The total length of the dynamic array is stored in the member variable
//    allocated.
// 3. The total number of characters prior to the null character is stored in
//    current_length, which is always less than allocated. 

#include <ctype.h>		// Provides stream tools
#include <assert.h>		// Provides assert()
#include <string.h>		// Provides strcpy(), strcat(), strlen(), strcmp()
#include <stdlib.h>		// Provides size_t, NULL
#include <iostream>		// Provides stream types
#include "mystring.h"
using namespace std;

namespace hw4
{

// CONSTRUCTORS and DESTRUCTOR
	my_string::my_string(const char str[])
// Library facilities used: string.h
	{
		current_length = strlen(str);
		allocated = current_length + 1;
		sequence = new char[allocated];
		strcpy(sequence, str);
	}

	my_string::my_string(const my_string &source)
// Library facilities used: string.h
	{
		sequence = new char[source.allocated];
		current_length = source.current_length;
		allocated = source.allocated;
		strcpy(sequence, source.sequence);
	}

	my_string::~my_string()
	{
		delete[] sequence;
	}

// MODIFICATION MEMBER FUNCTIONS
// CONSTANT MEMBER FUNCTIONS
// In-lined: size_t length( ) const;
	char my_string::operator[](size_t position) const
// Library facilities used: assert.h
	{
///*DEBUG*/ std::cout << "POSITION = " << position << "     CHAR = " << sequence[position] << "\n";
		assert(position < current_length);
		return sequence[position];
	}


// += Operator overloading. 
	void my_string::operator+=(const my_string &addend)
// Library facilities used: string.h
	{
		size_t totalLength;

		totalLength = (current_length + 1 + addend.current_length);
		if (allocated < totalLength)
			reserve(totalLength);
		strcat(sequence, addend.sequence);
		current_length = totalLength - 1;
	}


// += Operator overloading.
	void my_string::operator+=(const char addend[])
// Library facilities used: string.h
	{
		size_t totalLength;

		totalLength = current_length + 1 + strlen(addend);
		if (allocated < totalLength)
			reserve(totalLength);
		strcat(sequence, addend);
		current_length = totalLength - 1;
	}


// += Operator overloading.
	void my_string::operator+=(char addend)
// Library facilities used: string.h
	{
		char addstring[2];
		addstring[0] = addend;
		addstring[1] = '\0';
		size_t totalLength;

		totalLength = (current_length + 2);
/*DEBUG*/    std::cout << "totalLength = " << totalLength << "n";
		if (allocated < totalLength)
			reserve(totalLength);
		strcat(sequence, addstring);
		current_length = totalLength - 1;
	}


	void my_string::reserve(size_t n)
	{
		size_t i;
		char *larger_string;

		if (n == allocated)
			return; // The allocated memory is already the right size
		if (n < current_length + 1)
			n = current_length + 1; // Can't allocate less than is being used

		larger_string = new char[n];
		for (i = 0; i < current_length + 1; i++)
			larger_string[i] = sequence[i];
		delete[] sequence;
		sequence = larger_string;
		allocated = n;
	}


	void my_string::insert(size_t n)
// Function to insert a hyphen between words in a string
	{
		size_t totalLength;
		totalLength = current_length + 2;
		reserve(totalLength);
		current_length = totalLength - 1;
		// Insert necessary hyphen at appropriate position
		if ((sequence[n - 1] == ' ') && (sequence[n + 1] != ' '))
			// Insert hyphen at column + 1 position
		{
			for (int i = current_length; i > n + 1; --i)
				sequence[i] = sequence[i - 1];
			sequence[n + 1] = '-';
		}
		else
			// Insert hyphen at column position
		{
			for (int i = current_length; i > n; --i)
				sequence[i] = sequence[i - 1];
			sequence[n] = '-';
		}
	}


// = Operator overloading.
	void my_string::operator=(const my_string &source)
	{
		size_t i;
		char *new_string;

		if (allocated != source.allocated)
		{
			new_string = new char[source.allocated];
			delete[] sequence;
			sequence = new_string;
			allocated = source.allocated;
		}
		current_length = source.current_length;
		for (i = 0; i < current_length + 1; i++)
			sequence[i] = source.sequence[i];
	}


// FRIEND FUNCTIONS
// << Operator overloading.
	ostream &operator<<(ostream &outs, const my_string &source)
	{
		size_t i;

		for (i = 0; i < source.current_length; i++)
			outs << source.sequence[i];
		return outs;
	}


// == Operator overloading.
	bool operator==(const my_string &s1, const my_string &s2)
// Library facilities used: string.h
	{
		int comp = strcmp(s1.sequence, s2.sequence);

		return (comp == 0);
	}


// != Operator overloading.
	bool operator!=(const my_string &s1, const my_string &s2)
// Library facilities used: string.h
	{
		int comp = strcmp(s1.sequence, s2.sequence);

		return (comp != 0);
	}


// >= Operator overloading.
	bool operator>=(const my_string &s1, const my_string &s2)
// Library facilities used: string.h
	{
		int comp = strcmp(s1.sequence, s2.sequence);

		return ((comp > 0) || (comp == 0));
	}


// <= Operator overloading.
	bool operator<=(const my_string &s1, const my_string &s2)
// Library facilities used: string.h
	{
		int comp = strcmp(s1.sequence, s2.sequence);

		return ((comp < 0) || (comp == 0));
	}


// > Operator overloading.
	bool operator>(const my_string &s1, const my_string &s2)
// Library facilities used: string.h
	{
		int comp = strcmp(s1.sequence, s2.sequence);

		return (comp > 0);
	}

// < Operator overloading.
	bool operator<(const my_string &s1, const my_string &s2)
// Library facilities used: string.h
	{
		int comp = strcmp(s1.sequence, s2.sequence);

		return (comp < 0);
	}


// + Operator overloading.
// NON-MEMBER FUNCTIONS for the String class
	my_string operator+(const my_string &s1, const my_string &s2)
	{
		my_string combinedString;

		combinedString += s1;
		combinedString += s2;

		return combinedString;
	}


// >> Operator overloading.
	istream &operator>>(istream &ins, my_string &target)
	{
		char c;

		while (ins && isspace(ins.peek()))
			ins.ignore();
		target = ""; // Set the target to the empty string.
		while (ins && !isspace(ins.peek()))
		{
			ins >> c;
			target += c; // Call the operator += with a char argument.
		}

		return ins;
	}


	void getline(istream &ins, my_string &target)
	{
		char c;

		eat_white(ins, target);   // Removes initial whitespace
		target = "";
		ins.get(c);
		while (ins && (c != '\n'))
		{
			target += c;
			if (ins && isspace(ins.peek()) && ins.peek() != '\n')
			{
				eat_white(ins, target); // Removes additional
				// whitespace between words
				target += ' ';
			}
			ins.get(c);
		}
	}

	void eat_white(istream &ins, my_string &target)
	{
		while (ins && isspace(ins.peek()))
			ins.ignore();
	}


// OVERLOADED <<
	std::ostream &operator<<(std::ostream &os, my_string &source)
	{
		size_t index;

///*DEBUG*/    std::cout << "SOURCE LENGTH = " << source.length() << "\n";

		for (index = 0; index < source.length(); ++index)
		{
///*DEBUG*/    std::cout << "SOURCE = " << source.operator[](index) << "\n";
			if (std::isprint(source.operator[](index)) || source.operator[](index) == '\n')
				os << (source.operator[](index));

///*DEBUG*/ if (!isprint(source.operator[](index))) os << "INVALID CHARACTER SENT TO STREAM\n";

		}

		return os;
	}


	void my_string::raw_edit(char arg_char, size_t position)
	{
		assert(position < current_length);
		sequence[position] = arg_char;
///*DEBUG*/	std::cout << "WROTE " << sequence[position] << " AT " << position << "\n";
	}


}