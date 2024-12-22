#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  set<int> s = {1, 2};
  int out = 3;
  while (n--)
  {
    int x;
    cin >> x;
    if (x == out)
    {
      cout << "NO\n";
      return 0;
    }
    int y = -1;
    for (auto const &i : s)
    {
      if (i != x)
        y = i;
    }
    s.erase(y);
    s.insert(out);
    out = y;
  }
  cout << "YES\n";
  return 0;
}
