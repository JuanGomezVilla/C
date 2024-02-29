#include <stdio.h>

enum Seasons {
    SPRING = 4,
    SUMMER = 3,
    AUTUMN = 2,
    WINTER = 1
};

void main(){
    printf("Spring -> %d\n", SPRING);
    printf("Summer -> %d\n", SUMMER);
    printf("Autumn -> %d\n", AUTUMN);
    printf("Winter -> %d\n", WINTER);
}