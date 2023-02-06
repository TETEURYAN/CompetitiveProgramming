#include <stdio.h>
#include <string.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>

void input_string(char *nickname, int i, int tam) 
{
    char c = getchar();
    if(c == '\n' || i == tam) nickname[i] = '\0';
    else 
    {
        nickname[i] = c;
        input_string(nickname, i + 1, tam);
    }   
}

bool search(char index, char *array)
{
    for (int i = 0; i < strlen(array); i++)
        if (index == array[i]) return true;
    return false;
}

bool check_number(char *array, char *digitos)
{
    for (int i = 0; i < strlen(array); i++)
        if (not search(*(array+i), digitos)) return false;
    return true;
}

void convert(char *string, int *array, int tam, int i){

	if(*(string+i) =='\0') return;
 	else 
	{
		array[i] = (((long long int)*(string+i)) - '0');
		convert(string, array,  --tam,  ++i  );
	}
}

void first_digit(int *array, int *digit, int tam, int i, int j)
{
    for(; i < tam; i++, j--)
        *digit = *digit + (array[i]*j);
    *digit = (11 - (*digit%11));
    *digit = (*digit) >= 10 ? 0 : (*digit);
}

bool check_digits(char *array, int DVone, int DVtwo)
{
    if(DVone == ((int)*(array+9) - '0') and DVtwo == ((int)*(array+10) - '0') ) return true;
    else return false;
}

bool validate(char *cpf)
{
    int digits[12];
    int DVone = 0;
    int DVtwo = 0;
    
    convert(cpf, digits, 15, 0);
    first_digit(digits, &DVone, 9, 0, 10);
    first_digit(digits, &DVtwo,10, 0, 11);
    
    bool check = check_digits(cpf, DVone, DVtwo);
    
    return check ? true : false;
}

void solve(char *cpf)
{
    char digitos[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    if(not check_number(cpf, digitos) or not validate(cpf)) printf("CPF Invalido!");
    else printf("CPF Valido!\n");
}

void main()
{
    char cpf[12];

    printf("Digite seu CPF: ");
    input_string(cpf, 0, 15);

    solve(cpf);
}
