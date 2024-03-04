#define IDX_MAX 400007
#define INF 123456987654321ll
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

// LL dp[IDX_MAX];
LL arr[IDX_MAX];
LL seg[IDX_MAX];

LL update(int node, int st, int en, int i, LL val);
LL find(int node, int st, int en, int l, int r);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,D;
	cin >> N >> D;

	// fill(dp,dp+IDX_MAX,-INF);
	fill(arr,arr+IDX_MAX,-INF);
	fill(seg,seg+IDX_MAX,-INF);

	for(int i=1;i<=N;i++){
		cin >> arr[i];
		//arr[i]=1000000001;
		update(1,1,N,i,arr[i]);
		// cout << i << ":	"<< find(1,1,N,i,i);
		// cout << "\n";
	}

	//update(1,1,N,1,arr[1]);	중복된 코드
	for(int cur=2;cur<=N;cur++){
		int prev = max(1, cur-D);	//1이 맞나?
		LL val = max(find(1,1,N,prev,cur-1), 0ll) + arr[cur];
		// cout << "	prev :	" << prev;
		// cout << "	cur :	" << cur;
		// cout << "	val :	" << val;
		// cout << "\n";
		update(1,1,N,cur,val);
	}

	/*
	for(int i=1;i<=N;i++){
		cout << find(1,1,N,i,i) << " ";
	}
	cout << "\n";
	*/

	cout << find(1,1,N,1,N) << "\n";
	
	return 0;
}

LL update(int node, int st, int en, int i, LL val){
	if(i < st || en < i) return seg[node];
	if(st==en){
		return seg[node] = val;
	}
	int mid = (st+en)/2;

	/*
	cout << "	node :	" << node;
	cout << "	st :	" << st;
	cout << "	en :	" << en;
	cout << "	i :	" << i;
	cout << "	val :	" << val;
	cout << "	mid :	" << mid;
	cout << "	seg[node] :	" << seg[node];
	cout << "\n";
	*/
	
	return seg[node] = max(update(node*2, st, mid, i, val), update(node*2+1, mid+1, en, i, val));
}

LL find(int node, int st, int en, int l, int r){
	if(en < l || r < st) return -INF;	//최댓값이 절대 아닌 숫자를 return.
	if(l <= st && en <= r) return seg[node];
	int mid = (st+en)/2;
	return max(find(node*2, st, mid, l, r), find(node*2+1, mid+1, en, l, r));
}


/*
07:57 문제 분석
23:46 main() 작성 완료.
27:54 update() 작성 완료.
30:44 find() 작성 완료.
34:44 첫 컴파일
	-> 테스트 케이스 오답.. 2출력.
43:16 seg[]에서 실제 값은 N~2N-1이 아니다. 그냥 find(1,1,N,1,N) 써서 ans 출력하기.

01:11:54
	return max(update(node*2, st, mid, i, val), update(node*2+1, st, mid, i, val));
	에서
	return seg[node] = max(update(node*2, st, mid, i, val), update(node*2+1, mid+1, en, i, val));
	로 수정...
말도 안되는 실수를 2개 함...

1. seg[node] 값을 갱신 안하는 현상 수정.
2. 오른쪽 자식 노드로 갈 때, st <- mid+1, en <- en 으로 수정.

01:13:16 테스트 케이스 2개 통과.

틀렸습니다...

01:35:56
N이 10만일 때, 세그멘테이션 폴트 발생.
IDX_MAX를 400007으로 대폭 증가시켜서 해결함.

240304 01:36:24
*/