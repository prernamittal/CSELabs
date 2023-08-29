#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

const char *perms(__mode_t mode){
	static char buf[16] = {0};
	int i = 0;
	//user permissions
	buf[i++] = ((mode & S_IRUSR) ? 'r' : '-');
	buf[i++] = ((mode & S_IWUSR) ? 'w' : '-');
	buf[i++] = ((mode & S_IXUSR) ? 'x' : '-');
	//group permissions
	buf[i++] = ((mode & S_IRGRP) ? 'r' : '-');
	buf[i++] = ((mode & S_IWGRP) ? 'w' : '-');
	buf[i++] = ((mode & S_IXGRP) ? 'x' : '-');
	//other permissions
	buf[i++] = ((mode & S_IROTH) ? 'r' : '-');
	buf[i++] = ((mode & S_IWOTH) ? 'w' : '-');
	buf[i++] = ((mode & S_IXOTH) ? 'x' : '-');
	return buf;
}

int main (int argc, char *argv[]) {
	struct stat sb;
	int ret;
	ret = stat(argv[1], &sb);
	if (ret) {
	perror ("stat");
	return 1;
	}
	printf("ID: %ld", sb.st_dev);
	printf("\nINO NUM: %ld", sb.st_ino);
	printf("\nPERMISSIONS: %s", perms(sb.st_mode));
	printf("\nHARD DISKS: %ld", sb.st_nlink);
	printf("\nUSER ID: %u", sb.st_uid);
	printf("\nGROUP ID: %u", sb.st_gid);
	printf("\nDEVICE ID: %ld", sb.st_rdev);
	printf("\nSIZE: %ld", sb.st_size);
	printf("\nBLOCK SIZE: %ld", sb.st_blksize);
	printf("\nBLOCKS: %ld", sb.st_blocks);
	printf("\nLAST ACCESS TIME: %s", ctime(&sb.st_atime));
	printf("\nLAST MODIFICATION TIME: %s", ctime(&sb.st_mtime));
	printf("\nLAST STATUS CHANGE TIME: %s", ctime(&sb.st_ctime));
	return 0;
}