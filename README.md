#appdev for I-IT-1N&2
----------------------------------------------------------------------------
-------------------------Application Development 2020-----------------------
----------------------------------------------------------------------------


This project is made in course "Application Developments 2020" for us to 
understand what tools and measures will be used in an software application
development.

List of contents
1:Configuration instructions
2:Installation instuctions
3:Operating instructions
4:FILE manifest
5:Copyright and Licensing informaiton
6:Contact information
7:Credits and ackknowledgements



1.Configuration Instructions
	We need use putty for this section or using linux operating system.
	This app include several libraries such as: math , lcurl , stdio , stdint , ...
	to run this application

2.Installation instructions
	First   : Connect to the Putty by using student account
	Second  : using command "make" on the command window to compile all the .c file and make the executed file (sound)
	Third 	: Using command "./sound" to run the program
	If you want to check the content inside files, you can use "nano namefile" to access that file
	or using "make clean" to terminate .o file  
	*note: always rememmber that this programe include -lcurl -lm libraries to run the programm.
3.Operating instructions
	Using command "./sound" to run the program
	Because after compiling the files , we got the executed file (sound). and this file can be considered as the output file of the app.
	Please: Enter or using any keyboard to continue the application
	
4.File manifest
	We should list all the files of this application at here with short 
	description.

	List of files:
	README.md		this file.
	screen.c		contains screen manipulation functions
	screen.h		contains constant definitions and function declarations
					of screen.c
	testcur1.c		contains zip file of screen.c screen.h and testscreen.c
	testscreen.c 	contains the main file of source code or the output file
					of animation
	comm.c			contains posting and reposting information to the website 
	comm.h			contains constant definitions and function declarations
					of comm.c
	makefile		contains makefile function and operating command

	sound.c 		contains reading , using , organize the wav file in the course
	sound.h			contains constant definitions and function declarations
					of sound.c
	main.c 			include the main content of reading wav data and using this information
					 for several pupose 

	puttysize.php 	this file contents the reading and writing the post data from the main.c 
					and make the putty file to store data.
					
	
5.Copy right
	This application follow GPLv2 copyright.
6.Contact Information
	Email:			roft.poseidon@gmail
	Phone Number:	0906486980
7.Credits and acknowledgements
	
