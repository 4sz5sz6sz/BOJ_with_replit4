#define MIN first
#define COST second
#define IDX_MAX 8
#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Node;
int N,M,K;
int ans;

int isused[IDX_MAX];
vector<Node> arr;
vector<Node> input;

void Backtracking(int cur);
void func();

int solution(int k, vector<vector<int>> dungeons) {
	//int answer = -1;
	ans = 0;

	N = dungeons.size();
	M = N; K = k;
	arr.resize(N);
	for(int i=0;i<N;i++){
		input.push_back({dungeons[i][0],dungeons[i][1]});
	}

	Backtracking(0);

	return ans;
}

void Backtracking(int cur){
	if(cur>=M){
		func();
		return;
	}
	for(int i=0;i<N;i++){
		if(!isused[i]){
			arr[cur]=input[i];
			isused[i]=1;
			Backtracking(cur+1);
			isused[i]=0;
		}
	}
}

void func(){
	int curHP = K;
	int cnt=0;
	for(int i=0;i<N;i++){
		Node cur = arr[i];
		if(curHP >= cur.MIN){
			curHP-=cur.COST;
			cnt++;
		}
	}
	ans = max(ans,cnt);
}

/*
16:14 main(), Backtracking() Completed.
21:49 func() Completed.
240507 
*/