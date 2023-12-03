#include <bits/stdc++.h>
using namespace std;

const int n = 2e3;

int segtree[4*n];

int arr[n];

void build(int i, int left, int right, int arr[], int segtree[]) {
	if (left == right) 
		segtree[i] = arr[left];
	else{
		int m = (left+right)/2;
		build(2*i, left, m, arr, segtree);
		build(2*i+1, m+1, right, arr,  segtree);
		segtree[i] = segtree[2*i] + segtree[2*i+1];
	}
}

int consulta(int i, int left, int right, int query_left, int query_right) {
	if (query_left <= left and right <= query_right) 
        return segtree[i];
	if (query_right < left or right < query_left) 
        return 0;
	int m = (left+right)/2;
	return consulta(2*i, left, m, query_left, query_right) + consulta(2*i+1, m+1, right, query_left, query_right);
}

void update(int i, int left, int right, int pos, int value) {
	if (left == right) {
		segtree[i] = value;
	} else {
		int m = (left+right)/2;
		if (pos <= m) 
            update(2*i, left, m, pos, value);
		else 
            update(2*i+1, m+1, right, pos, value);
		segtree[i] = segtree[2*i] + segtree[2*i+1];
	}
}

