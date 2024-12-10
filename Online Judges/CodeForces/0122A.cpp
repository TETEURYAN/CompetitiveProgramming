#include<bits/stdc++.h>

using namespace std;
int main()
{
	vector<int>x = { 4,7,47,74,447,444,44,77,777,774,477,744 };
	int y;
	cin >> y;
	for (int i = 0; i < x.size(); i++)
	{
		if (y % x[i] == 0)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
