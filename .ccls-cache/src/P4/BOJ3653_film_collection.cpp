#define IDX_MAX (200002+5)
#include<bits/stdc++.h>
using namespace std;

int T;
int N,M;
int len;

typedef long long ll;

ll tree[IDX_MAX*4+5];
int myPos[IDX_MAX];
int unused;

void Init();
ll update(int node, int st, int en, int idx, ll val);
ll find(int node, int st, int en, int l, int r);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while(T--){
		cin >> N >> M;
		Init();
		
		// for(int i=1;i<=5;i++){
		// 	cout << "	myPos[i] : " << myPos[i];
		// 	cout << "\n";
		// }
		// cout << "\n";

		// for(int i=1;i<=10;i++){
		// 	cout << "	tree[i] : " << tree[i];
		// 	cout << "\n";
		// }
		// cout << "\n";
		
				
		for(int i=0;i<M;i++){
			int curN;
			cin >> curN;

			ll ans = find(1,1,len,myPos[curN]+1,unused-1);
			update(1,1,len,myPos[curN], 0);
			myPos[curN] = unused++;
			update(1,1,len,myPos[curN], 1);
			//unused++;
			cout << ans << " ";
			// cout << "	ans1 : " << ans1;
			// cout << "	ans2 : " << ans2;
			// cout << "\n";
		}
		cout << "\n";
	}
	
	return 0;
}

void Init(){
	len = N+M;
	for(int i=1;i<=N;i++){
		myPos[N+1-i] = i;
	}
	// for(int i=1;i<=N*4;i++){
	// 	tree[i]=0;
	// }
	for(int i=1;i<=N;i++){
		update(1,1,len,i,1);
	}
	for(int i=N+1;i<=len;i++){
		//update(1,N+1,unused-1,i,0);
		update(1,1,len,i,0);
	}
	unused = N+1;
}

ll update(int node, int st, int en, int idx, ll val){
	if(idx < st || en < idx) return tree[node];
	if(st>=en) return tree[node] = val;
	int mid = (st+en)/2;
	return tree[node] = update(node*2,st,mid,idx,val) + update(node*2+1,mid+1,en,idx,val);
}

ll find(int node, int st, int en, int l, int r){
	if(en < l || r < st) return 0;
	//if(st <= l && r <= en) return tree[node];
	if(l <= st && en <= r) return tree[node];
	if(st>=en) return tree[node];
	int mid = (st+en)/2;
	return find(node*2,st,mid,l,r) + find(node*2+1,mid+1,en,l,r);
}


/*
05:40 Problem Analysis.
11:47 main(), Init() Completed.
22:45 update() Completed.
24:35 find() Completed.
01:03:32 find 조건문 오류..

if(st <= l && r <= en) return tree[node];
에서
if(l <= st && en <= r) return tree[node];
로 수정...

01:04:56 TC passed.

WA...

01:24:43
2*N에서 len으로 변경.

맞았습니다!!
#define IDX_MAX(200002+5)
괄호 안 씌워서 OOB 오류 났었던 것.

240823 01:30:49
*/