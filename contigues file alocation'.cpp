#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BLOCKS 100

// Directory entry structure
struct DirectoryEntry {
    char fileName[50];
    int startBlock;
    int length;
};

// Bit vector to represent free/allocated blocks
int bitVector[MAX_BLOCKS];

// Directory to store file details
struct DirectoryEntry directory[MAX_BLOCKS];

// Number of blocks on disk
int numBlocks;

// Function prototypes
void showBitVector();
void createNewFile();
void showDirectory();
void deleteFile();
void initializeBitVector();
int findContiguousBlocks(int numBlocksRequested);

int main() {
    printf("Enter the number of blocks on disk: ");
    scanf("%d", &numBlocks);

    // Initialize random seed
    srand(time(NULL));

    // Initialize bit vector
    initializeBitVector();

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Show Bit Vector\n");
        printf("2. Create New File\n");
        printf("3. Show Directory\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showBitVector();
                break;
            case 2:
                createNewFile();
                break;
            case 3:
                showDirectory();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display the bit vector
void showBitVector() {
    printf("\nBit Vector:\n");
    for (int i = 0; i < numBlocks; ++i) {
        printf("%d ", bitVector[i]);
    }
    printf("\n");
}

// Function to create a new file
void createNewFile() {
    char fileName[50];
    printf("\nEnter file name: ");
    scanf("%s", fileName);

    int numBlocksRequested;
    printf("Enter number of blocks to allocate: ");
    scanf("%d", &numBlocksRequested);

    int startBlock = findContiguousBlocks(numBlocksRequested);
    if (startBlock == -1) {
        printf("Error: Not enough contiguous free blocks available.\n");
        return;
    }

    // Update directory entry
    int index;
    for (index = 0; index < MAX_BLOCKS; ++index) {
        if (directory[index].startBlock == -1) {
            break;
        }
    }
    strcpy(directory[index].fileName, fileName);
    directory[index].startBlock = startBlock;
    directory[index].length = numBlocksRequested;

    // Update bit vector
    for (int i = startBlock; i < startBlock + numBlocksRequested; ++i) {
        bitVector[i] = 1;
    }

    printf("File '%s' created successfully.\n", fileName);
}

// Function to show directory
void showDirectory() {
    printf("\nDirectory:\n");
    for (int i = 0; i < MAX_BLOCKS; ++i) {
        if (directory[i].startBlock != -1) {
            printf("File Name: %s, Start Block: %d, Length: %d\n", directory[i].fileName, directory[i].startBlock, directory[i].length);
        }
    }
}

// Function to delete a file
void deleteFile() {
    char fileName[50];
    printf("\nEnter file name to delete: ");
    scanf("%s", fileName);

    int index;
    for (index = 0; index < MAX_BLOCKS; ++index) {
        if (strcmp(directory[index].fileName, fileName) == 0) {
            break;
        }
    }

    if (index == MAX_BLOCKS) {
        printf("Error: File '%s' not found.\n", fileName);
        return;
    }

    // Update bit vector
    for (int i = directory[index].startBlock; i < directory[index].startBlock + directory[index].length; ++i) {
        bitVector[i] = 0;
    }

    // Clear directory entry
    directory[index].startBlock = -1;

    printf("File '%s' deleted successfully.\n", fileName);
}

// Function to initialize the bit vector randomly
void initializeBitVector() {
    for (int i = 0; i < numBlocks; ++i) {
        bitVector[i] = rand() % 2;
    }
}

// Function to find contiguous free blocks
int findContiguousBlocks(int numBlocksRequested) {
    int startBlock = -1;
    int count = 0;

    for (int i = 0; i < numBlocks; ++i) {
        if (bitVector[i] == 0) {
            if (startBlock == -1) {
                startBlock = i;
            }
            count++;
            if (count == numBlocksRequested) {
                return startBlock;
            }
        } else {
            startBlock = -1;
            count = 0;
        }
    }

    return -1;
}

