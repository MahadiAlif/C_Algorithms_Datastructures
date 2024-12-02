#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <float.h>

    //define the struct
    //readfile_storeit
    //switch case
    //respond to it
    //list
    //best
    //details 



typedef struct{
    char name[30];
    int id;
    int laps;
    float* lap_times;
} athlete_t;


void readfile_storeit(char* filename, athlete_t* athletes, int num_athlete, float* best_avg, int* best_index);
void number_athletes(char* filename, int* num_athlete);
void list_athletes(int num_athletes, athlete_t* athletes);
void best_athlete(float* best_avg, int* best_index, athlete_t* athletes);
void details_athlete(char* name, athlete_t* athletes, int num_athletes);

int main(){

    int num_athlete;
    athlete_t athletes[100];
    char filename[30];
    char command[30];
    float best_avg = FLT_MAX;
    int best_index = -1;

    printf("Input file name\n");
    fgets(filename, 30, stdin);
    filename[strcspn(filename, "\n")] = 0;
    number_athletes(filename, &num_athlete);
    readfile_storeit(filename, athletes, num_athlete, &best_avg, &best_index);

    printf("Command?\n");
    fgets(command, 30, stdin);
    command[strcspn(command, "\n")] = 0;
    while (strcasecmp(command, "stop") != 0){
        if (strcasecmp(command, "list") == 0){
            list_athletes(num_athlete, athletes);
        }
        else if (strcasecmp(command, "best") == 0){
            best_athlete(&best_avg, &best_index, athletes);
        }
        else if (strncasecmp(command, "details ", 8) == 0){
            char* name = command + 8;
            while (*name == ' ') name++;
            details_athlete(name, athletes, num_athlete);
        }
        else if(strcasecmp(command, "stop") == 0){
            printf("Program ended.\n");
            return;
        }
        else{
            printf("Invalid Command\n");
        }
        printf("Command?\n");
        fgets(command, 30, stdin);
        command[strcspn(command, "\n")] = 0;
    }


    return 0;
}
void number_athletes(char* filename, int* num_athlete){
    FILE* file = fopen(filename, "r");
    if (file == NULL){
        printf("error opening file\n");
        return;
    }
    fscanf(file, "%d", num_athlete);
    fclose(file);
}

void readfile_storeit(char* filename, athlete_t* athletes, int num_athlete, float* best_avg, int* best_index){
    FILE* file = fopen(filename, "r");
    

    if (file == NULL){
        printf("error opening file\n");
        return;
    }
    fscanf(file, "%*d");
    fgetc(file);
        for (int i =0; i<num_athlete; i++){
        float avg = 0.0;

        fscanf(file, "%s %d %d", athletes[i].name, &athletes[i].id, &athletes[i].laps);
        
        athletes[i].lap_times = (float*) malloc (athletes[i].laps * sizeof(float));
        for (int j=0; j<athletes[i].laps; j++) {
            fscanf(file, "%f", &(athletes[i].lap_times[j]));
            avg += athletes[i].lap_times[j];
        }     
        
        avg = avg/athletes[i].laps;

        if  (avg < *best_avg){
            *best_avg = avg;
            *best_index = i;
        }
    }
    fclose(file);
}
 
void list_athletes(int num_athletes, athlete_t* athletes){
    printf("Number of athletes %d\n", num_athletes);
    for (int i = 0; i< num_athletes; i++){
        printf("Name: %-10s", athletes[i].name);
        printf("#ID: %-10d", athletes[i].id);
        printf("Laps: %d\n", athletes[i].laps);
        printf("Lap Times\t");
        for (int j = 0; j< athletes[i].laps; j++){
            printf("%.2f\t", athletes[i].lap_times[j]);
        }
        printf("\n");
        
    }
}

void best_athlete(float* best_avg, int* best_index, athlete_t* athletes){

    printf("Name\t %s\t", athletes[*best_index].name);
    printf("#Id\t%d\t", athletes[*best_index].id);
    printf("Laps\t%d\t", athletes[*best_index].laps);
    printf("Times\t");
    for (int i = 0; i < athletes[*best_index].laps; i++){
        printf("%.2f\t", athletes[*best_index].lap_times[i]);
    }
    
    printf("(Average: %.2f)\n", *best_avg);
}

void details_athlete(char* name, athlete_t* athletes, int num_athletes){
    int found = 0;
    for (int i = 0; i< num_athletes; i++){
        if (strcasecmp(name, athletes[i].name) == 0){
            printf("Id\t%d\t", athletes[i].id);
            printf("Laps\t%d\t", athletes[i].laps);
            printf("Times\t");
            for (int j = 0; j<athletes[i].laps; j++){
                printf("%.2f\t", athletes[i].lap_times[j]);

            }
        found = 1;
        printf("\n");
        }
    }
    if (found == 0){
        printf("The athlete name was not found\n");
    }
    
}