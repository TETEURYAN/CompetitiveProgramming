    #include<iostream>
    #include<algorithm>
     
    using namespace std;
     
    int main(){
        vector<int> a(8);
        
        for(int &i : a)
            cin >> i;
     
        for(int i : a){
            if((i!=1) and (i != 0)){
                cout << "F" << endl;
                return 0;
            }
        }
        cout << "S" << endl;
    }