#include <stdio.h>
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


#define MAX_SIZE 100

typedef struct {
    char name[50];
    int priority; 
    int age; 
    int time;
    bool apend;
} Person;

typedef struct {
    Person wait[MAX_SIZE];
    int front, rear;
} Queue;

Person getPerson(){
    system("clear || cls");
    Person peek;

    printf("Digite o nome do paciente: ");
    fgets(peek.name, 50, stdin);
    peek.name[strlen(peek.name) - 1] = '\0';
    
    printf("Digite a idade do paciente: ");
    scanf("%d", &peek.age);

    system("clear || cls");
    
    if (peek.age < 5 or peek.age > 80) peek.priority = 0;
    else if (peek.age >= 5 and peek.age < 16 or peek.age > 60 and peek.age < 80) peek.priority = 1;
    else peek.priority = 2;

    peek.time = 0;
    peek.apend = true;
    
    return peek;
}

Person peek( Queue list){
    return list.wait[0];
}

bool isEmpty(Queue list){
    return (list.front == list.rear);
}

void enqueue(Queue *queue, Person patient) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
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


Person dequeue(Queue *queue) {
    if (queue->front == -1) {

        Person empty = {-1, -1};
        empty.apend = false;
        return empty;
    }
    Person patient = queue->wait[queue->front];
    patient.apend = true;
    queue->front++;

    return patient;
}

void display(Queue list, int i){
    if(i > list.rear) return;
    printf("[%d] %s | Age %d | Priority %d\n", i+1, list.wait[i].name, list.wait[i].age, list.wait[i].priority);
    display(list, ++i);
}

int main() {
    Queue Fila;
    Fila.front = -1;
    Fila.rear = -1;

    srand(time(NULL));
    
    Person apointment;
    
    bool first = true;

    while(1){
        system("clear || cls");
        printf("Opcoes:\n\n\t(1) - Inserir pessoa na fila\n\t(2) - Remover pessoa da fila\n\t(3) - Ver quem esta sendo atendido\n\t(4) - Ver fila atual\n\t(5) - Adicionar 15 minutos\n\t(0) - Sair\n\n");
        printf("Escolha um número: ");    

        int op;
        scanf("%d", &op);
        getchar();
        switch(op){
            case 1:
                enqueue(&Fila, getPerson());
                if(first) apointment = dequeue(&Fila);
                first = false;
            break;

            case 2:
            break;

            case 3:  
                if(apointment.apend){
                    printf("Neste momento %s esta sendo atendido | Tempo decorrido  de %d minutos.\n", apointment.name, apointment.time );
                }
                else{
                    printf("Nao ha ninguém sendo atendido agora!\n");
                    apointment = dequeue(&Fila);
                }
                getchar();

            break;

            case 4:
            if(not isEmpty(Fila))
                display(Fila, Fila.front);
            else printf("A fila esta vazia!\n");    
            getchar();
            break;
        }
        if(apointment.time < 30){
            apointment.time += ((rand() % 15));
        }
        else apointment =  dequeue(&Fila);

    }
    return 0;
}
