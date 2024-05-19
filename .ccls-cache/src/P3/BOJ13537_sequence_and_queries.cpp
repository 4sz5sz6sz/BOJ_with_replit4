#define IDX_MAX 100007
#include<bits/stdc++.h>
using namespace std;

vector<int> tree[IDX_MAX*4];
int N,M;

void update(int node, int st, int en, int idx, int val);
int query(int node, int st, int en, int l, int r, int k);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=1;i<=N;i++){
		int val;
		cin >> val;
		update(1,1,N,i,val);
	}

	for(int i=1;i<N*4;i++) 
		sort(tree[i].begin(),tree[i].end());

	cin >> M;
	while(M--){
		int i,j,k;
		cin >> i >> j >> k;
		cout << query(1,1,N,i,j,k) << "\n";
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

int query(int node, int st, int en, int l, int r, int k){
	//if(r < st || en < l) return 0;
	if(en < l || r < st) return 0;
	if(l <= st && en <= r){
		/*
		cout << "	node : " << node;
		cout << "	l : " << l;
		cout << "	r : " << r;
		cout << "	k : " << k;
		cout << "	st : " << st;
		cout << "	en : " << en;
		cout << "	data : " << tree[node][0];
		cout << "	ret : " << tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
		cout << "\n";
		*/
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	}
	int mid = (st+en)/2;
	return query(node*2, st, mid, l, r, k) + query(node*2+1, mid+1, en, l, r, k);
}


/*
00:51 Problem Analysis.
10:27 main() Completed.
13:45 update() Completed.
17:38 query() Completed.
27:41 값 추적하기. l r 보정해줘야 할 듯.
30:03 data 출력해보니 확인함.
tree[node].push_back(node);
에서
tree[node].push_back(val);
로 수정..
30:36 TC passed.
240518 30:40
*/