#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAXPATH 256

int list_dir(char * dir, int rec)
{
	DIR * dirp;
	char path[MAXPATH];
	struct dirent * direntp;
	struct stat st;
	
	/* Here you should open the directory indicated by the given path */
	 if ((dirp = opendir(dir)) == NULL)
    {
        perror(dir);
        return -1;
    }

	/* loop through the directory and prints the information about the included files */
	/* check function readdir and stat */
    while ((direntp = readdir(dirp)) != NULL) {
        if (strcmp(direntp->d_name, ".") != 0 && strcmp(direntp->d_name, "..") != 0)
        {
            snprintf(path, sizeof(path), "%s/%s", dir, direntp->d_name);
            if (stat(path, &st) == -1)
            {
                perror(path);
                continue;
            }

            /* If it's a directory and recursive option is enabled, list its contents recursively */
            if (S_ISDIR(st.st_mode) && rec)
            {
                printf("Directory: %s\n", path); // Print directory name before listing contents
                list_dir(path, rec); // Recursive call to list contents of subdirectory
            }
            else
            {
                /* Print file information */
                printf("%-40s", direntp->d_name);
                printf(" %10ld", st.st_size);
                // Print last modified time
                printf(" %s", ctime(&st.st_mtime)); 
            }
        }
    }
	
	/* closing is already given here, but remember to do it yourself in the future :) */
	if (closedir(dirp) == -1) {
		perror(dir);
		return -1;
	}
	
	return 0;
}

int main(int argc, char * * argv)
{
	int i = 1, rec = 0;
	
	if (argc > 1) {
		if (strcmp(argv[i], "-r") == 0) {
			rec = 1;
			i++;
		}
	}
		
	while (i < argc) {
		if (list_dir(argv[i], rec) == -1) exit(1);
		i++;
	}
		
	return 0;
}