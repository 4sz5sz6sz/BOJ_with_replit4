#define IDX_MAX 300001
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll H[IDX_MAX];
ll A[IDX_MAX];
ll B[IDX_MAX];
ll DP[IDX_MAX];
ll tree[IDX_MAX*4];

ll find(int node, int st, int en, int l, int r);
ll update(int node, int st, int en, int idx, ll val);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> H[i];
	}

	for(int i=2;i<=N;i++){
		cin >> A[i];
	}

	for(int i=2;i<=N;i++){
		cin >> B[i];
	}

	for(int i=2;i<=N;i++){
		int st = 1;
		int en = i-1;
		int mid=(st+en)/2;
		while(st<=en){
			mid = (st+en)/2;
			if(H[mid] >= H[i] + B[i])
				st = mid+1;
			else
				en = mid-1;
		}
		if(en <= 0) continue;
		DP[i] = find(1,1,N,1,en) + A[i];
		update(1,1,N,i,DP[i]);
	}

	/*
	//FOR DEBUGGING
	for(int i=1;i<=N;i++){
		cout << find(1,1,N,i,i) << " ";
	}
	cout << "\n";
	*/

	cout << find(1,1,N,1,N) << "\n";
	
	return 0;
}

ll find(int node, int st, int en, int l, int r){
	if(en < l || r < st) return 0;
	//if(st>=en) return tree[node];
	if(l<=st && en<=r) return tree[node];
	int mid = (st+en)/2;
	return max(find(node*2,st,mid,l,r), find(node*2+1,mid+1,en,l,r));
}

ll update(int node, int st, int en, int idx, ll val){
	if(idx < st || en < idx) return tree[node];
	if(st>=en) return tree[node] = val;
	int mid = (st+en)/2;
	return tree[node] = max(update(node*2,st,mid,idx,val), update(node*2+1,mid+1,en,idx,val));
}


/*
21:45 Problem Analysis.
25:36 이분탐색 구현 완료.
29:25 main() Completed.
36:15 find() update() Completed.
38:57 TC passed.

240428 39:02
*/