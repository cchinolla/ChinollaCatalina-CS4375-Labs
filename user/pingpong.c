#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[]){
	int p1[2];
	int p2[2];
	pipe(p1);
	pipe(p2);
	if (fork() == 0){//if child 
	char buf[10];
		read(p1[0], buf, sizeof(buf));//read
		printf("%d: received ping\n", getpid());//get new id
		close(p1[0]);//close read
		write(p2[1], "c", 1);//write
		close(p2[1]);//close write
	}else{
		char buf[10];
		write(p1[1], "c", 1);//write
		close(p1[1]);//close write
		read(p2[0], buf, sizeof(buf));//read
		printf("%d: received pong\n", getpid());//get pid
		close(p2[0]);//close read
	}
	exit(0);
}

