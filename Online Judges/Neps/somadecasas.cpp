#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, x = 0;
    cin >> n;
    vector<int>v(n, x);
    while(x < n)
        cin >> v[x], x++;
    
    cin >> k;

    int i = 0, j = n - 1;
    while(i < j) {
        int ans = v[i] + v[j];
        if(ans == k) {
            cout << v[i] << " " << v[j] << endl;
            break;
        } 
		else if (ans > k) j--;
        else i++;
    }
}