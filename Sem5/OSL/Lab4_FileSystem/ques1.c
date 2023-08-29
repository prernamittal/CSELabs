#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int main (int argc, char *argv[]) {
struct stat sb;
int ret;
ret = stat(argv[1], &sb);
if (ret) {
perror ("stat");
return 1;
}
printf("\nINO NUM: %ld", sb.st_ino);
return 0;
}