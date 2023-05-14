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

Person getPerson(){
    system("clear || cls");
    Person peek;

    printf("Digite o nome do paciente: ");
    fgets(peek.name, 50, stdin);
    peek.name[strlen(peek.name) - 1] = '\0';
    
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

void enqueue(Queue *queue, Person patient) {
    if (queue->rear == tam-1) {
        printf("A fila esta cheia!\n");
        return;
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

void displayPeek(Person * peek, Queue * list, int cont, bool first){

    if((*peek).apend){
        printf("Neste momento %s esta sendo atendido | Tempo decorrido  de %d minutos.\n", (*peek).name, (*peek).time );
    }
    else{
        if(not first){
            printf("Nao ha ninguém sendo atendido agora!\n");
            (*peek) = dequeue(list);
        }
    }
    printf("Atendimentos realizado hoje: %d\n", cont);
}

void display(Queue list, int j, int i){
    if(i > list.rear) return;
    printf("[%d] %s | Age %d | Priority %d\n", j, list.wait[i].name, list.wait[i].age, newPriority(list.wait[i].priority));
    display(list,++j, ++i);
}

int main() {
    Queue Fila;
    Fila.front = -1;
    Fila.rear = -1;

    srand(time(NULL));
    int cont = 0;
    Person apointment;

    system("clear || cls");
    printf("Digite quantas pessoas serao antedidas no dia de hoje: ");
    scanf("%d", &tam);
    
    bool first = true;

    while(1){
        int op;
        system("clear || cls");
        printf("Opcoes:\n\n\t(1) - Inserir pessoa na fila\n\t(2) - Girar tempo\n\t(3) - Remover paciente da fila\n\t(4) - Ver fila atual\n\t(0) - Sair\n\n");
        displayPeek(&apointment, &Fila,cont, first);
        printf("\nEscolha um número: ");    

        scanf("%d", &op);
        getchar();
        switch(op){
            case 0:
                exit(0);
                break;
            
            case 1:
                if(cont < tam){
                    enqueue(&Fila, getPerson());
                    if(first){
                        apointment = dequeue(&Fila);
                        cont++;
                    }
                    first = false;
                }
                else{
                    printf("O numero maximo de antendimentos por dia foi atingido!\n");
                    exit(0);
                }

            break;

            case 2:
                if(apointment.time < 30){
                    apointment.time += ((rand() % 15));
                }
                else{
                    apointment = dequeue(&Fila);
                    cont++;
                }
            break;

            case 3:
            if(not isEmpty(Fila)){
                int index;
                printf("Digite o valor que será removido: ");
                scanf("%d", &index);
                dequeueIndex(&Fila, index);
            }  
            else{
                printf("A fila esta vazia!\n");
                getchar();
            }
            break;

            case 4:
            if(not isEmpty(Fila) and not first)
                display(Fila, 1, Fila.front);
            else printf("A fila esta vazia!\n");    
            getchar();
            break;
        }
    }
    return 0;
}
