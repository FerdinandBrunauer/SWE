#define _CRT_SECURE_NO_WARNINGS // Disable warning when using "unsafe" functions
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Please provide as first argument the File ...\n");

		getch();
		return -1;
	}

	struct stat file_stats;
	if ((stat(argv[1], &file_stats)) == -1)
	{
		printf("Failed to read information from file %s", argv[1]);
		getch();
		return 1;
	}

	printf("filename: %s\n", argv[1]);
	printf(" device: %lld\n", file_stats.st_dev);
	printf(" inode: %ld\n", file_stats.st_ino);
	printf(" protection: %o\n", file_stats.st_mode);
	printf(" number of hard links: %d\n", file_stats.st_nlink);
	printf(" user ID of owner: %d\n", file_stats.st_uid);
	printf(" group ID of owner: %d\n", file_stats.st_gid);
	printf(" device type (if inode device): %lld\n", file_stats.st_rdev);
	printf(" total size, in bytes: %ld\n", file_stats.st_size);
	printf(" time of last access: %ld : %s", file_stats.st_atime, ctime(&file_stats.st_atime));
	printf(" time of last modification: %ld : %s", file_stats.st_mtime, ctime(&file_stats.st_mtime));
	printf(" time of last change: %ld : %s", file_stats.st_ctime, ctime(&file_stats.st_ctime));

	getch();
	return 0;
}
