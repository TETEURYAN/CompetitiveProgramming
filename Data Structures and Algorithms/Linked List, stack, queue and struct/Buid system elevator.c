#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
#include <time.h>

struct build{
    char floor[50];
}build;

char getSymbol(int number){
    return (64 + number);
}

int getPos(int i, int j){
    return (j == 0) ? i :
           (j == 1) ? (i+19) : (i + 38);
}

struct build * insertBuildind(struct build * architecture, int ** state){

    architecture = calloc(300, sizeof(build));


    for(int i = 0; i < 300; i++){
        char example[50] = "██║|[-]==========[-]==========[-]|║██";
        for(int j = 0; j < 3; j++){
            if(state[i][j] not_eq 0){
                if(j == 0){
                    example[11] = getSymbol(state[i][j]);
                }
                else if(j == 1){
                    example[24] = getSymbol(state[i][j]);
                }
                else if(j == 2){
                    example[37] = getSymbol(state[i][j]);
                }
            }
        }
        strcpy(architecture[i].floor, example);
    }

    return architecture;
}

int ** initState(int ** state){
    state = calloc(300, sizeof(int*));

    if(state){
        for(int i = 0; i < 300; i++){
            state[i] = calloc(3, sizeof(int));
        }
        int ctrl = 0;

        for(int i = 0; i < 300; i++)
            for(int j = 0; j < 3; j++)
                state[i][j] = 0;                

        for(int i = 0; i < 300; i++){
            for(int j = 0; j < 3; j++){
                if(not i or not(i%60)){
                    state[getPos(i, j)][j] = ++ctrl;
                }
            }
        }
    } 

    for(int i = 0; i < 300; i++)
    {
       for(int j = 0; j < 3; j++)
            printf("%d ", state[i][j]);
        printf("\n");
    }

    return state;
}

void initFloors(struct build * architecture){
    FILE * floor;
    floor = fopen("build.txt", "w");

    for(int i = 299; i > -1; i--){
        fprintf(floor,"%3d %s\n", i+1, architecture[i].floor );
    }
    fclose(floor);
}

int main(){
    struct build * architecture = NULL;
    int ** state = NULL;

    state = initState(state);

    architecture = insertBuildind(architecture, state);

    initFloors(architecture);
}
