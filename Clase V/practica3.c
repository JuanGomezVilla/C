#include <stdio.h>

//Color enumeration
typedef enum {
    YELLOW,
    GREEN,
    BROWN
} Color;

//Leaf structure
typedef struct Leaf {
    float size;
    float thickness;
    Color color;
} leafData;

void main(){
    //Creates a leaf
    struct Leaf leaf;

    //Set the value of the variables
    leaf.size = 20.10;
    leaf.thickness = 2.0;
    leaf.color = GREEN;

    //Result
    printf("LEAF DATA -> color:%i, size:%.2f, thickness:%.2f\n", leaf.color, leaf.size, leaf.thickness);
}