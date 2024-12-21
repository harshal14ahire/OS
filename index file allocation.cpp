#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_BLOCKS 1000// define max block max files
#define MAX_FILES 100
// define structure 
typedef struct 
{//block no anmd pointer
    int block_num;
    int *blocks;
} DirectoryEntry;

// fundtion to instiqalised bit vector
void initialize_bit_vector(int bit_vector[], int n)
 {
   /// srand(time(NULL));
    for (int i = 0; i < n; i++)
	 {
        bit_vector[i] = rand() % 2;// int range 0and 1;
    }
}

// show bit vector 
void show_bit_vector(int bit_vector[], int n)
 {
    printf("Bit Vector: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", bit_vector[i]);
    }
    printf("\n");
}
// create file function takes :=Directory structure[], bit vector, n, *noof files
void create_new_file(DirectoryEntry directory[], int bit_vector[], int n, int *num_files)
 {
    // declare file name and  how many blocks you want to alloctetr
    
	char file_name[50];
    int num_blocks;
  
    printf("Enter file name: ");
    scanf("%s", file_name);

    printf("Enter number of blocks to allocate: ");
    scanf("%d", &num_blocks);

    // Find free blocks  declare  aray to store index of free bit vector
    int allocated_blocks[num_blocks];
    // intialiswed array count to 0
    int count = 0;
    for (int i = 0; i < n && count < num_blocks; i++)
	 {
        if (bit_vector[i] == 0) 
		{  bit_vector[i]=1;
             allocated_blocks[count++] = i;
        }
    }

    // Add directory entry
    directory[*num_files].block_num = 	num_blocks;// add dir number of blocks allocated
    directory[*num_files].blocks = (int *)malloc(num_blocks * sizeof(int));
    
    for (int i = 0; i < num_blocks; i++)
	 {
        directory[*num_files].blocks[i] = allocated_blocks[i];
    }
      (*num_files)++;// increament n of file allocated
      
    printf("File '%s' created successfully.\n", file_name);// print file created succfullly
}

void show_directory(DirectoryEntry directory[], int num_files)
 {
    printf("Directory:\n");
    for (int i = 0; i < num_files; i++) 
	{
        printf("File: %d, Blocks: ", i + 1);
        for (int j = 0; j < directory[i].block_num; j++) 
		{
            printf("%d ", directory[i].blocks[j]);
        }
        printf("\n");
    }
}

void delete_file(DirectoryEntry directory[], int bit_vector[], int *num_files)
 {
    char file_name[50];
    printf("Enter file name to delete: ");
    scanf("%s", file_name);

    for (int i = 0; i < *num_files; i++)
	 {
        if (strcmp(file_name, "File") == 0)
		 {
            // Free blocks
            for (int j = 0; j < directory[i].block_num; j++)
			 {
                bit_vector[directory[i].blocks[j]] = 0;
            }
            // Remove entry from directory
            for (int j = i; j < *num_files - 1; j++) 
			{
                directory[j] = directory[j + 1];
            }
            (*num_files)--;
            printf("File '%s' deleted successfully.\n", file_name);
            return;
        }
    }
    printf("File not found.\n");
}

int main() {
    int n;
    printf("Enter the number of blocks on the disk: ");
    scanf("%d", &n);

    int bit_vector[MAX_BLOCKS];
    initialize_bit_vector(bit_vector, n);

    DirectoryEntry directory[MAX_FILES];
    int num_files = 0;

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
                show_bit_vector(bit_vector, n);
                break;
            case 2:
                create_new_file(directory, bit_vector, n, &num_files);
                break;
            case 3:
                show_directory(directory, num_files);
                break;
            case 4:
                delete_file(directory, bit_vector, &num_files);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

