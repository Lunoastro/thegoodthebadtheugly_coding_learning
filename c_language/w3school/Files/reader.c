#include <stdio.h> 

int main() {
    FILE *fp;
    char ch;
    char myString[100];
    fp = fopen("file.txt", "r");
    fgets(myString, 100, fp); // reads the first 100 characters from the file and stores it in myString (only the first line)
    printf("%s", myString); 

    if (fp == NULL) {
        printf("File not found\n");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF) { // EOF: End of file
        printf("%c", ch); 
    }
    fclose(fp);
    return 0;
    
}
