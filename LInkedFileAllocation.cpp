
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define MAX_BLOCKS 100
#define MAX_FILES 10

// Define the structure for a block
typedef struct Block {
    int block_num;
    struct Block *next;			// defined structure for linked file (Linked LIst:)
} Block;

// Define the structure for a directory entry
typedef struct {
    char filename[50];   // dir stucture for file Name And Starting Block Of File(First Pointer
    Block *start;
} DirectoryEntry;

// Global variables
DirectoryEntry directory[MAX_FILES];// create dir array of structute 
int num_files = 0;//first files=0
int bit_vector[MAX_BLOCKS];//declare vit vector 

// Function to initialize the bit vector randomly
void initialize_bit_vector(int n) {
    //srand(time(NULL));//set srandom time to Null
    for (int i = 0; i < n; i++) {
        bit_vector[i] = rand() % 2;//allocate some blocks of bv 
    }
}
void showBV(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t",bit_vector[i]);
	}
	printf("\n");
}

// Function to create a new file
void create_file(char *filename, int num_blocks)// create file with file name and no of blocks to allocated
 {
    if (num_files >= MAX_FILES) {
        printf("Directory is full. Cannot create more files.\n");
        return;//check if all file are allocated to 
    }

    // Find free blocks
    int allocated_blocks[num_blocks];// find n free blocks from bv and store that free block index in new allocated array
    int count = 0;
    for (int i = 0; i < MAX_BLOCKS && count < num_blocks; i++)
	 {
        if (bit_vector[i] == 0) 
		{
            bit_vector[i] = 1;
            allocated_blocks[count++] = i;
        }
    }

    // Create blocks
    Block *first_block = NULL;// initially first block is set to null  empty linked list
    for (int i = 0; i < num_blocks; i++)// create n block to linked and allcate file
	{
        Block *new_block = (Block *)malloc(sizeof(Block));// create block to allocate 
        new_block->block_num = allocated_blocks[i];// set block no in block Structure of allocated block
        new_block->next = NULL;// set next to pointer to Null

        if (first_block == NULL)//check first block is empty or not 
		 {
            directory[num_files].start = new_block;//add pointer to directory in block
            first_block = new_block;// stor first block new Block
        } else 
		{
            first_block->next = new_block;// add block to next 
            first_block = new_block;// rename firstblock to new Blok
        }
    }

    // Update directory entry
    strcpy(directory[num_files].filename, filename);// add file name in directory
    num_files++;// increment no of file are allocated 
    printf("File '%s' created successfully.\n", filename);
}

// Function to delete a file
void delete_file(char *filename) //
{
    int file_index = -1;
    // Find the index of the file in the directory 
    for (int i = 0; i < num_files; i++) 
	{
        if (strcmp(directory[i].filename, filename) == 0)			// traverse directory and check file is present thent get index of that Dir[i]
		 {
            file_index = i;
            break;
        }
    }
    // If file not found
    if (file_index == -1)/
	 {
        printf("File not found.\n");
        return;
    }
    // Free the blocks allocated to the file
    // set curr_block to dir[].start;
    Block *curr_block = directory[file_index].start;	//det Starting Block of Dir[i].start;
    while (curr_block != NULL) 							//  traverse block 
	{
        bit_vector[curr_block->block_num] = 0;			// free bitvector=0
        Block *temp = curr_block;						// create Temp Block and Store CurrentBlock
        curr_block = curr_block->next;					// Traverse Linked List 
        free(temp);										 //free Memory
    }
    // Remove entry from the directory
    for (int i = file_index; i < num_files - 1; i++)
	 {
        directory[i] = directory[i + 1];
    }
    num_files--;
    printf("File '%s' deleted successfully.\n", filename);
}

// Function to display the directory
void show_directory()
 {
    printf("Directory:\n");
    for (int i = 0; i < num_files; i++)
    {
       			 printf("File: %s, Blocks: ", directory[i].filename);
       			 Block *curr_block = directory[i].start;
       			 	while (curr_block != NULL) 
					{
         		  	 		printf("%d ", curr_block->block_num);
          					  curr_block = curr_block->next;
       				}
        printf("\n");
    }
}

int main() {
    int num_blocks;
    printf("Enter the number of blocks on the disk: ");
    scanf("%d", &num_blocks);


    initialize_bit_vector(num_blocks);

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
           case 1:showBV(num_blocks);
           	break;
		   
		    case 2:
                if (num_files >= MAX_FILES) {
                    printf("Directory is full. Cannot create more files.\n");
                    break;
                }
                char filename[50];
                printf("Enter file name: ");
                scanf("%s", filename);
                int num_blocks;
                printf("Enter number of blocks to allocate to the file: ");
                scanf("%d", &num_blocks);
                create_file(filename, num_blocks);
                break;
            case 3:
                show_directory();
                break;
           
                case 4:
    char filename_to_delete[50];
    printf("Enter the name of the file to delete: ");
    scanf("%s", filename_to_delete);
    delete_file(filename_to_delete);
    break;

          case 5:
                printf("Exiting...\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

