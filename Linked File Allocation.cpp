#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#define MAX_BLOCKS 100


// Structure for disk block
struct DiskBlock
 {
    bool isAllocated;
    char fileName[50];
    struct DiskBlock *next;
};

// Directory entry structure
struct DirectoryEntry
 {
    char fileName[50];
    struct DiskBlock *startBlock;
    int length;
};

// Directory to store file details
struct DirectoryEntry directory[MAX_BLOCKS];

// Function prototypes
void showBitVector();
void createNewFile();
void showDirectory();
void deleteFile();
void initializeDisk( int );
struct DiskBlock * findFreeBlock();
struct DiskBlock * findLastBlock();
struct DiskBlock * findBlockByName(char * fileName);


int main() 
{
    int numBlocks;
    printf("Enter the number of blocks on disk: ");
    scanf("%d", &numBlocks);

    // Initialize disk
    initializeDisk(numBlocks);
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

        switch (choice) 
		{
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
void showBitVector() 
{ int i;
    printf("\nBit Vector:\n");
    for ( i = 0; i < MAX_BLOCKS; ++i) 
	{
        printf("%d ", directory[i].startBlock != NULL ? 1 : 0);
    }
    printf("\n");
}

// Function to create a new file
void createNewFile()
 {
    char fileName[50];
    printf("\nEnter file name: ");
    scanf("%s", fileName);

    int numBlocksRequested;
    printf("Enter number of blocks to allocate: ");
    scanf("%d", &numBlocksRequested);

    // Find free blocks
    struct DiskBlock *startBlock = findFreeBlock();
    if (startBlock == NULL)
	 {
        printf("Error: Not enough free blocks available.\n");
        return;
    }

    // Update directory entry
    int index;
    for (index = 0; index < MAX_BLOCKS; ++index) 
	{
        if (directory[index].startBlock == NULL)
		 {
            break;
        }
    }
    strcpy(directory[index].fileName, fileName);
    directory[index].startBlock = startBlock;
    directory[index].length = numBlocksRequested;

    // Allocate blocks
    struct DiskBlock *currentBlock = startBlock;
    for (int i = 1; i < numBlocksRequested; ++i) 
	{
        struct DiskBlock *newBlock = findFreeBlock();
        if (newBlock == NULL) {
            printf("Error: Not enough free blocks available.\n");
            // Rollback changes if allocation fails
            while (startBlock != NULL)
			 {
                struct DiskBlock *temp = startBlock;
                startBlock = startBlock->next;
                free(temp);
            }
            directory[index].startBlock = NULL;
            return;
        }
        currentBlock->next = newBlock;
        currentBlock = newBlock;
    }

    printf("File '%s' created successfully.\n", fileName);
}

// Function to show directory
void showDirectory()
 { int i;
    printf("\nDirectory:\n");
    for ( i = 0; i < MAX_BLOCKS; ++i)
	 {
        if (directory[i].startBlock != NULL)
		 {
            printf("File Name: %s, Start Block: %p, Length: %d\n", directory[i].fileName, (void *)directory[i].startBlock, directory[i].length);
        }
    }
}

// Function to delete a file
void deleteFile()
 {
    char fileName[50];
    printf("\nEnter file name to delete: ");
    scanf("%s", fileName);

    struct DiskBlock *startBlock = findBlockByName(fileName);
    if (startBlock == NULL) 
	{
        printf("Error: File '%s' not found.\n", fileName);
        return;
    }

    // Update directory entry
    int index;
    for (index = 0; index < MAX_BLOCKS; ++index)
	 {
        if (strcmp(directory[index].fileName, fileName) == 0)
		 {
            break;
        }
    }
    directory[index].startBlock = NULL;
    directory[index].length = 0;

    // Release blocks
    while (startBlock != NULL)
	 {
        struct DiskBlock *temp = startBlock;
        startBlock = startBlock->next;
        free(temp);
    }

    printf("File '%s' deleted successfully.\n", fileName);
}

// Function to initialize the disk
void initializeDisk(int numBlocks) 
{
    // Initialize directory
    int i;
    for ( i = 0; i < MAX_BLOCKS; ++i)
	{
        directory[i].startBlock = NULL;
    }

}

// Function to find a free block
struct DiskBlock* findFreeBlock()
{
	int i;
    for ( i = 0; i < MAX_BLOCKS; ++i)
	 {
        if (directory[i].startBlock == NULL)
		 {
            struct DiskBlock *block = (struct DiskBlock *)malloc(sizeof(struct DiskBlock));
            block->isAllocated = true;
            block->next = NULL;
            return block;
         }
     }
    return NULL;
}

// Function to find the last block in a file
struct DiskBlock* findLastBlock(struct DiskBlock *startBlock) 
{
    struct DiskBlock *currentBlock = startBlock;
    while (currentBlock->next != NULL) 
	{
        currentBlock = currentBlock->next;
    }
    return currentBlock;
}

// Function to find a block by file name
struct DiskBlock* findBlockByName(char *fileName)
{ int i;
    for ( i = 0; i < MAX_BLOCKS; ++i)
	 {
        if (strcmp(directory[i].fileName, fileName) == 0)
		{
            return directory[i].startBlock;
        }
    }
    return NULL;
}

