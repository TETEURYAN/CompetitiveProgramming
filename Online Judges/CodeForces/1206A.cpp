#include <bits/stdc++.h>

using namespace std;
vector<int>fa(201, 0);
vector<int>fb(201, 0);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        fa[a[i]]++;
    }

    int m;
    cin >> m;
    vector<int> b(m);

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        fb[b[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i]+b[j] > 200 || (fa[a[i]+b[j]] == 0 && fb[a[i]+b[j]] == 0))
            {
                cout << a[i] << ' ' << b[j] << '\n';
                return 0;
            }
        }
    
    }
    
    return 0;
}
