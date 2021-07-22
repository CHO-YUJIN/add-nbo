#include <stdint.h>
#include <netinet/in.h>
#include <cstdio>
#include <stdlib.h>

uint32_t readfile(char* filename){
    FILE * file = fopen(filename, "rb");
    uint32_t f;
    size_t readlen = fread(&f, 1, sizeof(uint32_t), file);
    if(readlen != sizeof(uint32_t)) {
        fprintf(stderr, "fread return %lu\n", readlen);
        exit(-1);
    }
    f = ntohl(f);
    fclose(file);
    return f;
}

int main(int argc, char *argv[]) {


    if(argc != 3) {
        printf("syntax : add-nbo <file1> <file2>\n");
        printf("sample : add-nbo a.bin c.bin\n");

        return -1;
    }

    uint32_t file1, file2;
    file1 = readfile(argv[1]);
    file2 = readfile(argv[2]);

    uint32_t result = file1 + file2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", file1, file1, file2, file2, result, result);
}
