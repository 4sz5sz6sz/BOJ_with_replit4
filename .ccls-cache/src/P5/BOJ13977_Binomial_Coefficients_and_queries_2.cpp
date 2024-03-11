#define IDX_MAX 4000000
#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL seg[0*4+1];
LL arr[IDX_MAX+1];

// LL update(int node, int st, int en, int idx, LL value);
// LL find(int node, int st, int en, int l, int r);
LL POW(LL a, LL b, LL MMM);
LL INV(LL b, LL MMM);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	arr[0]=1;
	for(int i=1;i<=IDX_MAX;i++){
		arr[i]=arr[i-1]*i%MOD;
		//cout << update(1,1,IDX_MAX,i,arr[i]) << "\n";
		//update(1,1,IDX_MAX,i,i);
	}
	
	for(int i=0;i<T;i++){
		int n,r;
		cin >> n >> r;
		//if(b==0) b=a;
		//LL A = find(1,1,IDX_MAX,a-b+1,a);
		//LL B = INV(find(1,1,IDX_MAX,1,b),MOD);
		LL A = arr[n];
		LL B = arr[n-r];
		LL C = arr[r];
		// cout << "	A : " << A;
		// cout << "	B : " << B;
		// cout << "\n";

		LL ans = A * INV(B,MOD) % MOD;
		ans = ans * INV(C,MOD) % MOD;
		cout << ans << "\n";
	}
	
	return 0;
}

LL update(int node, int st, int en, int idx, LL value){
	if(idx < st || en < idx) return seg[node];
	if(st==en) return seg[node] = value;
	int mid = (st+en)/2;
	return seg[node] = (update(node*2,st,mid,idx,value) * update(node*2+1,mid+1,en,idx,value))%MOD;
}

LL find(int node, int st, int en, int l, int r){
	if(en < l || r < st) return 1;
	if(l <= st && en <= r) return seg[node];
	int mid = (st+en)/2;
	return (find(node*2,st,mid,l,r) * find(node*2+1,mid+1,en,l,r))%MOD;
}

LL POW(LL a, LL b, LL MMM){
	LL ret=1;
	for(;b;b>>=1,a=(a*a)%MMM)
		if(b & 1)
			ret = (ret*a)%MMM;
	return ret;
}

LL INV(LL b, LL MMM){
	return POW(b,MMM-2,MMM);
}


/*
02:26 문제 분석
05:33 전역변수 작성 완료
14:33 main() 작성 완료
19:35 update() find() 작성 완료.
21:39 POW() INV() 작성 완료.

22:58 테스트 케이스 오답.. 전부 0 출력..

if(node < st || en < node) return seg[node];
에서
if(idx < st || en < idx) return seg[node];
로 수정..

29:12 테스트 케이스 통과

틀렸습니다..

32:42 IDX_MAX을 100000 -> 4000000*4로 늘리기

시간초과...

1000000*88

값의 대칭성을 이용하여 연산횟수를 줄이기?

41:08 애초에 세그먼트 트리가 아닐 수도 있다.
세그먼트 트리 다 날리기.

46:02 완성
-> 테스트 케이스 통과

240311 47:24
*/