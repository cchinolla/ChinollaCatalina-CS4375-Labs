#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int 
main(int argc, char *argv[])//argc starts at 2, &
			//  # of  specified ticks
{
	//code goes here
	if(argc != 2){//making sure theres an valid input
		printf("error");//error message
		exit(0);//exit
	}
	int num_tick = atoi(argv[1]);//atoi to convert string to int
	sleep(num_tick);//call sleep
	exit(0);
}
