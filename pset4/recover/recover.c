/*Pseudocode
*******Steps to implement this program
****Required to restore deleted JPEG files from Camera
*********************************************************
1. Check that the user provides exactly one command-line argument
2. Open the file and if invalid, print error
3. Declare variables / files that we need for the next step
4. Iterate over a copy of the memory card in blocks of 512 bytes and if wer detect the start of the JPED
   - Create the filename
   - Open the file for us to write into
   - Track the number of images that we have created so far
   - Check that the file we have opened has not been used. If it has not, we will write our newely-found JPEG into this file
5. To end, close off all files
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Step 1
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    //Step 2
    // *input_file is a file pointer to keep track of the location of the file
    //argv[1] refers to the file (which the user inputs)
    //r -> refers to the mode (what are we gonna do with the file) in this case: r -> opens file for "reading"
    FILE *input_file = fopen(argv[1], "r");

    //Checking the input file is valid
    if (input_file == NULL)
    {
        printf("ERROR\n");
        return 2;
    }

    //Step 3
    //Store blocks of 512 bytes in an array
    unsigned char buffer[512];

    //Track number of images generated
    int image_count = 0;

    //File pointer for recovered images
    FILE *output_file = NULL;

    //char filename[8]
    char *filename = malloc(8 * sizeof(char));

    //Step 4
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //Check if byes indicate start of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)


    //Step 5
    sprintf(filename, "%03i.jpg", image_count);
    output_file = fopen(filename, "w");
    image_count++;

    if (output_file != NULL)
    {
        fwrite(buffer, sizeof(char), 512, output_file);
    }
    }
    //Step 6
    free(filename);
    fclose(input_file);
    fclose(output_file);
    return 0;
}