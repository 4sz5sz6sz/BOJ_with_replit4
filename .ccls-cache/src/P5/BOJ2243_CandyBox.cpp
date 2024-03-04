#define IDX_MAX 1000007
#include<bits/stdc++.h>
using namespace std;
typedef int LL;	//안전하게 int로 변경.
LL arr[IDX_MAX*4];
LL seg[IDX_MAX*4];

LL update(int node, int st, int en, int i, LL val);
LL find(int node, int st, int en, int l, int r);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for(int i=0;i<N;i++){
		LL a,b,c;
		cin >> a;

		//사탕 꺼내기
		if(a==1){
			cin >> b;
			//int target = b;
			int st = 1;
			int en = 1000000;
			while(st<en){
				int mid = (st+en)/2;
				LL curRank = find(1,1,1000000,1,mid);
				if(curRank >= b)	//성공
					en = mid;
				else	//실패
					st = mid+1;
			}
			cout << en << "\n";
			update(1,1,1000000,en,arr[en]-1);
			arr[en]--;
		}

		//사탕 넣기
		else if(a==2){
			cin >> b >> c;
			update(1,1,1000000,b,arr[b]+c);
			arr[b]+=c;
			//cout << "	arr[b] : "<<  arr[b] << "\n";
		}

		/*
		for(int i=1;i<=3;i++){
			cout << "	arr[i]	:	" << arr[i];
		}
		cout << "\n";
		*/
		
	}

	
	return 0;
}

LL update(int node, int st, int en, int i, LL val){
	if(i < st || en < i) return seg[node];
	if(st==en) return seg[node] = val;
	int mid = (st+en)/2;
	return seg[node] = update(node*2,st,mid,i,val) + update(node*2+1,mid+1,en,i,val);
}

LL find(int node, int st, int en, int l, int r){
	if(en < l || r < st) return 0;	//덧셈의 항등원
	if(l <= st && en <= r) return seg[node];
	int mid = (st+en)/2;
	return find(node*2,st,mid,l,r) + find(node*2+1,mid+1,en,l,r);
}


/*
17:00+09:07 문제 분석
19:24 main() 작성 완료.
22:01 update() 작성 완료.
25:12 find() 작성 완료. 첫 컴파일

26:57 테스트 케이스 오답.. 1000000만 출력됨..

34:35 
	return update(node*2,st,mid,i,val) + update(node*2+1,mid+1,en,i,val);
	에서
	return seg[node] = update(node*2,st,mid,i,val) + update(node*2+1,mid+1,en,i,val);
	로 수정.
	아무래도 자주하는 실수인 듯.
	1 2 2 출력됨. 답에 근접하는 중.

39:16
	arr[st]--; 추가.

53:38 
	while(st<en) 대신 while(st<=en) 쓰는게 더 안전하다고 판단.
55:23 테스트 케이스 통과.
틀렸습니다...

01:08:32 일부 자료형을 LL로 변경.

01:23:09 st,en 변경함. en 출력하도록 변경. 테스트 케이스 통과.

01:27:10 포기..

01:56:25 어이없는 실수 발견함.
LL curRank = find(1,1,N,1,mid);
에서
LL curRank = find(1,1,1000000,1,mid);
로 변경해야 함...

도움을 받은 것은, 테스트 케이스
2
2 3 5
1 1
출력결과
1000000
이였음.

N은 내가 스스로 찾아냄.

240304 17:00+01:57:50
*/