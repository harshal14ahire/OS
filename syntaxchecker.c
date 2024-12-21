#include <stdio.h>

#define MAX_LINE_LENGTH 256

int checkSyntax(FILE *file);

int main() {
    FILE *file;
    char filename[50];

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");

    // Check if the file is opened successfully
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1; // Exit with an error code
    }

    // Check the syntax of the file
    if (checkSyntax(file)) {
        printf("Syntax is correct.\n");
    }

    // Close the file
    fclose(file);

    return 0; // Exit successfully
}

int checkSyntax(FILE *file) {
    int openParentheses = 0;
    int closeParentheses = 0;
    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;

    // Read each line from the file
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        lineNumber++;
   int i;
        // Read each character from the line
        for ( i = 0; line[i] != '\0'; i++) {
            char c = line[i];
            if (c == '(') {
                openParentheses++;
            } else if (c == ')') {
                closeParentheses++;

                // Check if closing parentheses are more than opening ones
                if (closeParentheses > openParentheses) {
                    printf("Syntax error on line %d: Extra closing parenthesis\n", lineNumber);
                    printf("%s", line);  // Print the problematic line
                    int j;
					// Highlight the problematic position
                    for ( j = 0; j < i; j++) {
                        printf(" ");
                    }
                    printf("^\n");
                    return 0; // Syntax error
                }
            }
        }
    }

    // Check if the number of opening and closing parentheses is equal
    if (openParentheses == closeParentheses) {
        return 1; // Syntax is correct
    } else {
        printf("Syntax error: Missing closing parenthesis\n");
        return 0; // Syntax error
    }
}
