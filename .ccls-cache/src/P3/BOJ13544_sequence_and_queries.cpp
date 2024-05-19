#define IDX_MAX 100007
#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> tree[IDX_MAX*4];

void update(int node, int st, int en, int idx, int val);
int query(int node, int st, int en, int l, int r, int val);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=1;i<=N;i++){
		int num;
		cin >> num;
		update(1,1,N,i,num);
	}

	for(int i=1;i<4*N;i++){
		sort(tree[i].begin(),tree[i].end());
	}

	cin >> M;
	int _xor = 0;
	while(M--){
		int i,j,k;
		cin >> i >> j >> k;
		i^=_xor;
		j^=_xor;
		k^=_xor;
		//i--; j--;
		_xor = query(1,1,N,i,j,k);
		cout << _xor << "\n";
	}
	
	return 0;
}

void update(int node, int st, int en, int idx, int val){
	if(idx < st || en < idx) return;
	tree[node].push_back(val);
	if(st!=en){
		int mid = (st+en)/2;
		update(node*2,st,mid,idx,val);
		update(node*2+1,mid+1,en,idx,val);
	}
}

int query(int node, int st, int en, int l, int r, int val){
	if(en < l || r < st) return 0;
	if(l <= st && en <= r){
		return tree[node].end() - upper_bound(tree[node].begin(),tree[node].end(),val);
	}
	int mid = (st+en)/2;
	return query(node*2, st, mid, l, r, val) + query(node*2+1, mid+1, en, l, r, val);
}


/*
01:11 Problem Analysis.
07:57 main() Completed.
11:13 update() Completed.
13:43 query() Completed.
15:19 TC passed.
240519 15:23
*/