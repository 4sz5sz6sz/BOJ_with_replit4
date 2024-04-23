#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> A;
vector<int> dist;

void BFS(int start);

int solution(string begin, string target, vector<string> words){
	int st=-1;
	int en=-1;
	words.push_back(begin);
	N = words.size();
	A.resize(N+1);
	dist.resize(N+1,INF);
	int len = words[0].length();

	//Set st, en
	for(int i=0;i<N;i++){
		if(words[i] == begin) st = i;
		else if(words[i] == target) en = i;
	}
	
	//Set Graph.
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			string s1 = words[i];
			string s2 = words[j];
			int diff = 0;
			for(int k=0;k<len;k++){
				if(s1[k] != s2[k]) diff++;
			}
			if(diff==1){
				A[i].push_back(j);
				A[j].push_back(i);
			}
		}
	}

	BFS(st);

	if(en == -1) return 0;
	
	int ret = dist[en];
	if(ret == INF) ret = 0;
	return ret;
}

void BFS(int start){
	queue<int> Q; Q.push(start);
	dist[start] = 0;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int next:A[cur]){
			//if(dist[next] != INF) continue;
			if(dist[cur] + 1 >= dist[next]) continue;
			dist[next] = dist[cur] + 1;
			Q.push(next);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	
	return 0;
}



/*
03:35 Problem Analysis.
10:32 solution() Completed.
11:55 BFS() Completed.
20:52 words.push_back(begin); 추가.
문제 조건에 의해, words에는 begin가 없어도 된다..

블로그에서 오개념 발견
https://prmblogs.tistory.com/39
length()의 시간복잡도는 O(N)이다? (X)

240422 21:26
*/