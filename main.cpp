// Homework 3
//
// Refer to the documenting and submitting homework from here.
//
// Using the mystring.h and mystring.cpp, (you're not supposed to use STL string
// for this homework)
//
// 1) implement a text file formatting program. It takes a text file data.txt as
// an input file. The file name can be hard-coded in your program or take a file
// name as a command line parameter. The file has a few lines of text but the
// length(column) of the line is arbitrary. One line could have anywhere between
// 1 to 200 characters before a new line (carriage return). Your program should
// ask the number of column to the user and format the text file accordingly.
// For example, if a user types 65, every line should be aligned 65 long. You may
// have to combine two lines to one to eliminate the white spaces and blank lines,
// or split one to two.
//
// 2) in cases you need to change line in the middle of a word, you need to use a
// hyphen (-) to connect a word between two lines.
//
// 3) There should be no more than one white space between two words. Multiple
// spaces, newlines or tabs must be replaced with a space.
//
// You can assume that a hyphen can be added after the maximum column. So if
// you're formatting a text to 60 columns and a word is starting at the 60th
// column, you can add hyphen at 61st. Only the hyphen can come at 61st.
//
// For the output, display the formatted text on screen and save it to data.out file.
//
//
// Hint: read Appendix F for the file I/O and string handling. You may find
// eat_white( ) function useful for removing white spaces. Read Standard C String &
// Character and use appropriate functions like strcpy, strcat, memcmp etc.
//
// Grading guideline
//
// Correct and complete functionality 70%
// Reasonable fault tolerance, i.e. it should not crash often. 10%
// Makefile and Readme 10%
// Documentation and comments in the code 10%
//
// Due on Feb. 15th at 4PM.




// Your program should ask the number of column to the user and format the text file accordingly.
// For example, if a user types 65, every line should be aligned 65 long.
// DO
	// PROMPT COLUMN WIDTH 1-200
	// WHILE WIDTH < 1 || WIDTH > 200

// It takes a text file data.txt as an input file.
// OPEN INPUT FILE
// OPEN OUTPUT FILE
// IF BOTH FILES OPEN THEN

	// WHILE NOT INPUT FILE FAIL
		// READ NEXT CHAR TO BUFFER CHAR

		// 3) There should be no more than one white space between two words.
		// Multiple spaces, newlines or tabs must be replaced with a space.
		// SWITCH BUFFER
			// CASE NEWLINE
			// CASE TAB
			// CASE SPACE
				// IF NOT SPACE FLAG SET THEN
					// SET SPACE FLAG
					// PRINT SPACE TO FILE
					// PRINT SPACE TO CONSOLE
				// BREAK
			// DEFAULT
				// CLEAR SPACE FLAG
				// For the output, display the formatted text on screen and save it to data.out file.
				// PRINT BUFFER TO FILE
				// PRINT BUFFER TO CONSOLE
				// BREAK
		// INCREMENT INDEX

		// You can assume that a hyphen can be added after the maximum column.
		// 2) in cases you need to change line in the middle of a word, you need to use a hyphen (-) to connect a word between two lines.
		// IF INDEX == WIDTH THEN
			// IF NOT SPACE FLAG SET THEN
				// PRINT HYPHEN TO FILE
				// PRINT HYPHEN TO CONSOLE
			// INDEX = 0

	// END WHILE

	// CLOSE INPUT FILE
	// CLOSE OUTPUT FILE
// ELSE PRINT FILE ERROR

// DON'T FORGET TO REDUCE EFFICIENCY BY STORING FILE CHARACTER DATA TO MULTIPLE MYSTRING OBJECTS


#include <iostream>
#include <fstream>





int main()
{
	// CONSTANTS
	const char* INPUT_FILENAME = "data.txt";
	const char* OUTPUT_FILENAME = "data.out";
	const int MAX_WIDTH = 200;

	// DECLARATIONS
	bool spaceFlag = 0;
	char buffer;

	int width, index;
		width = index = 0;


	// It takes a text file data.txt as an input file.
	// OPEN INPUT FILE
	std::ifstream inputFile(INPUT_FILENAME);

	// OPEN OUTPUT FILE
	std::ofstream outputFile(OUTPUT_FILENAME);

	// IF BOTH FILES OPEN THEN
	if (inputFile.is_open() && outputFile.is_open())
	{

/*DEBUG*/    std::cout << "FILES OPEN\n";
/*DEBUG*/    outputFile << "FILES OPEN\n";


		// Your program should ask the number of column to the user and format the text file accordingly.
		// For example, if a user types 65, every line should be aligned 65 long.
		// DO
		do
		{
			// PROMPT COLUMN WIDTH 1-200
			std::cout << "[ENTER THE NUMBER OF COLUMN>  ";
			std::cin >> width;

			// WHILE WIDTH < 1 || WIDTH > 200
		} while (width > MAX_WIDTH || width < 1);


		// WHILE NOT INPUT FILE FAIL
		while (!inputFile.fail())
		{
			// READ NEXT CHAR TO BUFFER CHAR
			inputFile.get(buffer);

/*DEBUG*/	std::cout << buffer;

			// 3) There should be no more than one white space between two words.
			// Multiple spaces, newlines or tabs must be replaced with a space.
			// SWITCH BUFFER
			// CASE NEWLINE
			// CASE TAB
			// CASE SPACE
			// IF NOT SPACE FLAG SET THEN
			// SET SPACE FLAG
			// PRINT SPACE TO FILE
			// PRINT SPACE TO CONSOLE
			// BREAK
			// DEFAULT
			// CLEAR SPACE FLAG
			// For the output, display the formatted text on screen and save it to data.out file.
			// PRINT BUFFER TO FILE
			// PRINT BUFFER TO CONSOLE
			// BREAK
			// INCREMENT INDEX

			// You can assume that a hyphen can be added after the maximum column.
			// 2) in cases you need to change line in the middle of a word, you need to use a hyphen (-) to connect a word between two lines.
			// IF INDEX == WIDTH THEN
			// IF NOT SPACE FLAG SET THEN
			// PRINT HYPHEN TO FILE
			// PRINT HYPHEN TO CONSOLE
			// INDEX = 0

		}
		// END WHILE


		// CLOSE INPUT FILE
		inputFile.close();

		// CLOSE OUTPUT FILE
		outputFile.close();

	}
	// ELSE PRINT FILE ERROR
	else
	{
		// CLOSE INPUT FILE
		inputFile.close();

		// CLOSE OUTPUT FILE
		outputFile.close();

		std::cout << "[FATAL ERROR: 13 (UNABLE TO OPEN INPUT OR OUTPUT FILE)]\n";
		return 13;
	}

	return 0;
}


