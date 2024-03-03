#define MOD 1000000007
#define IDX_MAX 2000007
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL arr[IDX_MAX];
LL seg[IDX_MAX];

LL update(int node, int st, int en, int i, LL val);
LL find(int node, int st, int en, int l, int r);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M,K;
	cin >> N >> M >> K;

	for(int i=1;i<=N;i++){
		cin >> arr[i];
		update(1,1,N,i,arr[i]);
	}

	for(int i=0;i<M+K;i++){
		LL a,b,c;
		cin >> a >> b >> c;
		if(a==1){
			update(1,1,N,b,c);
		}
		else if(a==2){
			cout << find(1,1,N,b,c)%MOD << "\n";
		}
	}

	return 0;
}

LL update(int node, int st, int en, int i, LL val){
	if(st==en) return seg[node] = val;
	int mid = (st+en)/2;
	if(i <= mid) return seg[node] = update(node*2,st,mid,i,val) * seg[node*2+1]%MOD;
	else return seg[node] = seg[node*2] * update(node*2+1,mid+1,en,i,val)%MOD;
}

LL find(int node, int st, int en, int l, int r){
	if(en < l || r < st) return 1;
	if(l <= st && en <= r) return seg[node];
	int mid = (st+en)/2;
	return find(node*2,st,mid,l,r) * find(node*2+1,mid+1,en,l,r) % MOD;
}


/*
00:58 문제 분석
06:21 main() 작성 완료.
16:24 update() 작성 완료.	: 둘 중에 하나만 호출하는 식으로 구현
21:05 find() 작성 완료.

24:16 전부 0으로 출력되는 현상 발생..
	->
	/MOD;
	에서
	%MOD;
	로 수정..


25:57 테스트 케이스 통과.

update()에
	if(idx>end || idx<start) return seg[node]; 
	넣는게 더 최적화 될 듯. 성능은 차이없으나, 가독성&분량에 차이가 있음.
	인덱스 범위 검사는, 일단 방문을 하고 나서 그 뒤에 하기, 
	방문 전 검가 아니라, 방문하자마자 검사하기.

Platinum IV를 찍게 해준 문제.

240303 25:59
*/