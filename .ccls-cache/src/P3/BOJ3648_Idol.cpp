#define IDX_MAX 2007
#include<bits/stdc++.h>
using namespace std;

int N,M;
stack<int> S;
vector<vector<int>> A;
vector<vector<int>> revA;
vector<vector<int>> grp;
vector<int> vis;
vector<int> v2grp;
int cntOfGroup;

void Init();
void SCC();
void DFS(int cur);
void rev_DFS(int cur);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//int T=2;
	//T--
	while(cin >> N >> M){
		//cin >> N >> M;
		Init();
		for(int i=0;i<M;i++){
			int a,b;
			cin >> a >> b;
			int aIdx = a>0 ? a : N-a;
			int bIdx = b>0 ? b : N-b;
			int negAIdx = a>0 ? N+a : -a;
			int negBIdx = b>0 ? N+b : -b;
			A[negAIdx].push_back(bIdx);
			A[negBIdx].push_back(aIdx);
			revA[bIdx].push_back(negAIdx);
			revA[aIdx].push_back(negBIdx);
		}
		// A[1].push_back(N+1);
		// A[N+1].push_back(1);
		// revA[N+1].push_back(1);
		// revA[1].push_back(N+1);

		SCC();

		int ans=1;
		for(int i=1;i<=N;i++){
			if(v2grp[i] == v2grp[i+N]){
				ans=0;
				//cout << "no\n";
				break;
			}
			
			//else if(v2grp[i] > v2grp[i+N])
		}
		if(v2grp[1] < v2grp[1+N])	//state[1] == F
			ans = 0;
		
		if(ans==1)
			cout << "yes\n";
		else if(ans==0)
			cout << "no\n";
	}

	return 0;
}

void Init(){
	A.clear();
	revA.clear();
	grp.clear();
	v2grp.clear();
	vis.clear();
	
	A.resize(2*N+1);
	revA.resize(2*N+1);
	v2grp.resize(2*N+1);
	vis.resize(2*N+1);
	cntOfGroup=0;
}

void SCC(){
	for(int i=1;i<=2*N;i++){
		DFS(i);
	}

	vis.clear();
	vis.resize(2*N+1);
	
	while(!S.empty()){
		int cur = S.top(); S.pop();
		if(!vis[cur]){
			grp.push_back(vector<int>());
			rev_DFS(cur);
			//sort(grp[curOfGroup].begin(),grp[curOfGroup].end());
			cntOfGroup++;
		}
	}
}

void DFS(int cur){
	if(vis[cur])
		return ;
	vis[cur]=1;
	for(int next:A[cur])
		DFS(next);
	S.push(cur);
}

void rev_DFS(int cur){
	if(vis[cur])
		return ;
	vis[cur]=1;

	grp[cntOfGroup].push_back(cur);
	v2grp[cur]=cntOfGroup;
	
	for(int next:revA[cur])
		rev_DFS(next);
}

/*
06:57 문제 분석
11:57 Init() 작성 완료.
17:37 Init() 재작성 완료.
25:34 main() 작성 완료.
30:40 SCC() 작성 완료.
34:00 DFS 함수 2개 작성 완료.
34:27 첫 컴파일
35:40 세그멘테이션 폴트 발생..
x -> neg x으로 가는 경로가 있을 때, 위상정렬 조건 하다가 stop.
자정 STOP.

재개

06:08 
	// A[1].push_back(N+1);
	// A[N+1].push_back(1);
	// revA[N+1].push_back(1);
	// revA[1].push_back(N+1);
이 문장은 넣으면 안됨. 오작동함.
	if(v2grp[1] < v2grp[1+N])	//state[1] == F
해당 문장 삽입하여 T or F 판정함.

08:03 테스트 케이스 통과.


240309  35:40+08:03
*/