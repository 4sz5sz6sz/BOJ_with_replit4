#define USED first
#define POS second
#define IDX_MAX 10007
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;
int flag;
int N,M;
int cntOfAirport;
unordered_map<string,int> myIndex;
vector<string> myName(1);   //1-indexed
vector<string> answer;
vector<string> arr;
vector<vector<Node>> A; //USED, POS;
//vector<vector<int>> isused;
//int vis[IDX_MAX];
int st;

void DFS(int cur, int depth);
bool cmp(const Node &a, const Node &b);

vector<string> solution(vector<vector<string>> tickets) {
	M = tickets.size();
	A.resize(IDX_MAX);
	//isused.resize(IDX_MAX);
	for(int i=0;i<M;i++){
		for(int j=0;j<2;j++){
			string s = tickets[i][j];
			if(myIndex[s] == 0){
				myIndex[s] = ++cntOfAirport;
				myName.push_back(s);
				if(s == "ICN")
					st = cntOfAirport;
			}
		}
		int S = myIndex[tickets[i][0]];
		int E = myIndex[tickets[i][1]];
		A[S].push_back({0,E});
		//isused[S].push_back(E);
	}
	N = cntOfAirport;

	for(int i=1;i<=N;i++){
		sort(A[i].begin(),A[i].end(),cmp);
	}

	arr.push_back(myName[st]);
	DFS(st,0);

	return answer;
}

void DFS(int cur, int depth){
	if(depth >= M){
		answer = arr;
		flag=1; //탈출 스위치 On
		return;
	}
	//for(Node next:A[cur]){
	for(int i=0;i<A[cur].size();i++){
		Node next = A[cur][i];
		if(!next.USED){
			arr.push_back(myName[next.POS]);
			A[cur][i].USED = 1;
			DFS(next.POS, depth+1);
			if(flag) return;
			A[cur][i].USED = 0;
			arr.pop_back();
		}
	}
}

bool cmp(const Node &a, const Node &b){
	string s1 = myName[a.POS];
	string s2 = myName[b.POS];
	return s1<s2;
}