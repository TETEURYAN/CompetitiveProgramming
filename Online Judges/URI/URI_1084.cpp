#include <cstdio>
#include <ciso646>
#include <iostream>
#include <algorithm>
#include<cstring>

using namespace std;

#define max 100001

char arr[max];

int main(){
	int ans,i,n,peek,last;
	char letter;
	
	while((cin >> n >> ans) and (n or ans)){
		peek = 0;
		last = n-ans;
		for (i = 0; i < n; i++){
			cin >> letter;
			while (peek and ans and arr[peek-1]<letter)
				peek--,ans--;
			arr[peek++]=letter;
		} 
		arr[last]='\0';
		cout << arr << "\n";
	}
}
