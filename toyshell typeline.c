#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h> // Include this for the exit function

void typeline(char *s, char *fn) {
    int handle, n, i = 0, cnt = 0;
    char c;

    if ((handle = open(fn, O_RDONLY)) == -1) {
        printf("\nFile not found\n");
        return;
    }

    if (s[0] == 'a') {
        while (read(handle, &c, 1) != 0)
            printf("%c", c);

        close(handle);
        return;
    }

    n = atoi(s);

    if (n > 0) {
        while (read(handle, &c, 1) != 0) {
            if (c == '\n')
                i++;

            if (i == n)
                break;

            printf("%c", c);
        }
    } else if (n < 0)
	 {
        while (read(handle, &c, 1) != 0) {
            if (c == '\n')
                cnt++;
        }

        lseek(handle, 0, SEEK_SET);

        while (read(handle, &c, 1) != 0) {
            if (c == '\n')
                i++;

            if (i == cnt + n)
                break;
        }

        while (read(handle, &c, 1) != 0)
            printf("%c", c);
    } else {
        printf("Invalid choice for typeline");
    }

    printf("\n");
    close(handle);
}

int main() {
    char command[80], t1[20], t2[20], t3[20], t4[20];
    char n;

    system("clear");

    while (1) {
        printf("MYshell$");
        fflush(stdin);
        fgets(command, 80, stdin);

        n = sscanf(command, "%s%s%s%s", t1, t2, t3, t4);

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
                if (strcmp(t1, "typeline") == 0)
                    typeline(t2, t3);
                else {
                    if (!fork()) {
                        execlp(t1, t2, t3, NULL);
                    }
                }
                break;

            case 4:
                if (!fork()) {
                    execlp(t1, t2, t3, t4, NULL);
                    perror(t1);
                }
                break;

            case 5:
                if (strcmp(t1, "q") == 0) {
                    exit(0);
                }
                break;

            case 0:
                exit(0);
                break;
        }
    }

    return 0;
}
