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





// NEW ALGORITHM
// THIS ALGORITHM WILL INCORPORATE THE MY_STRING CLASS
// FIRST AN ANALYSIS OF THE BACKGROUND OF THE PROBLEM



// CHARACTER TYPES:

// 1. NON-PRINTABLE
// 2. WHITESPACE
// 3. VALID CHARACTERS



// END-OF-LINE SCENARIOS:

// 1. NON-PRINTABLE CHARACTERS
	// SKIP
	// DON'T INC

// 2. CHARACTER FIRST, SPACE NEXT
	// DON'T HYPHENATE
	// INC

// 3. CHARACTER FIRST, CHARACTER NEXT
	// HYPHENATE
	// INC

// 4. SPACE FIRST, CHARACTER NEXT
	// SAVE NEXT CHARACTER
	// SET SAVEFLAG
	// INC



// NEW ALGORITHM

// OPEN INPUT FILE
// OPEN OUTPUT FILE

// IF BOTH FILES OPEN THEN

	// DO
			// PROMPT COLUMN WIDTH 1-200
		// WHILE WIDTH < 1 || WIDTH > 200

	// WHILE NOT INPUTFILE FAIL

		// MY_STRING NEW STRING
		// STRING RESERVE(WIDTH)

		// NOTE: SAVEFLAG ONLY SETS ON END-OF-LINE CONDITION 4
		// IF (SAVEFLAG)
			// STRING += BUFFER
			// RESET SAVEFLAG

		// WHILE (!FAIL && INDEX < WIDTH)

			// GET BUFFER

			// SKIP NON-PRINTABLE CHARACTERS
			// IF (ISPRINT BUFFER) THEN

				// IF (ISSPACE BUFFER) THEN
					// DON'T START LINE WITH SPACE
					// DON'T REPEAT SPACE
					// IF (INDEX && !ISSPACE STRING[INDEX-1]) THEN
						// STRING += SPACE
						// ++INDEX

				// ELSE (BUFFER IS VALID CHARACTER)
					// STRING += BUFFER
					// ++INDEX
					// IF (INDEX == WIDTH) END-OF-LINE THEN
						// GET BUFFER
						// RESET INDEX = 0
						// IF (ISPRINT BUFFER && !ISSPACE BUFFER) THEN
							// INSERT HYPHEN
							// SET SAVEFLAG

		// ENDWHILE

		// PRINT STRING
		// DELETE STRING

	// ENDWHILE

	// CLOSE INPUT FILE
	// CLOSE OUTPUT FILE

// ELSE PRINT FILE ERROR
	// CLOSE INPUT FILE
	// CLOSE OUTPUT FILE
	// RETURN ERROR

// RETURN NORMAL




#include <iostream>
#include <fstream>
#include <cctype> // FOR isspace, isprint
#include <cstring> // FOR strncpy;


#include "mystring.h"
using namespace hw4;




int main()
{
	// CONSTANTS
	const char* INPUT_FILENAME = "data.txt";
	const char* OUTPUT_FILENAME = "data.out";
	const size_t MAX_WIDTH = 200;
	const char MAX_WIDTH_SPACES[] =
	//	"                                                                                                                                                                                                        ";
		// USE NON-PRINTABLE CHARACTERS INSTEAD OF SPACES
		"€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€";

	// DECLARATIONS
	bool saveFlag = false;

	char buffer;

	size_t width, index;
		width = 30;
		index = 0;

	// It takes a text file data.txt as an input file.
	// OPEN INPUT FILE
	std::ifstream inputFile(INPUT_FILENAME);

	// OPEN OUTPUT FILE
	std::ofstream outputFile(OUTPUT_FILENAME);


	// IF BOTH FILES OPEN THEN
	if (inputFile.is_open() && outputFile.is_open())
	{

///*DEBUG*/    std::cout << "FILES OPEN\n";
///*DEBUG*/    outputFile << "FILES OPEN\n";

		// DO
		do
		{
			// PROMPT COLUMN WIDTH 1-200
			std::cout << "[ENTER THE NUMBER OF COLUMN>  ";
			std::cin >> width;

			// WHILE WIDTH < 1 || WIDTH > 200
		} while (width > MAX_WIDTH || width < 1);


		// WHILE NOT INPUTFILE FAIL
		while (!inputFile.fail())
		{

			// MY_STRING NEW STRING
			typedef my_string * ptr_my_string;

			char * giddyup_horsie;
			giddyup_horsie = new char[width + 2];
			std::strncpy(giddyup_horsie, MAX_WIDTH_SPACES, (width + 2));

			ptr_my_string outputLine = new my_string(giddyup_horsie);

			// STRING RESERVE(WIDTH)
			// PREVENT FAILURE WITH RESERVE(WIDTH + 2)


			delete [] giddyup_horsie;

//			fullLine = false;


			// NOTE: SAVEFLAG ONLY SETS ON END-OF-LINE CONDITION 4
			// IF (SAVEFLAG)
			if (saveFlag)
			{
				// STRING += BUFFER
				outputLine->raw_edit(buffer, 0);

				// RESET SAVEFLAG
				saveFlag = false;

				// INDEX = 1
				index = 1;
			}

			// WHILE (!FAIL && INDEX < WIDTH)
			while (!inputFile.fail() && index < width)
			{

				// GET BUFFER
				inputFile.get(buffer);

				if (buffer == '\n')
				{
					buffer = ' ';
				}

				// SKIP NON-PRINTABLE CHARACTERS
				// IF (ISPRINT BUFFER) THEN
				if (std::isprint(buffer))
				{
					// IF (ISSPACE BUFFER) THEN
					if (std::isspace(buffer))
					{

						// DON'T START LINE WITH SPACE
						// DON'T REPEAT SPACE
						// IF (INDEX && !ISSPACE STRING[INDEX-1]) THEN
						if (index != 0 && !std::isspace(outputLine->operator[](index - 1)))
						{
							// STRING += SPACE
							outputLine->raw_edit(' ',index);

							// ++INDEX
							++index;
						}

					}
					// ELSE (BUFFER IS VALID CHARACTER)
					else
					{

						// STRING += BUFFER
						outputLine->raw_edit(buffer, index);

						// ++INDEX
						++index;
					}

						// IF (INDEX == WIDTH) END-OF-LINE THEN
						if (index == width)
						{

//							fullLine == true;

							// GET BUFFER
							inputFile.get(buffer);


							// IF (ISPRINT BUFFER && !ISSPACE BUFFER) THEN
							//if (std::isprint(buffer))
							if (!std::isspace(buffer) && (!std::isspace(outputLine->operator[](index - 1))))
							{
///*DEBUG*/	std::cout << " INSERT HYPHEN\n";
								// INSERT HYPHEN
								// DO NOT USE INSERT() WHICH CALLS UNNECESSARY RESERVE()
								outputLine->raw_edit('-', index);

								// SET SAVEFLAG
								saveFlag = true;

								// ++INDEX
								++index;
							}
								else if (std::isprint(buffer) && !std::isspace(buffer))
							{
								saveFlag = true;
							}


							// INSERT NEWLINE
							outputLine->raw_edit('\n', index);

						}
				}

			// ENDWHILE
			}

//
//			if (!fullLine)
//			{
//				while (index < width)
//				{
//					outputLine->raw_edit(char(17), index+3);
//					++index;
//				}
//			}


			// RESET INDEX = 0
			index = 0;

			// PRINT STRING
///*DEBUG*/	std::cout << "PRINT LINE SEQUENCE WITH LENGTH = " << outputLine->length() << "\n";

			std::cout << *outputLine;
			outputFile << *outputLine;


			// DELETE STRING
///*DEBUG*/	std::cout << "DELETING STRING OBJECT\n";
			delete outputLine;

		// ENDWHILE
		}


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

		// RETURN ERROR
		std::cout << "[FATAL ERROR: 13 (UNABLE TO OPEN INPUT OR OUTPUT FILE)]\n";
		return 13;
	}


	// RETURN NORMAL
	return 0;
}






































//// THIS IS THE ORIGINAL ALGORITHM
//// THE ORIGINAL ALGORITHM DIDN'T INCORPORATE THE MY_STRING CLASS
//// THEREFORE THE ORIGINAL ALGORITHM WILL BE SCRAPPED
//
//
//// Your program should ask the number of column to the user and format the text file accordingly.
//// For example, if a user types 65, every line should be aligned 65 long.
//// DO
//	// PROMPT COLUMN WIDTH 1-200
//	// WHILE WIDTH < 1 || WIDTH > 200
//
//// It takes a text file data.txt as an input file.
//// OPEN INPUT FILE
//// OPEN OUTPUT FILE
//// IF BOTH FILES OPEN THEN
//
//	// WHILE NOT INPUT FILE FAIL
//		// READ NEXT CHAR TO BUFFER CHAR
//
//		// 3) There should be no more than one white space between two words.
//		// Multiple spaces, newlines or tabs must be replaced with a space.
//		// SWITCH BUFFER
//			// CASE NEWLINE
//			// CASE TAB
//			// CASE SPACE
//				// IF NOT SPACE FLAG SET THEN
//					// SET SPACE FLAG
//					// PRINT SPACE TO FILE
//					// PRINT SPACE TO CONSOLE
//				// BREAK
//			// DEFAULT
//				// CLEAR SPACE FLAG
//				// For the output, display the formatted text on screen and save it to data.out file.
//				// PRINT BUFFER TO FILE
//				// PRINT BUFFER TO CONSOLE
//				// BREAK
//		// INCREMENT INDEX
//
//		// You can assume that a hyphen can be added after the maximum column.
//		// 2) in cases you need to change line in the middle of a word, you need to use a hyphen (-) to connect a word between two lines.
//		// IF INDEX == WIDTH THEN
//			// IF NOT SPACE FLAG SET THEN
//				// PRINT HYPHEN TO FILE
//				// PRINT HYPHEN TO CONSOLE
//			// INDEX = 0
//
//	// END WHILE
//
//	// CLOSE INPUT FILE
//	// CLOSE OUTPUT FILE
//// ELSE PRINT FILE ERROR
//
//// DON'T FORGET TO REDUCE EFFICIENCY BY STORING FILE CHARACTER DATA TO MULTIPLE MYSTRING OBJECTS
//
//
//#include <iostream>
//#include <fstream>
//#include <cctype> // FOR isspace, isprint
//
//
//
//
//
//// ANALYZE PROBLEM: REGULAR CHARACTER THAT ENDS A WORD AT THE END OF A PROCESSED LINE CAUSES HYPEN INSERTION
//// PROJECTED SOLUTION: SECONDARY CHAR VARIABLE OR PEEK
//
//
//
//
//
//
//
//
//int main()
//{
//	// CONSTANTS
//	const char* INPUT_FILENAME = "data.txt";
//	const char* OUTPUT_FILENAME = "data.out";
//	const int MAX_WIDTH = 200;
//
//	// DECLARATIONS
//	bool spaceFlag = 0;
//	char buffer;
//
//	int width, index;
//		width = index = 0;
//
//	// It takes a text file data.txt as an input file.
//	// OPEN INPUT FILE
//	std::ifstream inputFile(INPUT_FILENAME);
//
//	// OPEN OUTPUT FILE
//	std::ofstream outputFile(OUTPUT_FILENAME);
//
//
/////*DEBUG*/	std::cout << "\nALGORITHM VARIABLE BYTES ALLOCATED ON STACK = "
/////*DEBUG*/	 			<< sizeof(spaceFlag) + sizeof(buffer) + sizeof(width) + sizeof(index) << "\n";
//
/////*DEBUG*/	std::cout << "VARIABLE BYTES CORRESPONDING TO FILE OBJECTS = "
/////*DEBUG*/	 			<< sizeof(inputFile) + sizeof(outputFile) << "\n";
//
/////*DEBUG*/	std::cout << "BYTES ALLOCATED TO CONSTANTS = "
/////*DEBUG*/	 			<< sizeof(INPUT_FILENAME) + sizeof(OUTPUT_FILENAME) + sizeof(MAX_WIDTH) << "\n";
//
/////*DEBUG*/	std::cout << "BYTES ALLOCATED ON HEAP = 0\n\n";
//
//
//	// IF BOTH FILES OPEN THEN
//	if (inputFile.is_open() && outputFile.is_open())
//	{
//
/////*DEBUG*/    std::cout << "FILES OPEN\n";
/////*DEBUG*/    outputFile << "FILES OPEN\n";
//
//
//		// Your program should ask the number of column to the user and format the text file accordingly.
//		// For example, if a user types 65, every line should be aligned 65 long.
//		// DO
//		do
//		{
//			// PROMPT COLUMN WIDTH 1-200
//			std::cout << "[ENTER THE NUMBER OF COLUMN>  ";
//			std::cin >> width;
//
//			// WHILE WIDTH < 1 || WIDTH > 200
//		} while (width > MAX_WIDTH || width < 1);
//
//
//		// WHILE NOT INPUT FILE FAIL
//		while (!inputFile.fail())
//		{
//			// READ NEXT CHAR TO BUFFER CHAR
//			inputFile.get(buffer);
//
/////*DEBUG*/	std::cout << buffer;{
//
//			// IF BUFFER == NEWLINE
//			if (buffer == '\n')
//			{
//				// SET SPACE FLAG
//				spaceFlag = true;
//
//				// PRINT SPACE TO CONSOLE
//				std::cout << ' ';
//
//				// PRINT SPACE TO FILE
//				outputFile << ' ';
//
//				// INCREMENT INDEX
//				++index;
//			}
//
//
//			// ELSE IF BUFFER CHARACTER CANNOT BE PRINTED THEN SKIP TO NEXT CHARACTER
//			else if (std::isprint(buffer))
//			{
//
//				// 3) There should be no more than one white space between two words.
//				// Multiple spaces, newlines or tabs must be replaced with a space.
//				// IF ISSPACE(BUFFER)
//				if (std::isspace(buffer))
//				{
//					// IF NOT SPACE FLAG SET THEN
//					if (!spaceFlag)
//					{
//						// SET SPACE FLAG
//						spaceFlag = true;
//
//						// PRINT SPACE TO CONSOLE
//						std::cout << ' ';
//
//						// PRINT SPACE TO FILE
//						outputFile << ' ';
//
//						// INCREMENT INDEX
//						++index;
//					}
//
//					// DO NOT INCREMENT INDEX IF BOTH ISSPACE(BUFFER) AND SPACEFLAG ARE TRUE
//
//					// NON-SPACE CHARACTERS WILL RUN THE ELSE SUBROUTINE
//				} else
//				{
//					// CLEAR SPACE FLAG
//					spaceFlag = false;
//
//					// For the output, display the formatted text on screen and save it to data.out file.
//					// PRINT BUFFER TO CONSOLE
//					std::cout << buffer;
//
//					// PRINT BUFFER TO FILE
//					outputFile << buffer;
//
//					// INCREMENT INDEX
//					++index;
//				}
//
//
//				// You can assume that a hyphen can be added after the maximum column.
//				// 2) in cases you need to change line in the middle of a word, you need to use a hyphen (-) to connect a word between two lines.
//				// IF INDEX == WIDTH THEN
//				if (index == width)
//				{
//					// IF NOT SPACE FLAG SET THEN
//					if (!spaceFlag)
//					{
//						// PRINT HYPHEN TO CONSOLE
//						std::cout << '-';
//
//						// PRINT HYPHEN TO FILE
//						outputFile << '-';
//					}
//
//					// PRINT NEWLINE TO CONSOLE
//					std::cout << std::endl;
//
//					// PRINT NEWLINE TO FILE
//					outputFile << std::endl;
//
//					// INDEX = 0
//					index = 0;
//
//				}
//			}
//
//
//
//			// END WHILE
//		}
//
//
//		// CLOSE INPUT FILE
//		inputFile.close();
//
//		// CLOSE OUTPUT FILE
//		outputFile.close();
//
//	}
//	// ELSE PRINT FILE ERROR
//	else
//	{
//		// CLOSE INPUT FILE
//		inputFile.close();
//
//		// CLOSE OUTPUT FILE
//		outputFile.close();
//
//		std::cout << "[FATAL ERROR: 13 (UNABLE TO OPEN INPUT OR OUTPUT FILE)]\n";
//		return 13;
//	}
//
//	// DON'T FORGET TO REDUCE EFFICIENCY BY STORING FILE CHARACTER DATA TO MULTIPLE MYSTRING OBJECTS
//
//	return 0;
//}
//
//
