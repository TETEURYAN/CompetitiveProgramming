#include <stdio.h>
#include <stdbool.h>

//1419 - Bakugan

int vetor (int *v, int r, int i) 
{
    scanf("%d", &v[i]);
    if (i == r - 1) return v[i];
    return v[i] + vetor(v, r, i + 1);    
}

void bonus (int *vm, int *vl, int *m, int *l, int r, int i) 
{
    bool validM, validL;
    validM = validL = false;

    if (i == r - 1) return;

    if (vm[i - 1] == vm[i] && vm[i] == vm[i + 1]) 
    {
        *m += 30;
        validM = true;
    }

    if (vl[i - 1] == vl[i] && vl[i] == vl[i + 1]) 
    {
        *l += 30;
        validL = true;
    }

    if (validM || validL) return;
    else bonus(vm, vl, m, l, r, i + 1);

}

void inputs (int r) {
    int m, l, vm[r], vl[r];;
    m = l = 0;

    m = vetor(vm, r, 0);
    l = vetor(vl, r, 0);

    if (r > 2) bonus(vm, vl, &m, &l, r, 1);
    printf("%c\n", m > l ? 'M' : (l > m ? 'L' : 'T'));
}

int main () {
    int r;
    scanf("%d", &r);
    return r ? inputs(r), main() : 0;
}
