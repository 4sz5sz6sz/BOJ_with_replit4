#define INF 0x3f3f3f3f
#define IDX_MAX 400007
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

	int N;
	cin >> N;

	fill(arr,arr+IDX_MAX,INF);
	
	for(int i=1;i<=N;i++){
		cin >> arr[i];
		update(1,1,N,i,arr[i]);
	}
	arr[0] = INF;
	seg[0] = 0;

	/*
	for(int i=1;i<=N*2-1;i++){
		cout << seg[i] <<" ";
	}
	cout << "\n";
	*/
	
	int M;
	cin >> M;
	for(int i=0;i<M;i++){
		LL a,b,c;
		cin >> a >> b >> c;
		if(a==1){
			update(1,1,N,b,c);
			arr[b]=c;
		}
		else if(a==2){
			cout << find(1,1,N,b,c) << "\n";
		}
	}

	/*
	for(int i=1;i<=N;i++){
		cout << arr[i] <<" ";
	}
	cout << "\n";
	

	for(int i=1;i<=N*2-1;i++){
		cout << seg[i] <<" ";
	}
	cout << "\n";
	*/
	
	return 0;
}

LL update(int node, int st, int en, int i, LL val){
	if(i < st || en < i) return seg[node];//인덱스 범위를 벗어난다면, 일단 0 리턴해보기. 0 대신에 seg[node] 리턴하도록 수정.
	if(st==en){
		// cout << "	st	:	" << st;
		// cout << "	i	:	" << i;
		// cout << "\n";
		seg[node] = st;
		arr[st] = val;
		return st;	//첫 줄과 합칠 수 있음. 나중에 디버깅을 위해 분리함.
	}
	int mid = (st+en)/2;
	int ret1 = update(node*2, st, mid, i, val);
	int ret2 = update(node*2+1, mid+1, en, i, val);
	// cout << "	node	: " << node;
	// cout << "	st	: " << st;
	// cout << "	en	: " << en;
	// cout << "	i	: " << i;
	// cout << "	val	: " << val;
	// cout << "	ret1	: " << ret1;
	// cout << "	ret2	: " << ret2;
	// cout << "	arr[ret1]	: " << arr[ret1];
	// cout << "		arr[ret2]	: " << arr[ret2];
	// cout << "\n\n";
	if(arr[ret1]<=arr[ret2]){
		seg[node] = ret1;
		return ret1;
	}
	else{
		seg[node] = ret2;
		return ret2;
	}
}

LL find(int node, int st, int en, int l, int r){
	if(en < l || r < st) return 0;
	if(l <= st && en <= r) return seg[node];
	int mid = (st+en)/2;
	int ret1 = find(node*2, st, mid, l, r);
	int ret2 = find(node*2+1, mid+1, en, l, r);
	if(arr[ret1]<=arr[ret2]){
		return ret1;
	}
	else{
		return ret2;
	}
}


/*
03:38 문제 분석
08:22 main() 작성 완료.
21:08 update() 작성 완료.
27:19 find() 작성 완료.
27:28 첫 컴파일
29:54 세그멘테이션 폴트
	-> if(l < st && en < r) return seg[node];
		에서
		if(l <= st && en <= r) return seg[node];
		로 수정.

	전부 0으로 출력되는 현상 발생..

41:51 오타 수정.
	int ret2 = update(node*21, mid+1, en, i, val);
	에서
	int ret2 = update(node*2+1, mid+1, en, i, val);
	로 수정.

01:00:38
	fill(arr,arr+IDX_MAX,INF);
	추가하니, 답에 더 근접해짐.

재개
10:56 값 추적 중.

29:35 ret1이 0으로만 리턴되는 현상 발생, 0이 아니라 seg[node]를 리턴해야 함.
if문 문장 순서 위치 2개 스왑시킴.

0 대신 seg[node]를 리턴시킴.

다시 if문 2개 스왑시킴. (출력 결과가 달라짐)

32:21 테스트 케이스 통과.

if문 순서에 따라 출력 결과의 변화를 보임.
update() 과정에서 함부로 0 return 하는 경우 없애기.

240304 01:00:38 + 34:15 이게 왜 맞지?
*/
