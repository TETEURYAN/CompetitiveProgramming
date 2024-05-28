# Busca Binária

A busca binária é um algoritmo eficiente para encontrar um elemento em uma lista ordenada ou em abordagens que maximizam ou minimizam problemas que também apresentam estruturas ordenadas.

``` c

    long long l = 0,r = 1e9 + 1;

    while(l < r){
        long long mid = (l+r) >> 1;

        if(not condition(mid)) r = mid + 1;
        else l = mid;
    }
```