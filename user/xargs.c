#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"

int main(int argc, char *argv[]){
	char buf[512];
	char *exec_argv[MAXARG] = {0};//declare argv array
	int argv_index = 0;
	int buf_index = 0;
	int length = 0;

	for(int i = 1; i<argc; i++){//for length of argc
		exec_argv[argv_index++] = argv[i];
	}

	while(1){
		int index = buf_index;//set index to buffer index
		while(1){
			length = read(0, &buf[buf_index], 1);//read
			if(length == 0){
				buf[buf_index] = 0;
				break;
			}
			buf_index++;
		}
		if(length == 0){
			break;
		}
		if(buf_index == index){
			continue;
		}
		buf[buf_index++] = 0;
		exec_argv[argv_index++] = buf + index;
	}
	if(fork() == 0){
		exec(argv[1], exec_argv);
		exit(0);
	}else{
		wait(0);
	}
	exit(0);

}
