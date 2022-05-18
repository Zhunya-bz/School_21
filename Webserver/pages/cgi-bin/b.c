#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void){
	// This program prints out the data entered by the user.
	printf("Content-type: text/plain");
	printf("\r\n\r\n");
	// Output a CGI title, the meaning of this line of code will be explained later
	char *pszMethod;
	pszMethod = getenv("REQUEST_METHOD");
	if(strcmp(pszMethod,"GET") == 0)
	{
		//GET method
		// Read the environment variable to get the data
		printf("This is GET METHOD!\n");
		printf("SERVER_NAME: %s\n", getenv("SERVER_NAME"));
		printf("REMOTE_ADDR: %s\n", getenv("REMOTE_ADDR"));
		printf("Your answer is:%s\n", getenv("QUERY_STRING"));
	}
	else
	{
		// POST method
		// Read STDIN to get data
		int iLength = atoi(getenv("CONTENT_LENGTH"));
		printf("This is POST METHOD!\n");
		// printf("input data is:\n");

		// int l = read(0, buffer, iLength);
		// printf("l: %d\n", l);

		for(int i = 0; i < iLength; i++)
			putchar(getchar());
	}
}
