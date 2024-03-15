//COMMAND: compile ejercicio1.c && ejercicio 3

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structure for a bomb
typedef struct Bomb {
    int x; //Coordinates on the X axis
    int y; //Coordinates on the Y axis
} Bomb;

//Structure for an attempt
typedef struct Attempt {
    int x;                  //Coordinates on the X axis of the launch
    int y;                  //Coordinates on the Y axis of the launch
    int bombInRow;          //The bomb is in that row
    int bombInColumn;       //The bomb is in that column
    int bombFound;          //The bomb has been found
} Attempt;

//Structure for multiple attempts
typedef struct Attempts {
    Attempt* list;          //Array list with the attempts
    int amount;             //Number of attempts
} Attempts;

//OPTIONS
enum Options {
    SEARCH_BOMB = 1,
    WATCH_BOARD = 2,
    WATCH_ATTEMPTS = 3,
    EXIT = 4
};

//Elements of the board
enum Elements {
    INCOGNITO = '?',
    WATER = 'O',
    BOMB = 'X'
};

//GLOBAL ACCESS
//Number of cells, indicated by the user in the console parameter; attemps and board
int amountCells;
Attempts attempts;
char** board;

/*
    Method to generate a random number
*/
int getRandomInteger(int min, int max){
    return min + rand() % (max - min + 1);
}

/*
    Method to create a matrix initially with a number of rows and columns
*/
char** createBoard(int amountRowColumns){
    //Reserve memory for rows and then columns
    char** board = (char**) malloc(amountRowColumns * sizeof(char *));
    for(int i=0; i<amountRowColumns; i++) board[i] = (char*) malloc(amountRowColumns * sizeof(char));

    //Returns the resulting array
    return board;
}

/*
    Method to fill a given array and fill value
*/
void fillBoard(char** board, char value){
    //Loop through the array adding the values
    for(int y=0; y<amountCells; y++){
        for(int x=0; x<amountCells; x++){
            board[y][x] = value;
        }
    }
}

/*
    Method to create an attempt
*/
Attempt createAttempt(){
    //Creating a temporary attempt and setting the initial default values ​​to 0
    Attempt temporalAttempt;
    temporalAttempt.bombInColumn = 0;
    temporalAttempt.bombInRow = 0;
    temporalAttempt.bombFound = 0;

    //The user writes some coordinates, and they travel to the numbers
    scanf("%d %d", &temporalAttempt.y, &temporalAttempt.x);

    //Returns the temporary attempt
    return temporalAttempt;
}

/*
    Method to check an attempt
*/
void checkAttempt(char*** board, Attempt* attemp, Bomb bomb){
    //Set the data
    attemp->bombInColumn = (bomb.x == attemp->x);
    attemp->bombInRow = (bomb.y == attemp->y);
    attemp->bombFound = (bomb.y == attemp->y && bomb.x == attemp->x);

    //If the bomb has been found
    if(attemp->bombFound){
        printf("Bomb found at (x, y) = (%i, %i)\n", bomb.x, bomb.y);
        (*board)[attemp->y][attemp->x] = BOMB;
        
        //Show the final result on the screen
        for(int y=0; y<amountCells; y++){
            for(int x=0; x<amountCells; x++){
                printf("%c", (*board)[y][x]);
            }
            printf("\n");
        }

        //End of program
        free(board);
        free(attempts.list);
        exit(1);
    //If bomb in row
    } else if(attemp->bombInRow){
        printf("The bomb is in that row...\n");
    
    //If bomb in column
    } else if(attemp->bombInColumn){
        printf("The bomb is in that column...\n");
    }

    //Indicates the coordinates of the failed attempt
    (*board)[attemp->y][attemp->x] = WATER;
}

/*
    Method to insert a new attempt
*/
void insertAttempt(Attempts* attempts, Attempt attempt){
    //Increases the number of attempts, reserves memory for a new one, and inserts it
    attempts->amount++;
    attempts->list = (Attempt*) realloc(attempts->list, attempts->amount * sizeof(Attempt));
    attempts->list[attempts->amount - 1] = attempt;
}

void main(int argc, char* argv[]){
    //Checks that the user enters at least two arguments (program and size)
    if(argc != 2){
        printf("\nYou must provide the size of the board...\n");
        return;
    }

    //Captures the value, still 0 is not a valid value so it will return an error
    amountCells = strtol(argv[1], NULL, 10);
    if(amountCells == 0){
        printf("\nThe board size cannot be 0 or an invalid data type...\n");
        return;
    }

    //Creates a board and fill it with the incognito character
    board = createBoard(amountCells);
    fillBoard(board, INCOGNITO);

    //Create an attempt structure, save the amount, and then start the attempt list at 0
    attempts.amount = 0;
    attempts.list = (Attempt*) malloc(attempts.amount * sizeof(Attempt));
    
    //Sets the data of a bomb started at the beginning and get its random location
    srand(time(NULL));
    Bomb bomb;
    bomb.x = getRandomInteger(0, amountCells - 1); //Subtract 1 because it counts from 0
    bomb.y = getRandomInteger(0, amountCells - 1);

    //Selected option and menu
    int option = -1;
    while(option != EXIT){
        printf("\n1. Search bomb\n2. Watch board\n3. Watch attempts\n4. Exit\nOPTION: ");
        scanf("%d", &option);

        //Option to search the bomb
        if(option == SEARCH_BOMB){
            printf("\nRow and column (example: 1 2): ");
            Attempt attempt = createAttempt();

            //Check attempts and insert them
            checkAttempt(&board, &attempt, bomb);
            insertAttempt(&attempts, attempt);

        //Option to view the board
        } else if(option == WATCH_BOARD){
            //Print the board on screen
            printf("\n");
            for(int y=0; y<amountCells; y++){
                for(int x=0; x<amountCells; x++){
                    printf("%c", board[y][x]);
                }
                printf("\n"); //Line break between rows
            }
        } else if(option == WATCH_ATTEMPTS){
            //Print the title
            printf("\nATTEMPTS:\n");

            //Loop through the array of attempts with a loop
            for(int i=0; i<attempts.amount; i++){
                //Captures a temporary attempt and displays its data on the screen
                Attempt temporalAttempt = attempts.list[i];
                printf("   Attempt %i -> (x, y) = (%i, %i); In column: %s; In row: %s\n", i+1, temporalAttempt.x, temporalAttempt.y, temporalAttempt.bombInColumn ? "Yes" : "No", temporalAttempt.bombInRow ? "Yes" : "No");
            }
        }
    
    }

    //Memory cleaning
    free(board);            //For the board
    free(attempts.list);    //For the list of attempts
}