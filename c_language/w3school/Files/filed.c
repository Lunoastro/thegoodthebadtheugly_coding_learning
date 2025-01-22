#include <stdio.h> 
#include <string.h>
FILE *filePointer; // the pointer can be understood as a reference to the file
int main()
{
    char dataToBeWritten[50] = "Hello, World!";
    filePointer = fopen("file.txt", "w"); // w is for write mode // r is for read mode // a is for append mode
    // warning w mode will overwrite file content if the file already exists
    if (filePointer == NULL)
    {
        printf("File failed to open\n");
    }
    else
    {
        printf("The file is now opened.\n");
        if (strlen(dataToBeWritten) > 0)
        {
            fprintf(filePointer, "%s\n", dataToBeWritten); 
            fputs(dataToBeWritten, filePointer);
            fputs("\n", filePointer); 
            // don't really get the difference between fprintf and fputs but eh both work
        }
        fclose(filePointer); //closing the file to prevent memory leaks (w3school: Clean up unnecessary memory space)
        // also other programs can access the file now
        printf("Data successfully written in file.txt\n");
        printf("The file is now closed.\n");
    }
    return 0;
}