#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct build{
    char floor[50];
}build;

struct build * insertBuildind(struct build * architecture){

    architecture = calloc(300, sizeof(build));

    for(int i = 0; i < 300; i++){
        strcpy(architecture[i].floor, "██║|[-]==========[-]==========[-]|║██");
    }

    return architecture;
}

void initFloors(struct build * architecture){
    FILE * floor;
    floor = fopen("build.txt", "w");

    for(int i = 0; i < 300; i++){
        fprintf(floor,"%3d %s\n", i+1, architecture[i].floor );
    }
    fclose(floor);
}

int main(){
    struct build * architecture;

    architecture = insertBuildind(architecture);

    initFloors(architecture);
}
