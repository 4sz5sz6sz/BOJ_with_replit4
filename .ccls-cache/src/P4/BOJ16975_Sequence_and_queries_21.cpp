#define IDX_MAX 100001
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL seg[IDX_MAX*4];
LL A[IDX_MAX*4];
LL B[IDX_MAX*4];

LL update(int node, int st, int en, int idx, LL val);
LL find(int node, int st, int en, int l, int r);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N;

	for(int i=1;i<=N;i++){
		cin >> A[i];
		B[i] = A[i]-A[i-1];
		// cout << "	B[i] :	" << B[i];
		// cout << "\n";
		update(1,1,N,i,B[i]);
	}
	// //
	// for(int i=1;i<=N;i++){
	// 	cout << find(1,1,N,1,i) << " ";
	// }	
	// cout << "@@\n";
	// //

	cin >> M;

	for(int i=0;i<M;i++){
		LL a,b,c,d;
		cin >> a;

		if(a==1){
			cin >> b >> c >> d;
			update(1,1,N,b,B[b]+d);
			B[b]+=d;
			update(1,1,N,c+1,B[c+1]-d);
			B[c+1]-=d;
		}
		else if(a==2){
			cin >> b;
			cout << find(1,1,N,1,b) << "\n";
		}

		// //
		// for(int i=1;i<=N;i++){
		// 	cout << find(1,1,N,1,i) << " ";
		// }
		// cout << "\n";
		// //
		
	}
	return 0;
}

LL update(int node, int st, int en, int idx, LL val){
	if(idx < st || en < idx) return seg[node];
	if(st==en) return seg[node] = val;
	int mid = (st+en)/2;
	return seg[node] = update(node*2, st, mid, idx, val) + update(node*2+1, mid+1, en, idx, val);
}

LL find(int node, int st, int en, int l, int r){
	if(en < l || r < st) return 0;
	if(l <= st && en <= r) return seg[node];
	int mid = (st+en)/2;
	return find(node*2, st, mid, l, r) + find(node*2+1, mid+1, en, l, r);
}




/*
15:24 문제 분석
20:03 main() 작성 완료.
22:43 update() 작성 완료.
24:07 find() 작성 완료.
25:56 첫 컴파일
테스트 케이스 오답.. 4 4 출력..

44:37
seg[idx];라고 되어있는 3곳을
seg[node]; 로 변경.

45:39 테스트 케이스 통과.

240305 45:44
*/