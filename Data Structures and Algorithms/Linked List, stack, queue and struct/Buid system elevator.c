#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <iso646.h>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

struct build{
    char floor[50];
}build;

struct coordinates{
    int x, y;
}coordinates;

struct statement{
    struct coordinates now;
    struct coordinates destiny;
    bool floor;
    bool moovment;
    int number;
}statement;

struct choosen{
    int a, b, c, d;
}choosen;

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

struct statement ** initStatement(struct statement ** traveled, int ** state){
    traveled =  calloc(300, sizeof(struct statement*));
    
    for(int i = 0; i < 300; i++){
        traveled[i] = calloc(3, sizeof(struct statement));
    }

    if(traveled){
        for(int i = 0; i < 300; i++){
            for(int j = 0; j < 3; j++){
                if(state[i][j]){
                    traveled[i][j].now.x = i;
                    traveled[i][j].now.y = j;
                    traveled[i][j].floor = true;
                    traveled[i][j].number = state[i][j];
                }
                traveled[i][j].moovment = false;
            }
        }
    }

    // for(int i = 0; i < 300; i++)
    //     for(int j = 0; j < 3; j++)
    //         if(traveled[i][j].floor)
    //             printf("Coordinate x %d Coordinate y %d\n", traveled[i][j].now.x, traveled[i][j].now.y );

    // getchar(); 
    return traveled;
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

struct choosen initSelect(struct choosen select, bool operation, bool type){
    
    if(operation and type){
        do{
            system("clear or cls");
            printf("Digite o valor do andar de destino: ");
            scanf("%d", &select.a);
        }while(select.a < 1 or select.a > 300);

        do{
            system("clear or cls");
            printf("Digite o valor do corredor de destino: ");
            scanf("%d", &select.b);
            --select.b;
        }while(select.b < 0 or select.b > 2);
    }

    else if(operation and not type){
        do{
            system("clear or cls");
            printf("Digite o valor do andar em que se encontra: ");
            scanf("%d", &select.a);
        }while(select.a < 1 or select.a > 300);

        do{
            system("clear or cls");
            printf("Digite o valor do corredor em que se encontra: ");
            scanf("%d", &select.b);
            --select.b;
        }while(select.b < 0 or select.b > 2);
    }

    else{

        do{
            system("clear or cls");
            printf("Digite o valor do andar em que se encontra: ");
            scanf("%d", &select.a);
        }while(select.a < 1 or select.a > 300);

        do{
            system("clear or cls");
            printf("Digite o valor do corredor em que se encontra: ");
            scanf("%d", &select.b);
            --select.b;
        }while(select.b < 0 or select.b > 2);

        do{
            system("clear or cls");
            printf("Digite o valor do andar de destino: ");
            scanf("%d", &select.c);
        }while(select.c < 1 or select.c > 300);

        do{
            system("clear or cls");
            printf("Digite o valor do corredor de destino: ");
            scanf("%d", &select.d);
            --select.d;
        }while(select.d < 0 or select.d > 2);
    }

    return select;
}

void initFloors(struct build * architecture){
    FILE * floor;
    floor = fopen("build.txt", "w");

    for(int i = 299; i > -1; i--){
        fprintf(floor,"%3d %s\n", i+1, architecture[i].floor );
    }
    fclose(floor);
}

void menu(int ** state, struct build * architecture){

    int op, i = 0;
    struct choosen select;
    while(true){
        system("clear or cls");
        printf("\n\tSISTEMA DE ELEVADOR\n\n");
        printf("Opcoes:\n");
        printf("\t(1) - Subir a partir do terreo\n\t(2) - Descer até o terreo\n\t(3) - Subir ou descer entre os APs\n\nEscolha:");

        scanf("%d", &op);

        switch(op){
            case 1:
                select = initSelect(select, true, true);
            break;

            case 2:
                select = initSelect(select, true, false);
            break;

            case 3:
                select = initSelect(select, false, false);
            break;

            case 4:
                exit(0);
            break;

        }
    }
}

int main(){
    struct build * architecture = NULL;
    struct statement ** traveled = NULL;
    int ** state = NULL;

    state = initState(state);
    traveled = initStatement(traveled, state);

    architecture = insertBuildind(architecture, state);

    initFloors(architecture);

    menu(state, architecture);

    return 0;
}
