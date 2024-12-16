#include <bits/stdc++.h>

using namespace std;

void solved()
{
    int n;
    cin >> n;

    vector <int> a(n);
    vector <int> freq(n + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector <int> b(n);

    int aux = n;

    for(int i = 0; i < n; i++)
    {
        if (freq[a[i]] > 0)
        {
            while(aux > 0 && freq[aux] > 0)
                aux--;

            b[i] = aux;
            freq[aux]++;
            aux--;
        }
        else
        {
            b[i] = a[i];
            freq[a[i]]++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << b[i];

        if (i + 1 != n)
        {
            cout << ' ';
        }
        else
        {
            cout << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solved();

    return 0;
}
