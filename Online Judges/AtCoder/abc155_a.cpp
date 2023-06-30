#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <iso646.h>

typedef long long int lli;

void main(){
    int arr[3];
    for(int i = 0; i < 3; i++)
        scanf("%d", &arr[i]);
    
    int ans = 0;
    for(int i = 0; i < 3; i++)
        for(int j = i+1; j < 3; j++)
            if(arr[i] == arr[j])
                ans++;
    printf("%s", ans == 1 ? "Yes\n" : "No\n");
    
}