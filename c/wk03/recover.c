#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image");
        return 1;
    }

    char *rawFile = argv[1];
    // Open raw
    FILE *raw = fopen(rawFile, "r");
    if (raw == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", rawFile);
        return 2;
    }

    unsigned char buffer[512];
    int block = 0;
    int imgCount = 0;
    char filename[8];
    FILE *img = 0;
    // Loop through raw
    do
    {
        block = fread(&buffer, 512, 1, raw);
        // If EOF - close raw and image
        if (block != 1)
        {
            fclose(img);
            fclose(raw);

            return 0;
        }
        // If block starts with JPEG header - create a file
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Close file before creaing a new one
            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", imgCount);
            img = fopen(filename, "w");
            // Write block with header info
            fwrite(&buffer, 512, 1, img);
            // Add to image counter
            imgCount++;
        }
        // If file is open - write block
        else
        {
            if (img != NULL)
            {
                fwrite(&buffer, 512, 1, img);
            }
        }
    }
    while (1);
}