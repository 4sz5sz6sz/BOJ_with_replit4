#define IDX_MAX 200007
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tree[IDX_MAX*4];
int N,M;

ll UPDATE(int node, int st, int en, int idx, ll val);
ll QUERY(int node, int st, int en, int l, int r);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for(int i=1;i<=N;i++){
		UPDATE(1,1,N,i,1);
	}

	while(M--){
		int comm,num;
		cin >> comm;
		if(comm == 1){
			cin >> num;
			UPDATE(1,1,N,num,0);
		}
		else if(comm == 2){
			cin >> num;
			UPDATE(1,1,N,num,1);
		}
		else{
			cout << QUERY(1,1,N,1,N) << "\n";
		}
	}
	
	return 0;
}

ll UPDATE(int node, int st, int en, int idx, ll val){
	if(idx < st || en < idx) return tree[node];
	if(st == en) return tree[node] = val;
	int mid = (st+en)/2;
	return tree[node] = UPDATE(node*2,st,mid,idx,val) + UPDATE(node*2+1,mid+1,en,idx,val);
	
}

ll QUERY(int node, int st, int en, int l, int r){
	if(en < l || st > r) return 0;
	if(l <= st && en <= r) return tree[node];
	int mid = (st+en)/2;
	return QUERY(node*2,st,mid,l,r) + QUERY(node*2+1,mid+1,en,l,r);
}


/*
02:34 Problem Analysis.
07:35 main() Completed.
12:33 2 function Completed.
14:46 TC passed.
240525 14:51
*/