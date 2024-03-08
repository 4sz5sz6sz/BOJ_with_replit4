#define IDX_MAX 20007
#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> A;
vector<vector<int>> revA;
vector<int> vis;
vector<vector<int>> grp;	//group to vertex
vector<int> v2grp;	//vertex to group
int groupOfCnt;
stack<int> S;

void DFS(int cur);
void rev_DFS(int cur);
void SCC();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	A.resize(2*N+1);
	revA.resize(2*N+1);
	vis.resize(2*N+1);
	v2grp.resize(2*N+1);

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;

		/*
		if(a==-b){
			cout << "0\n";
			return 0;
		}
		*/
		

		int AIdx = (a > 0 ? a : N-a);
		int BIdx = (b > 0 ? b : N-b);
		int negAIdx = (a > 0 ? N+a : -a);
		int negBIdx = (b > 0 ? N+b : -b);
		/*
		cout << "	i : " << i;
		cout << "	a : " << a;
		cout << "	b : " << b;
		cout << "	AIdx : " << AIdx;
		cout << "	BIdx : " << BIdx;
		cout << "	negAIdx : " << negAIdx;
		cout << "	negBIdx : " << negBIdx;
		cout << "\n";
		*/
		A[negAIdx].push_back(BIdx);
		A[negBIdx].push_back(AIdx);
		revA[BIdx].push_back(negAIdx);
		revA[AIdx].push_back(negBIdx);
	}

	SCC();

	vector<int> state(2*N+1,-1);
	for(int i=1;i<=N;i++){
		if(v2grp[i] == v2grp[i+N]){
			cout << "0\n";
			return 0;
		}
//		cout << "	v2grp[i] : " << v2grp[i];
	//	cout << "	v2grp[i+N] : " << v2grp[i+N];
	//	cout << "\n";
		state[i] = (v2grp[i] > v2grp[i+N]);
	}

	//sort(grp.begin(),grp.end());
	/*
	cout << groupOfCnt << "\n";
	for(int i=0;i<groupOfCnt;i++){
		for(int j=0;j<grp[i].size();j++)
			cout << grp[i][j] << " ";
		cout << "-1\n";
	}
	*/

	cout << "1\n";

	
	for(int i=1;i<=N;i++)
		cout << state[i] << " ";
	
	
	return 0;
}

void DFS(int cur){
	if(vis[cur])
		return;
	vis[cur]=1;

	for(int next:A[cur])
		DFS(next);

	S.push(cur);
}

void rev_DFS(int cur){
	//if(cur==6) cout << "	*cur :	" << cur;
	if(vis[cur])
		return ;
	vis[cur]=1;
	//if(cur==6) cout << "	**cur :	" << cur;
	// cout << "	cur :	" << cur << "\n";
	// cout << "	groupOfCnt :	" << groupOfCnt << "\n";

	grp[groupOfCnt].push_back(cur);
	v2grp[cur]=groupOfCnt;
	
	for(int next:revA[cur]){
		// cout << "	cur :	" << cur;
		// cout << "	next :	" << next << "\n";
		rev_DFS(next);
	}
}

void SCC(){
	for(int i=1;i<=2*N;i++)
		DFS(i);

	vis.clear(); vis.resize(2*N+1,0);
	//cout << "	S.size() :	" << S.size() << "\n";
	
	//for(int i=1;i<=2*N;i++){
	while(!S.empty()){
		if(!vis[S.top()]){
			grp.push_back(vector<int>());
			rev_DFS(S.top()); 
			sort(grp[groupOfCnt].begin(),grp[groupOfCnt].end());
			groupOfCnt++;
		}
		S.pop();
	}
}


/*
04:28 문제 분석
18:48 main() 작성 완료.
25:13 SCC() 작성 완료.
30:05 DFS() rev_DFS() 작성 완료.
30:27 첫 컴파일
	-> 세그멘테이션 폴트

30분째 값 추적..

01:06:09
state[i] = (v2grp[i] < v2grp[i+N]);
에서
state[i] = (v2grp[i] > v2grp[i+N]);
로 수정.

반례 발견, 1 1 -1 1

01:11:30 테스트 케이스 통과?

2-SAT - 4 풀다가 포기. 2-SAT - 3 으로 대신 제출.

재개 +38:07
올바르지 않은, 이상한 예외처리를 함..
	1 1 -1 1은 반례가 아니다!
	애초에, 올바른 코드를 30분만에 작성했었음..
	
240308 01:14:36 + 38:07
*/