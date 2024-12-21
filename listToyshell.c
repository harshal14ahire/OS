#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

void list(char mode, char *dirpath) {
    DIR *dir = opendir(dirpath);
    if (dir == NULL) {
        printf("Error opening directory\n");
        return;
    }

    int count = 0;
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (mode == 'f') {
            printf("%s\n", entry->d_name);
        } else if (mode == 'n') {
            count++; // Increment count for each entry
        } else if (mode == 'i') {
            printf("%s %lu\n", entry->d_name, (unsigned long)entry->d_ino);
        }
    }

    if (mode == 'n') {
        // Print the total count after the loop
        printf("Number of entries in directory: %d\n", count);
    }

    closedir(dir);
}

int main() {
    char command[80], t1[20], t2[20], t3[20], t4[20];
    char mode;
    int n;

    while (1) {
        printf("MYshell# ");
        fflush(stdout); // Ensure the prompt is displayed

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break; // Handle EOF
        }

        n = sscanf(command, "%s%s%s%s", t1, t2, t3, t4);

        switch (n) {
            case 1:
                if (!fork()) {
                    execlp(t1, t1, NULL);
                    perror(t1);
                }
                break;

            case 2:
                if (!fork()) {
                    execlp(t1, t1, t2, NULL);
                    perror(t1);
                }
                break;

            case 3:
                if (strcmp(t1, "list") == 0)
                    list(t2[0], t3);
                else {
                    if (!fork()) {
                        execlp(t1, t1, t2, t3, NULL);
                    }
                }
                break;

            case 4:
                if (!fork()) {
                    execlp(t1, t1, t2, t3, t4, NULL);
                    perror(t1);
                }
                break;

            case 5:
                if (strcmp(t1, "q") == 0) {
                    exit(0);
                }

            case 0:
                exit(0);
        }
    }

    return 0;
}
