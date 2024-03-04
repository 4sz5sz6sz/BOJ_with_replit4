//8192
#define IDX_MAX 8200
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

bool vis[IDX_MAX+1];
int A[IDX_MAX][IDX_MAX];
int numOfAvail;
int maxD;
int depthOfLastV;
int V;
int maxDiv;

LL POW(int a, int b);
void DFS(int curNode, int depth, int cntOfDiv);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int D,N,U,T;
	cin >> D >> N >> U >> T;
	V = (1<<D)-1;
	//길목 만들기
	for(int i=1;i<=(1<<(D-1))-1;i++){
		A[i][i*2] = 1;
		A[i][i*2+1] = 1;
	}

	//길목 파괴시키기
	for(int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		A[a][b] = 0;
	}

	DFS(1,1,0);

	int ans1 = U*(maxD-1) + maxDiv*(maxDiv+1)/2*T;
	int ans2 = 2 * U * (numOfAvail-1) - (depthOfLastV-1)*U;

	cout << "	maxDiv :	" << maxDiv;
	cout << "	depthOfLastV :	" << depthOfLastV;
	cout << "	numOfAvail :	" << numOfAvail;
	cout << "	maxD :	" << maxD;
	cout << "	ans1 :	" << ans1;
	cout << "	ans2 :	" << ans2;
	cout << "\n";
	
	if(ans1<ans2)
		cout << ":blob_twintail_aww:";
	else if(ans1>ans2)
		cout << ":blob_twintail_sad:";
	else
		cout << ":blob_twintail_thinking:";
	
	return 0;
}

LL POW(int a, int b){
	int ret = 1;
	while(b--){
		ret*=a;
	}
	return ret;
}

void DFS(int curNode, int depth,int cntOfDiv){
	if(vis[curNode])
		return;
	vis[curNode]=true;
	numOfAvail++;
	depthOfLastV=depth;
	
	if(depth > maxD)
		maxD = depth;
	if(cntOfDiv > maxDiv)
		maxDiv = cntOfDiv;

	if(A[curNode][curNode*2] && A[curNode][curNode*2+1]) cntOfDiv++;
	
	if(A[curNode][curNode*2])
		DFS(curNode*2,depth+1,cntOfDiv);
	if(A[curNode][curNode*2+1])
		DFS(curNode*2+1,depth+1,cntOfDiv);
	
	
}

/*
36:54 문제 분석
47:51 main() 작성 완료.
55:02 DFS() 작성 완료. 첫 컴파일
01:15:54 테스트 케이스 1 오답. maxDiv 도입.1
01:19:22 테스트 케이스 3개 통과.
240303 01:19:27
*/