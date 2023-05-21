#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iso646.h>
#include <time.h>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

typedef struct {
    char name[50];
    int priority; 
    int age; 
    int time;
    bool apend;
} Person;

typedef struct {
    Person wait[100];
    int front, rear;
} Queue;

int tam;


bool search(char index, char *array)
{
    int i;

    for (i = 0; i < 26; i++)
    {
        if (index == array[i]) return true;
    }

    return false;
}

bool rules(char *nome, char *Max, int tam)
{
    if(!search(*nome, Max)) return false;
    if(tam <= 0) return false;
    else return true;
}

bool solve(char *nome, char *Max, char *Min, int tam)
{
    int i;

    bool validating = rules(nome, Max, strlen(nome) - 1);
    if(!validating) return false;

    for (i = 1; i < tam; i++)
    {
        if (search(*(nome + i), Min) == 0 && *(nome + i) != ' ')
        {
            if (nome[i - 1] != ' ') return false;
        } 
        if (*(nome + i) == ' ' && search(nome[i + 1], Max) == 0) return false;
    }

    return true;
}

Person getPerson(){

    char Min[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char Max[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    system("clear || cls");
    Person peek;

    do{
        printf("Digite o nome do paciente: ");
        fgets(peek.name, 50, stdin);
        peek.name[strlen(peek.name) - 1] = '\0';

    }while(not solve(peek.name, Max, Min, strlen(peek.name) - 1));
    
    printf("Digite a idade do paciente: ");
    scanf("%d", &peek.age);

    system("clear || cls");
    
    if (peek.age < 5 or peek.age > 80) peek.priority = 2;
    else if (peek.age < 16 or peek.age > 60) peek.priority = 1;
    else peek.priority = 0;

    peek.time = 0;
    peek.apend = true;
    
    return peek;
}

int newPriority(int value){
    return (not value) ? 2 : (value == 1) ? 1 : 0;
}

Person peek( Queue list){
    return list.wait[list.front];
}

bool isEmpty(Queue list){
    return (list.front > list.rear);
}

bool isOk(int number){
    return (number > 0 and number < 8);
}

void fillBool(bool * list){
    for(int i = 0; i < 7; i++){
        list[i] = true;
    }
}

void enqueue(Queue *queue, Queue list[], int * day, Person patient) {
    if (queue->rear == tam-1) {
            if(*day < 7){
                *day = *day + 1;
                enqueue(&list[*day], list, day, patient);
            }
            else return (void) printf("Limite atingido de atendimento!\n");
    }

    if (queue->front == -1 and queue->rear == -1) {
        queue->front = 0;
        queue->rear = 0;
        queue->wait[queue->rear] = patient;
    } else {
        int i, j;
        for (i = queue->front; i <= queue->rear; i++) {
            if (patient.priority < queue->wait[i].priority) {
                for (j = queue->rear + 1; j > i; j--) {
                    queue->wait[j] = queue->wait[j - 1];
                }
                queue->wait[i] = patient;
                queue->rear++;
                break;
            }
        }
        if (i > queue->rear) {
            queue->rear++;
            queue->wait[queue->rear] = patient;
        }
    }
}

void dequeueIndex(Queue * list, int index){
    if(index < (*list).rear){
        (*list).wait[index] = (*list).wait[index+1];
        dequeueIndex(list, ++index);
    }
    else (*list).rear--;
}

Person dequeue(Queue *queue) {
    if (queue->front == -1) {

        Person empty = {-1, -1};
        empty.apend = false;
        return empty;
    }
    Person patient = queue->wait[queue->front];
    patient.apend = (queue->front > queue->rear) ? false : true;
    queue->front += (queue->front > queue->rear) ? 0 : 1;

    return patient;
}

void displayPeek(Person * peek, Queue * list, int cont, int day, bool first){

    if((*peek).apend){
        printf("Neste momento %s esta sendo atendido | Tempo decorrido  de %d minutos.\n", (*peek).name, (*peek).time );
    }
    else{
        if(not first){
            printf("Nao ha ninguém sendo atendido agora!\n");
            (*peek) = dequeue(list);
        }
    }
    printf("Atendimentos realizado no dia %d: %d\n", day, cont);
}

void display(Queue list, int tam, int j, int i){
    if(i > tam) return;
    printf("[%d] %s | Age %d | Priority %d\n", j, list.wait[i].name, list.wait[i].age, newPriority(list.wait[i].priority));
    display(list,tam,++j, ++i);
}

void fillQueue(Queue * list){
    for(int i = 0; i < 7; i++){
        list[i].front = -1;
        list[i].rear = -1;
    }
}

int main() {
    Queue Fila[7];
    fillQueue(Fila);

    srand(time(NULL));
    int cont = 0, day = 0, nowDay = 0;
    Person apointment;

    system("clear || cls");
    printf("Digite quantas pessoas serao antedidas no dia de hoje: ");
    scanf("%d", &tam);
    
    bool first[7];
    fillBool(first);
    
    while(1){
        int op, chooseDay, index;
        Person example;
        system("clear || cls");
        printf("Opcoes:\n\n\t(1) - Inserir pessoa na fila\n\t(2) - Girar tempo\n\t(3) - Remover paciente da fila\n\t(4) - Ver fila atual\n\t(0) - Sair\n\n");
        displayPeek(&apointment, &Fila[nowDay],cont, nowDay+1, first[nowDay]);
        printf("Nowday: %d\n", nowDay);
        printf("\nEscolha um número: ");    

        scanf("%d", &op);
        getchar();
        switch(op){
            case 0:
                exit(0);
            break;
            
            case 1:
                example = getPerson();
                if(cont < tam){
                    enqueue(&Fila[day], Fila, &day, example);
                    if(first[0]){
                        apointment = dequeue(&Fila[day]);
                        first[0] = true;
                        cont++;
                    }
                    first[day] = false;
                }
                else{
                    enqueue(&Fila[day], Fila, &day, example);
                    first[day] = false;
                    cont = 0;
                    
                }
            break;
            
            case 2:
                if(apointment.time < 30){
                    apointment.time += ((rand() % 15));
                }
                else{
                    if(cont < tam){
                        apointment = dequeue(&Fila[nowDay]);
                        cont++;
                    }
                    else{
                        first[nowDay] = true;
                        ++nowDay;
                        //apointment = dequeue(&Fila[++nowDay]);
                        cont = 0;
                    }
                }
            break;

            case 3:
                
                do{
                    system("clear || cls");
                    printf("Digite o dia que terá o valor removido: ");
                    scanf("%d", &chooseDay);
                }while(not isOk(chooseDay));
                
                if(not isEmpty(Fila[chooseDay])){
                    do{
                        system("clear || cls");
                        printf("Digite o valor que será removido: ");
                        scanf("%d", &index);
                    }while(not isOk(index));
                    dequeueIndex(&Fila[chooseDay-1], index);
                }  
                else{
                    printf("A fila esta vazia para o dia %d!\n", chooseDay);
                    getchar();
                }
            break;

            case 4:
                do{
                    system("clear || cls");
                    printf("Digite o dia escolhido para ver: ");
                    scanf("%d", &chooseDay);
                }while(not isOk(chooseDay));
                
                if(not first[chooseDay-1])
                    display(Fila[chooseDay-1], tam-1, 1, Fila[chooseDay-1].front);
                else printf("A fila esta vazia para o dia %d!\n", chooseDay);    
                getchar();
                getchar();
                
            break;
        }
    }
    return 0;
}
