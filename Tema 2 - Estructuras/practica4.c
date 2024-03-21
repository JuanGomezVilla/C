#include <stdio.h>

union bswap32 {
    int data;
    char bytes[4];
};

void main(){
    union bswap32 checker;
    checker.data = 1;
    printf("RESULTADO: %s\n", checker.bytes[0] ? "LittleEndian" : "BigEndian");
}