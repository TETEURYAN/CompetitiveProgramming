#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>

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
    
    return peek;
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
    if (queue->front == -1 or queue->front > queue->rear) {
        printf("Queue is empty!\n");
        Person empty_patient = {-1, -1};
        return empty_patient;
    }

    Person patient = queue->wait[queue->front];
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

    while(1){
        printf("Opcoes:\n\n\t(1) - Inserir pessoa na fila\n\t(2) - Remover pessoa da fila\n\t(3) - Ver histórico total\n\t(4) - Ver fila atual\n\t(5) - Adicionar 15 minutos\n\t(0) - Sair\n\n");
        int op;
        scanf("%d", &op);
        getchar();
        switch(op){
            case 1:
            enqueue(&Fila, getPerson());
            break;

            case 2:
            dequeue(&Fila);
            break;

            case 3:
            break;

            case 4:
            display(Fila, 0);
            getchar();
            break;
        }
    }

    return 0;
}
