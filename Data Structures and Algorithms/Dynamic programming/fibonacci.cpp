#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

/* How to use dynamic programming to solve a fibonacci recursive problem*/

vector<int> mem; //init the memorize vector of fib(n)

int fib(int n){
    mem[0] = 0; //init the first position
    mem[1] = 1; //init the second position

    for(int i = 2; i <= n; i++)  //for to calculate and memorizate any fib(n) in the vector
        if(mem[i] == -1)//if mem[fib(n)] is -1, not calculated yet
            mem[i] = mem[i-1] + mem[i-2];
    return mem[n]; //return the fib(n)
}

int main(){
    int ans;
    cout << "Insert a number n to find fibonacci(n) : ";
    cin >> ans;
    mem.resize(ans + 1, -1);
    system("clear");
    cout << fib(ans) << "\n";
    return 0;
}