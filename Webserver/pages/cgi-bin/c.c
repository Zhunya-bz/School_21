#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    fprintf(stdout, "\r\n\r\n");
    fprintf(stdout,"Sounds good! Your %s\n", getenv("QUERY_STRING"));
}
