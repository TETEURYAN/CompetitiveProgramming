#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct kary //Estrutura com os índices da árvore. Implementação do modelo LCRS
{
    int num;
    struct kary * firstChild;
    struct kary * nextBro;
}kary;

kary * newNode(int value) //Geração de um novo nó com o valor a ser inserido na ávore N-aria
{
    kary * aux = malloc(sizeof(kary));

    aux->firstChild = NULL;
    aux->nextBro = NULL;
    aux->num = value;

    return aux;
}

kary * initKaryTree(int firstValue) //Função para inicializar a árvore N-aria
{
    return newNode(firstValue);
}

kary * search( kary * root, int value) //Função para procurar um determinado elemento na árvore, ele retorna o ponteiro (endereço de memória) da primeira ocorrência na árvore N-ária
{

	if (root != NULL) //Enquanto a raiz for diferente de NULL, prossiga
    {
		if (root->num == value) //Caso o primeiro valor for igual ao que estamos procurando, retorna o ponteiro dessa posição
			return root;
		else //caso contrário, pulamos para os fihos e fazemos o mesmo prosseguimento
        {
			kary *son = root->firstChild;

			while (son != NULL) 
            {
				kary *looking = search( son, value);
				
                if (looking != NULL) 
					return looking;
				son = son->nextBro;
			}
		}
	}

	return NULL;
}

bool unionKary(kary * first, kary * second) //Função que realiza a união da 2º árvore (second) com a primeira (first);
{
    if(not second or not first or not search(first, second->num)) //Se a primeira ou a segunda forem NULL, ou seja, nãoe existirem, o programa retornará false e não será prosseguido
        return false;

    else{ //Caso contrário, o programa dará prosseguimento na união das árvores N-aria
        kary * aux = search(first, second->num); //Procura a raiz da 2º árvore e averigua se está presente na 1º
        //aux = aux->firstChild; // Pula da raiz para os filhos, já que, se a raiz já existe na 1º árore, não hveria necessidade de adicioná-la novamente.
        
        if(aux->firstChild == NULL)
        {
            aux->firstChild = second->firstChild;
        }
        
        while(aux->nextBro != NULL) // Laço para encontrar o filho mais a direita
            aux = aux->nextBro;
        aux->nextBro = second->firstChild;//Os filhos desse nó na 1ª arvore recebem os filhos da raiz da 2ª arvore 
        return true; // retorna verdadeiro, união feita com sucesso
    }    
    
}


bool insertKary(kary * root, int value, int father)//Função para inserir valores na árvore N-ária, para adicionar é necessário a raiz da árvore, o valor a ser adicionado e o valor do Pai
{
    kary * Pai = search(root, father);//Procura o ponteiro do Pai, para toda árvore N-ária precisamos do Pai para adicionar

    if(Pai != NULL)
    {
        if(Pai->firstChild == NULL) // Se o pai não tiver filhos, então o valor que queremos adicionar será o primeiro filho dele
        {
            Pai->firstChild = newNode(value);
            return true;
        }
        else // Caso contrário, vamos encontrar o irmão mais a direita e adicionar o novo fihho
        {
            kary * son = Pai->firstChild;

            while(son->nextBro != NULL)
                son = son->nextBro;

            son->nextBro = newNode(value);
            return true; // retorna verdadeiro, procedimento realizado com sucesso
        }
    }
    else return false; //Caso o Pai seja NULL, ele não existe, procedimento retorna false
}

void display(kary * root){ //Função recursiva para imprimir árvores N-árias
    if(root == NULL) return;

    printf("%d(",root->num);
    kary * p = root->firstChild;

    while(p)
    {
        display(p);
        p = p->nextBro;
    }
    printf(")");
}

void main()
{
    kary * firstTree = initKaryTree(25);//Criando primeira árvore de raiz 25 e adicionando elementos
    insertKary(firstTree, 10,25);
    insertKary(firstTree, 15,25);
    insertKary(firstTree, 16,25);
    insertKary(firstTree, 24,10);
    insertKary(firstTree, 32,16);


    kary * secondTree =  initKaryTree(15);//Criando segunda árvore de raiz 16 e adicionando elementos
    insertKary(secondTree, 89,15);
    insertKary(secondTree, 78,15);
    insertKary(secondTree, 96,15);
    insertKary(secondTree, 50,78);
    insertKary(secondTree, 53,96);
    insertKary(secondTree, 24,96);
    
    unionKary(firstTree, secondTree);//União da segunda árvore na primeira

    display(firstTree);//printando a árvore N-aria já unida.
}
