#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main(void){

	//1
	printf("User Real Identifier is: %d\nUser Effective Identifier is: %d\n", getuid(), geteuid());	//prints current uid and euid

	//2
	FILE *file = fopen("3.txt", "r");	//opens the file for the task with -|rw-|---|--- permissions

	if (!file) 	perror("\nThere was a error in the file opening");	//prints the error message in stderr if the file wasn't opened
	else {

		printf("\nThe \"3.txt\" file was succesfully opened.\n");

		fclose(file);	//closes the file if the file was opened

		printf("The \"3.txt\" file was succesfully closed.");
	}

	//3
	setuid(getuid());	//sets euid value to uid

	printf("\nThe User Effective Identifier has been setted to the User Real Identifier\n\n");

	//4: repeat first two steps

	//4.1
	printf("User Real Identifier is: %d\nUser Effective Identifier is: %d\n", getuid(), geteuid());	//prints current uid and euid

	//4.2
	file = fopen("3.txt", "r");	//opens the file for the task with -|rw-|---|--- permissions

	if (!file) 	perror("\nError message");	//prints the error message in stderr if the file wasn't opened
	else {

		printf("\nThe \"3.txt\" file was succesfully opened.\n");

		fclose(file);	//closes the file if the file was opened

		printf("The \"3.txt\" file was succesfully closed.\n");
	}

	return 0;
}
