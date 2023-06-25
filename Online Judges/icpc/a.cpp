    #include<iostream>
    #include<algorithm>
     
    using namespace std;
     
    int main(){
        int n;
        cin >> n;
     
        string ans;
        cin >> ans;
     
        int a = 0;
        for(int i = 0; i < ans.size(); i++)
            if(ans[i] == 'a' and ans[i+1] == 'a' or ans[i] == 'a' and ans[i-1] == 'a')
                a++;
        cout << a << endl;    
    }