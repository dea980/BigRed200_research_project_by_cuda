// demo of getting file status
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    char *path = "./README";
    struct stat f_info;

    if (argc > 1)
        path = argv[1];
    
    if (lstat(path, &f_info) == -1 ) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("File type: ");

    switch (f_info.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break; 
    }

    printf("owner UID: %u\n", f_info.st_uid);

    printf("File size (bytes): %lld\n", f_info.st_size);

    printf("Last modified: %s\n", ctime(&f_info.st_mtimespec.tv_sec));

}