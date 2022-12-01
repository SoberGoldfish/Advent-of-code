//Advent of Code Day 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* //Task 1
//define variables
int sum = 0;
int max_sum = 0;

//main function
int main(){
    FILE* open_file = fopen("input.txt", "r");  //open file with the input in

    if (open_file == NULL){     //if open file fails 
        printf("Error: Failed to open file!\n");
        return 1;
    }

    char* current_line = NULL;  //
    size_t length = 0;

    while(getline(&current_line, &length, open_file) != -1){
        if (current_line[1] == '\0'){
            if (sum > max_sum){
                max_sum = sum;
            }

            sum = 0;
        }else{
            sum += strtol(current_line, NULL, 10);
            //printf("Current sum %d\n", sum);
        }
    }
    fclose(open_file);

    printf("Max value: %d\n", max_sum);

    return 0;
}
*/

//Task 2
//define variables
int sum = 0;
int max_sum = 0;
int sec_sum = 0;
int tri_sum = 0;

void water_fall_effect(int sum){
    if (sum > max_sum){
        tri_sum = sec_sum;

        sec_sum = max_sum;
        
        max_sum = sum;
        
    }else if (sum > sec_sum){
        tri_sum = sec_sum;
        sec_sum = sum;
    }else if (sum > tri_sum){
        tri_sum = sum;
    }
}

//main function
int main(){
    FILE* open_file = fopen("input.txt", "r");  //open file with the input in

    if (open_file == NULL){     //if open file fails 
        printf("Error: Failed to open file!\n");
        return 1;
    }

    char* current_line = NULL;  //
    size_t length = 0;
    
    while(getline(&current_line, &length, open_file) != -1){
        
        if (current_line[1] == '\0'){
            water_fall_effect(sum);
            sum = 0;

        }else{
            sum += strtol(current_line, NULL, 10);
            //printf("Current sum %d\n", sum); //print sum of every elves calorie
        }
    
    }
    fclose(open_file);
    water_fall_effect(sum);

    //printf("3 Max values: %d , %d , %d\n", max_sum, sec_sum, tri_sum);
    printf("3 Max value: %d\n", max_sum + sec_sum + tri_sum);

    return 0;
}