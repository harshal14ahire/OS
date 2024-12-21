#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void search(char mode, char *filename, char *pattern) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, pattern) != NULL)
	   {
            if (mode == 'f')
			 {
                printf("%s", line);
                fclose(file);
                return;
            } 
			else if (mode == 'a')
			 {
                printf("%s", line);
            }
            count++;
        }
    }

    fclose(file);

    if (mode == 'c') {
        printf("Count: %d\n", count);
    } else if (count == 0) {
        printf("Pattern not found.\n");
    }
}

int main() {
    char command[80], t1[20], t2[20], t3[20], t4[20], t5[20];

    system("clear");

    while (1) {
        printf("MYshell#");
        fflush(stdin);
        fgets(command, 80, stdin);

        int n = sscanf(command, "%s%s%s%s%s", t1, t2, t3, t4, t5);

        switch (n) {
            case 1:
                if (!fork()) {
                    execlp(t1, NULL);
                    perror(t1);
                }
                break;

            case 2:
                if (!fork()) {
                    execlp(t1, t2, NULL);
                    perror(t1);
                }
                break;

            case 3:
                if (!fork()) {
                    execlp(t1, t2, t3, NULL);
                    perror(t1);
                }
                break;

            case 4:
                if (strcmp(t1, "search") == 0) {
                    search(t2[0], t3, t4);
                } else {
                    if (!fork()) {
                        execlp(t1, t2, t3, t4, NULL);
                    }
                }
                break;

            case 5:
                if (!fork()) {
                    execlp(t1, t2, t3, t4, t5, NULL);
                    perror(t1);
                }
                break;

            case 6:
                if (strcmp(t1, "q") == 0) {
                    exit(0);
                }
                break;

            case 0:
                exit(0);
        }
    }
    return 0;
}
