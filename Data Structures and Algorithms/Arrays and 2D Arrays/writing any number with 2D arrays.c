#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iso646.h>

char PrefixCentena[11][20] = {"", "c", "duz", "trez", "quatroc", "quinh", "seisc", "setec", "oitoc", "novec"};
char PrefixOnly10[10][20] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
char Dezenas[10][20] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
char Digits[10][20] = {"um ", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
char digitos[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

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

int convert(char *string, int number ,  int tam, int i){

	if(*(string+i) =='\0') return number ;
 	else 
	{
		number += (((int)*(string+i)) - '0') * pow(10,tam-1); 
		return convert(string, number ,  --tam,  ++i  );
	}

}

bool search(char index, char *array)
{
    for (int i = 0; i < 26; i++)
        if (index == *(array+ i)) return true;
    return false;
}

bool check_number(char *array)
{
    for (int i = 0; i < 26; i++)
        if (search(*(array+i), digitos)) return true;
    return false;
}

void PrintNumberPartTwo(int m)
{
    if(m < 10) printf("%s", Digits[m-1]);
    if(m >= 10 and m < 20) printf("%s", PrefixOnly10[ m%10]);
    if(m> 19 and not(m%10)) printf("%s", Dezenas[m/10 - 2]);
    if(m > 20 and m%10 not_eq 0) printf("%s e %s", Dezenas[m/10 - 2], Digits[(m%10) - 1]);
}

void PrintNumberPartOne(int n, int i, int j)
{
    if(n >= pow(10,9))
    {
      PrintNumberPartOne(n / 1000000000, 0, 0);
      printf("%s", (n / 1000000000) == 1 ? "bilhao " : (n >= 2000000000) ?  " bilhoes " : "bilhoes");
      PrintNumberPartOne(n % 1000000000, 0, 1);
    }
    else if(n >= pow(10,6))
    {
      PrintNumberPartOne(n / 1000000, 0, 0);
      printf("%s", (n / 1000000) == 1 ? "milhao " : " milhoes ");
      PrintNumberPartOne(n % 1000000, 0, 1);
    }
    else if(n >= 10000)
    {
      PrintNumberPartOne(n / 1000, 0, 0);
      printf("%s", n < 20000 ? "mil " : " mil ");
      PrintNumberPartOne(n % 1000, 1, ++j);
    }
    else if (n >= 1000)
    {
      if (n >= 2000) PrintNumberPartOne(n / 1000, 0, ++j);
      printf("mil");
      PrintNumberPartOne(n % 1000, 1, ++j);
    }
    else if (n >= 100)
    {
      if(n == 100 and j > 1) printf("e cem"); 
      if(n == 100 and j == 0) printf("cem");
      else
      {
          if(n == 900 and j > 0) printf("e ");
          printf("%sento%s", PrefixCentena[n / 100], n <= 199 ? "" : "s ");
          PrintNumberPartOne(n % 100, 1, ++j);
      }
    }
    else if (n >= 10)
    {
      if(j > 0 and n < 10000) printf("e ");
      if (n <= 19) printf("%s ", PrefixOnly10[n % 10]);
      else if( n > 19)
      {
          if(n < 10) printf("%s", Digits[n-1]);
          if(n >= 10 and n < 20) printf("%s", PrefixOnly10[ n%10]);
          if(n> 19 and not(n%10)) printf("%s", Dezenas[n/10 - 2]);
          if(n >= 20 and (n%10) not_eq 0) printf("%s e %s", Dezenas[n/10 - 2], Digits[(n%10)-1]);
      }
    }
    else if (n < 10 and i and not (not n))
    {
      printf("e %s", Digits[n-1]);
    }
    
    else if (n < 10 and not i)
    {
      printf("%s", Digits[n-1]);
    }
}

void solve(char *ano) 
{
    int intereger = convert(ano, 0, strlen(ano), 0);
    PrintNumberPartOne(intereger, 0, 0);
}

int main() 
{
    int tam = 15; char ano[tam];
    printf("Insert number: ");
    input_string(ano, 0, tam);

    if(not check_number(ano)) printf("Numero invalido");
    else solve(ano);
    
	return 0;
}
