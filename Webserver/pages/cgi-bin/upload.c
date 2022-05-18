#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int logIt(char *msg){
	FILE	*fp;

	if (!(fp = fopen("/Users/robert_zin/Documents/42Cursus/14_webserv/webserv/pages/cgi-bin/upload.log", "a")))
		return (0);
	fprintf(fp,"%s\n",msg);
	fclose(fp);

	return (-1);
}//end logIt function


int main(void) {
	FILE *fp;
	char *request_method;
	char *content_length;
	char *content_type;
	char *boundary, *pchar;
	char *pschar, *pechar;
	char *delim = "\r\n";
	char *datastart = "\r\n\r\n";

	int data_len, data_read, i,found;
	char *buffer;
	char msg[1024];



	printf("Content-type: text/html\n\n");
	printf("Here's the beginning...\n");
	logIt("Beginning");


	request_method = getenv("REQUEST_METHOD");
	content_length = getenv("CONTENT_LENGTH");
	content_type = getenv("CONTENT_TYPE");

	memset(msg,'\0',1024);
	sprintf(msg,"request_method=[%s]",request_method);
	logIt(msg);

	memset(msg,'\0',1024);
	sprintf(msg,"content_length=[%s]",content_length);
	logIt(msg);

	memset(msg,'\0',1024);
	sprintf(msg,"content_type=[%s]",content_type);
	logIt(msg);

	if(request_method == NULL){
			logIt("Unknown cgi-bin request");
			printf("<center>Error: Unknown cgi-bin request</center>\n");
			printf("</html>\n");
			return 1;
	} //end if request_method


	/* This only handles POST */
	if(strcmp(request_method, "POST") != 0){
			logIt("Error: request method not supported");
			printf("<center>Error: %s request method not supported</center>\n", request_method);
			printf("</html>\n");
			return 1;
	} //end if strcmp


	printf("<p>REQUEST_METHOD = %s</p>\n", request_method);
	printf("<p>CONTENT_LENGTH = %s</p>\n", content_length);
	printf("<p>CONTENT_TYPE = %s</p>\n", content_type);



	/* The total length of what the client sent upstream */
	data_len = atoi(content_length);



	/*
		Make a space to hold all of the data.  If large uploads are expected
					and memory is limited, this should be done in blocks rather than all
					at once
				*/
	logIt("about to allocate memory");
	buffer = (char *)malloc(data_len);

	logIt("about to fread the file");
	data_read = fread((void *)buffer, 1, data_len, stdin);

	printf("<p>Read %d bytes (of %d) from stdin</p>\n", data_read, data_len);
	sprintf(msg,"Read %d bytes of %d from stdin...",data_read,data_len);




	/* Get the boundary marker for start/end of the data */
	pchar = strtok(buffer, delim);
	boundary = strdup(buffer);
	printf("pchar: %s ", pchar);
	printf("boundary: %s ", boundary);
	logIt("Got boundary");


	/* Find the data start */
	pschar = strstr(buffer+strlen(boundary)+1, datastart);
	printf("buffer: %s ", buffer+strlen(boundary)+1);
	printf("datastart: %s ", datastart);



	if(pschar == NULL){
			logIt("Error - Bad Data Start 1");
			printf("<p>ERROR - BAD DATA START</p>\n");
			for(i=0; i<10; i++){
				printf("%c ", *(buffer+strlen(boundary)+i));
			} //end for i
			return 1;
	} //end if pschar

	/* Move the pointer past the end of headers marker */
	pschar+=strlen(datastart);

	/* Find the data end */
				/* Can't use strstr here as the data may be binary */
	found = 0;
	for(pchar=pschar; pchar < buffer+data_len-strlen(boundary); pchar++){
			if(memcmp(pchar, boundary, strlen(boundary)) == 0){
				found = 1;
				break;
			} //end if memcmp
	} //end for pchar

	if(found == 1){
			pechar = pchar;
	} else{
			logIt("Error - Bad Data End 1 ");
			printf("<p>ERROR - BAD DATA END</p>\n");
			free(boundary);
			free(buffer);
			return 1;
	} //end if found

	/* Write the data to a file */
	logIt("about to open myfile");
	fp = fopen("c:\\inetpub\\scripts\\upload\\myfile", "w");
	if(fp == NULL){
			logIt("Could not open file");
			printf("<p>Error opening output file for write</p>\n");
	} else{
			logIt("about to write file");
			fwrite(pschar, 1, pechar-pschar, fp);
			fclose(fp);
			printf("<p>Data Written to file</p>\n");
			logIt("File written");
	} //end if fp

	free(boundary);
	free(buffer);


	logIt("Done...");
	printf("</html>\n");
}//end main
