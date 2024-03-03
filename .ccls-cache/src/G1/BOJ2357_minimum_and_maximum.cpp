#define INF 0x3f3f3f3f
#define IDX_MAX 100007*3
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL arr[IDX_MAX];
LL segMin[IDX_MAX];
LL segMax[IDX_MAX];

void update_min(int idx,int st, int en, int i, LL val);
void update_max(int idx,int st, int en, int i, LL val);

LL add_min(int idx,int st, int en, int l, int r);
LL add_max(int idx,int st, int en, int l, int r);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;

	fill(segMin,segMin+IDX_MAX,INF);
	fill(segMax,segMax+IDX_MAX,-INF);

	for(int i=1;i<=N;i++){
		cin >> arr[i];
		update_min(1,1,N,i,arr[i]);
		update_max(1,1,N,i,arr[i]);
	}

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		cout << add_min(1,1,N,a,b) << " " << add_max(1,1,N,a,b) << "\n";
	}
	
	return 0;
}

void update_min(int idx,int st, int en, int i, LL val){
	segMin[idx] = min(segMin[idx],val);
	if(st==en) return;
	if(i <= (st+en)/2) update_min(idx*2,st,(st+en)/2,i,val);
	else update_min(idx*2+1,(st+en)/2+1,en,i,val);
}

void update_max(int idx,int st, int en, int i, LL val){
	segMax[idx] = max(segMax[idx],val);
	if(st==en) return;
	if(i <= (st+en)/2) update_max(idx*2,st,(st+en)/2,i,val);
	else update_max(idx*2+1,(st+en)/2+1,en,i,val);
}

LL add_min(int idx,int st, int en, int l, int r){
	if(en < l || r < st) return INF;	//return 0 하면 안됨.
	else if(l <= st && en <= r) return segMin[idx];
	else return min(add_min(idx*2,st,(st+en)/2,l,r),add_min(idx*2+1,(st+en)/2+1,en,l,r));
}

LL add_max(int idx,int st, int en, int l, int r){
	if(en < l || r < st) return -INF;	//return 0 하면 안됨.
	else if(l <= st && en <= r) return segMax[idx];
	else return max(add_max(idx*2,st,(st+en)/2,l,r),add_max(idx*2+1,(st+en)/2+1,en,l,r));
}


/*
02:51 문제 분석
10:44 main() 작성 완료.
25:11 함수 4개 작성 완료.
28:47 최솟값 전부 0으로 출력되는 현상 발생, 최솟값을 INF로 초기화.
29:42 테스트 케이스 통과.

240303 29:51
*/