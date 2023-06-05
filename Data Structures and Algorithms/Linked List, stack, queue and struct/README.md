# Struct
Struct is a flexible variable that can have different types of data inside it. In a sense, declaring a struct is declaring a new data type.
For example, if you want a data type that provides a coordinate, you will need a struct with two variables inside. Or if you want a person's information, you would need a struct with name, date of birth, age, etc.Examples below:

## Cordinate struct
```c
 struct cordinate
{
    int x;
    int y;
};
```

## Person struct

```c
struct Person
{
    char name{50};
    int age;
    int ID;
};
```

# Linked List
 Linked list is a list that uses dynamic assignment to store values.
 ```c
 struct Node
{
    int info;
    int Node * next;
};
```
 
# Stack

Stack is an abstract data structure used with the principle FILO(First in, Last out). The best known functions of this structure are Peek, Pop and Push.

```C

struct stack * pop(struct stack * list){
    struct stack * aux = list;
    list = list->next;
    free(aux);
    return list;
}

struct stack * push(struct stack * list, int num){
    if(not list){
        return insertNode(num);
    }
    else{
        struct stack * aux = getnode();
        aux->value = num;
        aux->next = list;
        return aux;
        }
}
```

# Queue

Queue is an abstract data structure of type FIFO(First in, first out).

```C
struct queue * putValue(struct queue * list, int num){
    if(not list){
        return insertNode(num);
    }
    else{
        struct queue * aux = list;
            while(aux->next){
                aux=aux->next;
            }
            aux->next = insertNode(num);
            return list;
        }
}

int outValue(struct queue ** list){
    int first = (*list)->value;
    struct queue * aux = (*list);
    (*list) = (*list)->next;
    free(aux);
    return first;
}

int sizeQueue(struct queue * list){
    if(list){
        return 1 + sizeQueue(list->next);
    }
    else return 0;
}

bool isEmpty(struct queue * list){
    return list;
}

bool isFull(struct queue * list, int tam){
    return (sizeQueue(list) >= tam);
}
```
