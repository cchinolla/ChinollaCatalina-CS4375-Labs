#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

void find(chaar *path, char *filename){//recursive
	char *p;
	char buf[512];
	struct stat st;
	int f;

	if(f = open(path, 0)) < 0){
	print
	}

}

char* findfile(char *path){//recursive call
	static char buf[DIRSIZ+1];//size of file
	char *p;

	//find first character after last slash.
	for(p = path+strlen(path); p>= path && *p != '/'; p--);
	p++;
}
