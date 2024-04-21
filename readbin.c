#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    const char *disk_file = "disk_sim";
    FILE *disk = fopen(disk_file, "rb");
    if (disk == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int address;

    
    for (int i = 0; i < 512; i++) {
        if (fread(&address, sizeof(address), 1, disk) == 1) {
            printf("Byte %d: %u\n", i, address);
        } else {
            perror("Error reading file");
            fclose(disk);
            return EXIT_FAILURE;
        }
    }

    fclose(disk);
    return EXIT_SUCCESS;

}