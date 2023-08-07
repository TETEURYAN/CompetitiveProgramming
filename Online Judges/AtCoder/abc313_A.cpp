    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main(){
      int N;
      while(scanf("%d", &N) > 0){
        int P[N];
        for(int i = 0; i < N; i++){
          scanf("%d", &P[i]);
        }
        printf("%d\n", max(0, *max_element(P+1, P+N) + 1 - P[0]));
      }
    }
