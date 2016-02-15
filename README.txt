*******************************************************
*  Name      :  BRIAN SUMNER        
*  Student ID:  xxxxx6939               
*  Class     :  UCD CSCI 2421-E01           
*  HW#       :  3               
*  Due Date  :  2016 FEB. 15
*******************************************************


                 README.txt


*******************************************************
*  PROGRAM DESCRIPTION
*******************************************************


The program "6936HW3" reformats a text file according to 
specification provided in CSCI 2421-E01 HW3 Spring 2016.

NOTE: This README.txt was modified from the example
      provided by Dr. Min Choi.



*******************************************************
*  SOURCE FILES
*******************************************************


Name:  main.cpp
   Main program.  This creates objects of the specified 
   my_string class and uses fstream objects to reformat 
   a text file according to specification.  More details 
   can be found in the source code.

Name:  mystring.h
   This is the declaration header for the my_string class.

Name:  mystring.cpp
   This is the implementation file for the my_string class.

Name:  data.txt
   This is a sample data.txt data file.  The program will 
   read text from this file before reformatting and 
   outputting said text.  You may utilize a custom 
   data.txt file if you wish.
   
Name:  Makefile
   This facilitates trouble-free compilation of the program.
   
Name:  README.txt
   This is the file you are currently reading.
   You must have done something correctly.


*******************************************************
*  BUILD HISTORY/STATUS
*******************************************************


   The original program algorithm runs successfully 
   using no string objects whatsoever.  However, when I 
   asked Dr. Choi if I needed to retrofit my already-
   efficient code to incorporate my_string objects, 
   he told me that I did.  Therefore, I rewrote the 
   algorithm in a similar manner as the first, but 
   this time including dynamically-allocated (and 
   deallocated) my_string objects, a selection of 
   character and c_string related library functions, 
   and an overloaded << stream operator.  The original 
   algorithm is attached to the bottom of main.cpp 
   as a large comment section.

   Although my second algorithm is less efficient than 
   the first, it does accomplish all the tasks assigned 
   to this project.  The only known bug can be observed 
   when setting the column width to a multiple of 16 
   characters plus 6 more (i.e. 22, 38, 54, or 70 
   characters, etc.) - in which case one extra character 
   is printed at the very end of the processed file. 
   This is somewhat bizarre behavior that I was not able 
   to eradicate without ending the output text file with 
   an extra '\n' newline character (which was not 
   requested in the instructions).  Other than the known 
   bug, this program appears to work perfectly.

   Given that the requirement for "Using the mystring.h 
   and mystring.cpp" is vague (other than the prohibition 
   against using the STL string class), and that 
   the exact procedure for accomplishing the tasks given
   in the instructions is equally vague, I believe that 
   I have duly satisfied all the requirements for the 
   project.  Therefore I trust that my grade for such 
   will reflect the sastifaction of said requirements.
   

   The program was developed and tested on GNU g++ 
   4:4.8.2-1ubuntu6 using Linux Cinnamon Mint 17.3 x64.
   It was also tested on the UCDenver CSE grid.  
 


*******************************************************
*  BUILD INSTRUCTIONS
*******************************************************


1. Carefully read all of the following instructions before 
   continuing.  If you do not understand any of them, 
   conduct appropriate research as necessary until you do. 
   This program is intended for experienced programmers only.


2. This README.txt file is located within "6936HW3.tgz" - 
   be sure to extract the contents of this archive into 
   some working directory.


3. In terminal, change to the "6936HW3/" directory you just 
   created.  The files in this directory are as follows:

       ./main.cpp
       ./mystring.h
       ./mystring.cpp
       ./data.txt
       ./Makefile
       ./README.txt


4. Compile the program by executing the following command:
    
       $ make


3. Run the program by executing the following command:

       $ ./6936HW3_exec


4. Delete all binary files if desired by executing the following command:

       $ make clean


5. Step 5.



6. Profit.
       
