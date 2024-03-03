#define IDX_MAX 1000000
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL seg[(IDX_MAX+1)*3];
LL arr[IDX_MAX+1];

LL add(int idx,int st,int en,int l, int r);
void update(int idx,int st,int en,int i, LL val);

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
			update(1,1,N,b,c-arr[b]);
			arr[b]=c;
		}
		else if(a==2){
			cout << add(1,1,N,b,c) << "\n";
		}
	}
	
	return 0;
}

LL add(int idx,int st,int en,int l, int r){
	// if(idx>IDX_MAX) return 0;
	if(en < l || r < st) return 0;
	else if(l <= st && en <= r) return seg[idx];
	else return add(idx*2,st,(st+en)/2,l,r) + add(idx*2+1,(st+en)/2+1,en,l,r);
}

void update(int idx,int st,int en,int i, LL val){
	// if(idx>IDX_MAX) return;
	seg[idx]+=val;
	if(st==en) return;
	if(i<=(st+en)/2) update(idx*2,st,(st+en)/2,i,val);
	else update(idx*2+1,(st+en)/2+1,en,i,val);
}


/*
09:28 main() 작성 완료.
12:27 add() 작성 완료.
15:52 update() 작성 완료.
17:53 테스트 케이스 통과
27:40 https://restudycafe.tistory.com/371 참고.
int a b c를 LL a b c로 변경.

// if(idx>IDX_MAX) return; 제거하니 정답처리 됨..
seg[]의 최댓값은 IDX_MAX가 아니라, IDX_MAX*2이다!
그러므로, idx의 값은 IDX_MAX가 넘는 경우가 존재한다.

240303 27:40
*/