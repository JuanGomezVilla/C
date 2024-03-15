//COMMAND: run ejercicio2.c

//Libraries
#include <stdio.h>
#include <stdlib.h>

//Menu options
enum Options {
    CREATE_RECORDING = 1,
    CREATE_STATION = 2,
    ASIGN_RECORDING_TO_STATION = 3,
    PRINT_STATIONS_DATA = 4,
    EXIT = 5
};

//Recording formats
enum Formats {
    WAV = 0,
    MP3 = 1,
    OGG = 2
} Formats;

//Structure for a recording
typedef struct Recording {
    char filename[50];
    char date[50];
    int format;
    char station[50];
    int initialized;
} Recording;

//Structure for a station
typedef struct Station {
    char name[50];
    float latitude;
    float longitude;
    int amountRecordings;
    Recording* recordings;
    int initialized;
} Station;

/*
    Method to read a string
*/
char* readString(char* stringVariable){
    //Creates a temporal character and iterator
    char temporalCharacter;
    int iterator = 0;
    
    //As long as the character is different from end of line
    while((temporalCharacter = getchar()) != '\n'){
        //Save the value and increment the iterator
        stringVariable[iterator] = temporalCharacter;
        iterator++;
    }
    //Add a line ending
    stringVariable[iterator] = '\0';
}

/*
    Method to copy a string to a string
    Similar to how strcpy works
*/
void copyString(char *pointerString, char *pointerValue){
    //As long as the content of the value pointer is different from the end
    while(*pointerValue != '\0'){
        //Inserts the value of the other pointer into the pointer
        *pointerString = *pointerValue;

        //Increment both pointers
        pointerString++;
        pointerValue++;
    }

    //Add a line ending
    *pointerString = '\0';
}

/*
    Method to check two strings.
    Similar to how strcmp works
*/
int compareStrings(char *pointerString1, char *pointerString2){
    //Loop that will repeat until reaching the last pointer character
    while(*pointerString1 != '\0' || *pointerString2 != '\0'){
        //If the content of both pointers is different, it returns 0
        if(*pointerString1 != *pointerString2) return 0;

        //Increment both pointers
        pointerString1++;
        pointerString2++;
    }

    //Returns 1 because both values ​​are correct
    return 1;   
}

void main(){
    //Amount of recordings and stations
    int amountRecordings = 0;
    int amountStations = 0;

    //Arrays of recordings and stations
    Recording* recordings = (Recording*) malloc(amountRecordings * sizeof(Recording));
    Station* stations = (Station*) malloc(amountStations * sizeof(Station));

    //Default option and starts the menu
    int option = 1;
    while(option != EXIT){
        //Print menu
        printf("\n1. Create recording file\n2. Create station data\n3. Assign recording to station\n4. Print stations data\n5. Exit\nOPTION: ");
        scanf("%i", &option);
        getchar();

        //Option to create a recording file
        if(option == CREATE_RECORDING){
            //Creates a temporal recording and changes the trigger
            Recording temporalRecording;
            temporalRecording.initialized = 1;
            temporalRecording.station[0] = '\0';

            //The user types data
            printf("\nFilename: ");
            readString(temporalRecording.filename);
            printf("Date (format \"DD/MM/AA\"): ");
            readString(temporalRecording.date);
            printf("Format (WAV -> 0 | MP3 -> 1 | OGG -> 2): ");
            scanf("%d", &temporalRecording.format);

            //Increase the number of recordings and modify the memory to add the recording, then, add the station
            amountRecordings++;
            recordings = (Recording*) realloc(recordings, amountRecordings * sizeof(Recording));
            recordings[amountRecordings-1] = temporalRecording;

        //Option to create a data station
        } else if(option == CREATE_STATION){
            //Creates a temporal station and changes the trigger
            Station temporalStation;
            temporalStation.amountRecordings = 0;
            temporalStation.initialized = 1;
            temporalStation.recordings = (Recording*) malloc(temporalStation.amountRecordings * sizeof(Recording));

            //The user types data
            printf("\nName: ");
            readString(temporalStation.name);
            printf("Latitude and longitude (example: 37.000 89.0000): ");
            scanf("%f %f", &temporalStation.latitude, &temporalStation.longitude);

            //Increase the number of stations and modify the memory to add the station, then, add the station
            amountStations++;
            stations = (Station*) realloc(stations, amountStations * sizeof(Station));
            stations[amountStations-1] = temporalStation;

        //Option to asign a recording to station
        } else if(option == ASIGN_RECORDING_TO_STATION){
            //Print all recordings
            printf("\nRECORDINGS\n");
            for(int i=0; i<amountRecordings; i++) printf("   Recording %i (%s) -> station:%s\n", i+1, recordings[i].filename, recordings[i].station[0] == '\0' ? "null" : recordings[i].station);

            //The user types a recording name
            printf("Recording name: ");
            char recordingName[50];
            readString(recordingName);

            //Creates a temporary recording iterator
            int iteratorRecording = -1;

            //For each existing recording
            for(int i=0; i<amountRecordings; i++){
                //Compares the strings and save the recording if they match
                if(compareStrings(recordingName, recordings[i].filename)){
                    iteratorRecording = i;
                    break;
                }
            }

            //Captured recording
            Recording capturedRecording;

            //If the recording was not started, it is because it does not exist
            if(iteratorRecording == -1){
                //Message error
                printf("\nRecording not found...\n");
            } else {
                //Capture the recording
                capturedRecording = recordings[iteratorRecording];

                //The user types name station
                printf("Station name to assign: ");
                char stationName[50];
                readString(stationName);

                //Check if the station exists
                int capturedStation = -1;
                for(int i=0; i<amountStations; i++){
                    //Compares the names, if is equal, save the station and breaks the loop
                    if(compareStrings(stationName, stations[i].name)){
                        capturedStation = i;
                        break;
                    }
                }

                //Check the station
                if(capturedStation == -1){
                    //Message error
                    printf("Station not found...\n");
                } else {
                    //Adds the recording      
                    stations[capturedStation].amountRecordings++;
                    stations[capturedStation].recordings = (Recording*) realloc(stations[capturedStation].recordings, stations[capturedStation].amountRecordings * sizeof(Recording));
                    stations[capturedStation].recordings[amountRecordings-1] = capturedRecording;
                
                    //Change the name of the stations recording
                    copyString(recordings[iteratorRecording].station, stations[capturedStation].name);
                }
            }

        //Option to print the recordings of stations
        } else if(option == PRINT_STATIONS_DATA){
            //Print a title
            printf("\nSTATIONS\n");

            //Loop for stations
            for(int i=0; i<amountStations; i++){
                printf("   Station %i (%s) -> (lat:%f, lon:%f) \n", i+1, stations[i].name, stations[i].latitude, stations[i].longitude);
            
                //Loop for recordings on station
                for(int j=0; j<stations[i].amountRecordings; j++){
                    //Temporal recording
                    Recording temporalRecording = stations[i].recordings[j];
                    printf("      Recording %i (%s) -> date: %s, format: %s\n", j+1, temporalRecording.filename, temporalRecording.date, temporalRecording.format == OGG ? "OGG" : (temporalRecording.format == WAV ? "WAV" : "MP3"));
                }
            }
        }
    }
    
    //Memory cleaning
    free(recordings);
    free(stations);
}