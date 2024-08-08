#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef enum
{
	FALSE,
	TRUE
}bool;

int main(int argc, char **argv)
{
	bool test = 15;
	if (test == 1)
		printf("true");
	else if (test == 0)
		printf("flase");
	else
		printf("no");

  return 0;
    
}