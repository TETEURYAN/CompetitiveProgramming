#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <iso646.h>
#include <time.h>

struct build{
    char floor[50];
}build;

struct coordinates{
    int x,y;
}coordinates;

char getSymbol(int number){
    return (64 + number);
}

int getPos(int i, int j){
    return (j == 0) ? i :
           (j == 1) ? (i+19) : (i + 38);
}

double distTwoPoint(int x1, int y1, int x2, int y2){
    return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
}

struct coordinates getDist(int x, int y, int ** state){
    double small = INT_MAX;
    struct coordinates example;

    for(int i = 0; i < 300; i++){
        for(int j = 0; j < 3; j++){
            if(state[i][j] not_eq 0){
                if(distTwoPoint(x,y,i,j) < small){
                    small = distTwoPoint(x,y,i,j);
                    example.x = i;
                    example.y = j;
                }
            }
        }
    }
    return example;
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

void menu(int ** state, build architecture){

    int op;

    while(1){
        printf("\n\tSISTEMA DE ELEVADOR\n\n");
        printf("Opcoes:\n");
        printf("\t(1) - Subir a partir do terreo\n\t(2) - Descer de um AP\n\t(3) - Sair\n\nEscolha:");

        scanf("%d", &op);

        switch(op){
            case 1:

            break;

            case 2:

            break;

            case 3;
                exit(0);
            break;

        }

    }

}

int main(){
    struct build * architecture = NULL;
    int ** state = NULL;

    state = initState(state);

    architecture = insertBuildind(architecture, state);

    initFloors(architecture);

    menu(state, architecture);

    return 0;
}
