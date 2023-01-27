#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iso646.h>

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
    for (int i = 0; i < 26; i++)
        if (index == *(array+ i)) return true;
    return false;
}

int check_signal(char index, char *array)
{
    int count = 0;
    for (int i = 0; i < 26; i++)
        if (index == *(array + i)) count++;
    return count;

}

void solve(char *number, char *digits)
{
    int virg = check_signal(',', number);
    int point = check_signal('.', number);
    int positive = check_signal('+', number);
    int negative = check_signal('-', number);
    
    for(int i = 0; i < strlen(number); i++)
    {
        if(not search(*(number + i), digits) or virg > 1 or positive > 1 or negative > 1 or point > 1 or (point and virg)) 
        {
            printf("Tipo de numero: Isso nem eh numero.\n"); return;
        }
    }
    
    printf("Tipo de numero: %s", ((virg or point) and negative) ? "Real negativo\n" 
                            : ((virg or point) and !negative) ? "Real positivo\n" 
                            : ((not virg or not point) and negative) ? "Inteiro\n" : "Natural\n");

}

int main()
{
    char digitos[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', ',','.'};
    
    char *number;
    input_string(number,  0);

    solve(number, digitos);

    return 0;
}