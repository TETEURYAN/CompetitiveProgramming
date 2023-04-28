struct stack{
    int value;
    struct stack * next;
};

struct stack * getnode(struct stack * node,  int num){

    struct stack * aux = malloc(sizeof(struct stack));

    aux->value = num;
    aux->next = node;
    
    return aux;
}

struct stack * pop(struct stack * stack){

    if(not stack){
        return NULL;
    }
    else{
        struct stack * aux = stack;
        aux = stack;
        stack = stack->next;
        free(aux);
        return stack;
    }
}

struct stack * push(struct stack *node, int value){
    return getnode(node, value);
}

int peek(struct stack * node){
    return (node->value);
}

bool isEmpty(struct stack * node){
    return node;
}

int sizeStack(struct stack * node){
    if(node){
        return 1 + sizeStack(node);
    }
}

bool isFull(struct stack * node,int size){
    return (size < sizeStack(node));
}

void display(struct stack * node){
    if(node){
        printf("%d ", node->value);
        display(node->next);
    }
}
