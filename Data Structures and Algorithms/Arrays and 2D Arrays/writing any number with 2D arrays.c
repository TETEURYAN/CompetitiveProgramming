#include <stdio.h>

void PrintNumberPartTwo(int m); 
void PrintNumberPartOne(int n, int i);

int main() 
{
    int ano;
    scanf("%d",  &ano);
    PrintNumberPartOne(ano, 0);

	return 0;
}

char PrefixCentena[11][20] = {"", "c", "duz", "trez", "quatroc", "quinh", "seisc", "setec", "oitoc", "novec"};
char PrefixOnly10[10][20] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
char Dezenas[10][20] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
char Digits[10][20] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};

void PrintNumberPartTwo(int m)
{
    if(m < 10) printf("%s", Digits[m-1]);
    if(m >= 10 && m < 20) printf("%s", PrefixOnly10[ m%10]);
    if(m> 19 && !(m%10)) printf("%s", Dezenas[m/10 - 2]);
    if(m > 20 && m%10 != 0) printf("%s e %s", Dezenas[m/10 - 2], Digits[(m%10) - 1]);
}

void PrintNumberPartOne(int n, int i)
{
  if (n >= 1000)
  {
    if (n >= 2000) PrintNumberPartOne(n / 1000, 0);
    printf("mil ");
    PrintNumberPartOne(n % 1000, 1);
  }
  else if (n >= 100)
  {
    if(n == 100) printf("e cem"); 
    else
    {
        if(n == 900) printf("e ");
        printf("%sento%s", PrefixCentena[n / 100], n <= 199 ? " " : "s ");
        PrintNumberPartOne(n % 100, 1);
    }
  }
  else if (n >= 10)
  {

    if (n <= 19) printf("e %s ", PrefixOnly10[n % 10 ]);
    else if( n > 19)
    {
        if(n < 10) printf("e %s", Digits[n-1]);
        if(n >= 10 && n < 20) printf("e %s", PrefixOnly10[ n%10]);
        if(n> 19 && !(n%10)) printf("e %s", Dezenas[n/10 - 2]);
        if(n >= 20 && (n%10)!= 0) printf("e %s e %s", Dezenas[n/10 - 2], Digits[(n%10)-1]);
    }
  }
  else if (n < 10 && n && i)
  {
    printf("e %s ", Digits[n-1]);
  }
  
  else if (n < 10 && !i)
  {
    printf("%s ", Digits[n-1]);
  }
}


