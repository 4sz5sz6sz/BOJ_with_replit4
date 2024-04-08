#define INF 0x3f3f3f3f
#define IDX_MAX 100000
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int N;
//int arr[IDX_MAX+1];
LL tree[4*IDX_MAX+1];

LL update(int node, int st, int en, int idx, LL data);
LL find(int node, int st, int en, int l, int r);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	cin >> N;
	
	for(int i=1;i<=N;i++){
		LL num;
		cin >> num;
		update(1,1,N,i,num);
		//cout << "	update : " << update(1,1,N,i,num) << "\n";
		//cout << "	find : " << find(1,1,N,i,i) << "\n";
	}

	

	int M;
	cin >> M;
	for(int i=0;i<M;i++){
		int a,b;
		LL c;
		cin >> a >> b >> c;
		if(a==1){
			update(1,1,N,b,c);
		}
		else{
			cout << find(1,1,N,b,c) << "\n";
		}
	}
	
	return 0;
}

LL update(int node, int st, int en, int idx, LL data){
	/*
	cout << "	**update()**";
	cout << "	st	:	" << st;
	cout << "	en	:	" << en;
	cout << "	node	:	" << node;
	cout << "	tree[node]	:	" << tree[node];
	cout << "\n";
	*/
	
	//if(idx < st || en < idx) return INF;
	if(idx < st || en < idx) return tree[node];
	if(st==en) return tree[node] = data;
	int mid = (st+en)/2;
	return tree[node] = min(update(node*2,st,mid,idx,data), update(node*2+1,mid+1,en,idx,data));
}

LL find(int node, int st, int en, int l, int r){

	/*
	cout << "	**find()**";
	cout << "	st	:	" << st;
	cout << "	en	:	" << en;
	cout << "	node	:	" << node;
	cout << "	tree[node]	:	" << tree[node];
	cout << "\n";
	*/
	
	if(en < l || r < st) return INF;
	if(l <= st && en <= r) return tree[node];
	int mid = (st+en)/2;
	return min(find(node*2,st,mid,l,r), find(node*2+1,mid+1,en,l,r));
}



/*
02:00 Problem Analysis
15:13 main() Completed.
24:34 update() Completed.
29:09 find() Completed.
find에 문제 있음.

~~50:24 포기.~~

+24:21
if(idx < st || en < idx) return INF;
에서
if(idx < st || en < idx) return tree[node];
로 수정.

-> update 과정에서, idx가 st en 범위를 벗어나더라도, 값의 변동에서만 제외시키는 것이지, 비교 대상에서는 제외시키면 안된다. seg[node]를 리턴하여, 반대쪽 자식 노드와 값 비교를 하게끔 해준다.

240408 50:24 + 24:21
*/