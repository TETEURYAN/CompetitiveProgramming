#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void input_string(char *nickname, int i) 
{
    char c = getchar();
    if(c == '\n') nickname[i] = '\0';
    else 
    {
        nickname[i] = c;
        input_string(nickname, i + 1);
    }   
}

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


int main()
{
    char Min[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char Max[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    char nome[50];
    input_string(nome, 0);
    
    bool check = solve(nome, Max, Min, strlen(nome) - 1);

    printf("%s", check ? "Nome Valido\n" : "Nome Invalido\n");

    return 0;
}