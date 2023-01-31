#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <iso646.h>


char PrefixCentena[11][20] = {"", "cento ", "duzento", "trezento", "quatrocento", "quinhento", "seiscento", "setecento", "oitocento", "novecento"};
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

int convert(char *string, long long int number ,  int tam, int i){

	if(*(string+i) =='\0') return number ;
 	else 
	{
		number += (((long long int)*(string+i)) - '0') * pow(10,tam-1); 
		return convert(string, number ,  --tam,  ++i  );
	}
}

bool search(char index, char *array)
{
    for (int i = 0; i < strlen(array); i++)
        if (index == array[i]) return true;
    return false;
}

bool check_number(char *array)
{
    for (int i = 0; i < strlen(array); i++)
        if (not search(*(array+i), digitos)) return false;
    return true;
}

void PrintNumberPartTwo(long long int m)
{
    if(m < 10) printf("%s", Digits[m-1]);
    if(m >= 10 and m < 20) printf("%s", PrefixOnly10[ m%10]);
    if(m> 19 and not(m%10)) printf("%s", Dezenas[m/10 - 2]);
    if(m > 20 and m%10 not_eq 0) printf("%s e %s", Dezenas[m/10 - 2], Digits[(m%10) - 1]);
}

void PrintNumberPartOne(long long int n, int i, int j)
{
    if(n >= pow(10,6))
    {
      PrintNumberPartOne(n / 1000000, 0, 0);
      printf("%s", (n / 1000000) == 1 ? "milhao " : " milhoes ");
      PrintNumberPartOne(n % 1000000, 0, 1);
    }
    else if(n >= 10000)
    {
      PrintNumberPartOne(n / 1000, 0, 0);
      printf("%s", n < 20000 ? " mil " : " mil ");
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
          printf("%s%s", PrefixCentena[n / 100], n <= 199 ? "" : "s ");
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

void solve(char *ano, int tam, int dif) 
{
    long long int intereger; 
    long long int restante;
    
    if(tam <= 9) 
    {
        intereger = convert(ano, 0, strlen(ano), 0);
        PrintNumberPartOne(intereger, 0, 0);
    }
    else if(tam <=12)
    {
        intereger = convert(ano, 0, tam-9, dif);
        PrintNumberPartOne(intereger, 0, 0);
        printf("%s", (intereger == 1) ? " bilhao " : " bilhoes ");
        
        int def = abs((tam) - 9);
        //printf("\n%d\n", tam-def);
        restante = convert(ano, 0, tam-def, def + dif);
        PrintNumberPartOne(restante, 0, 0);
        
    }
    
    else if(tam <=15)
    {
        intereger = convert(ano, 0, tam-12, dif);
        PrintNumberPartOne(intereger, 0, 0);
        printf("%s", (intereger == 1) ? "trilhao " : " trilhoes ");
        
        int def = abs((tam) - 12);
        //printf("\n%d\n", tam-def);
        solve(ano, tam-def, def+dif);
    }
    
    else if(tam <=18)
    {
        intereger = convert(ano, 0, tam-15, dif);
        PrintNumberPartOne(intereger, 0, 0);
        printf("%s", (intereger == 1) ? "quatrilhao " : " quatrilhoes ");
        
        int def = abs((tam) - 15);
        //printf("\n%d %d\n", def+dif, tam);
        solve(ano, tam-def, def+dif);
    }
    
    else if(tam <=21)
    {
        intereger = convert(ano, 0, tam-18, dif);
        PrintNumberPartOne(intereger, 0, 0);
        printf("%s", (intereger == 1) ? "quintilhao " : " quintilhoes ");
        
        int def = abs(tam - 18);
        //printf("\n%d %d\n", def, tam);
        solve(ano, tam-def, def+dif);
    }
    
    else if(tam <=24)
    {
        intereger = convert(ano, 0, tam-21, dif);
        PrintNumberPartOne(intereger, 0, 0);
        printf("%s", (intereger == 1) ? "sextilhão " : " sextilhoes ");
        
        int def = abs(tam - 21);
        //printf("\n%d %d\n", def, tam);
        solve(ano, tam-def, def+dif);
    }
}

int main() 
{
    int tam = 25; char ano[tam];
    printf("Insert number: ");
    input_string(ano, 0, tam);

    if(not check_number(ano)) printf("Numero invalido");
    else solve(ano, strlen(ano), 0);
    
	return 0;
}
