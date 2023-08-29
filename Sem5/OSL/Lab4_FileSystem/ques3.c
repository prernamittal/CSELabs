#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	char *oldpath = argv[1];
	char *newpath = "newpath.txt";
	struct stat sb;
	if (argc < 2) {
		printf ("insufficient arguments");
		return 0;
	}
	int ret1 = stat (oldpath, &sb);
	if (ret1) {
		perror ("stat");
		return 1;
	}
	printf("Before linking: %ld\n", sb.st_nlink);
	link(oldpath, newpath);
	printf("After linking: \n");
	system("ls");
	int ret2 = stat(newpath, &sb);
	if(ret2 != 0){
		perror("stat");
		return 1;
	}
	printf("After linking: %ld\nNew path: %s\n", sb.st_nlink, newpath);
	unlink(oldpath);
	printf("After unlinking: \n");
	system("ls");
	int ret3 = stat(newpath, &sb);
	if(ret3 != 0){
		perror("stat");
		return 1;
	}
	printf("After unlinking: %ld\n", sb.st_nlink);	
	return 0;
}