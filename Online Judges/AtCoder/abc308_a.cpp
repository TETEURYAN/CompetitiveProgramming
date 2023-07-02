    #include<bits/stdc++.h>
     
    using namespace std;
     
    int main(){
        ios_base::sync_with_stdio(false);
     
        cin.tie(NULL);
     
        vector<int> arr(8);
        bool ans = true;;
        for(int &i : arr){
            cin >> i;
            if(i%25 != false or (i < 100 or i > 675)) ans = false;
        }
     
        for(int i = 0; i < 7; i++){
            if(arr[i] <= arr[i+1])
                continue;
            else
                ans = false;          
        }   
        printf("%s\n", ans ? "Yes" : "No");
     
        return 0;    
    }
