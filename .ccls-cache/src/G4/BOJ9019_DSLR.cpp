#define INF 0x3f3f3f3f
#define IDX_MAX 10000
#define COMM first
#define DIST first
#define POS second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;	//COMM POS
typedef pair<int,int> Edge;	//DIST POS

Edge A[IDX_MAX][4];
//Edge revA[IDX_MAX][4];
int dist[IDX_MAX];
Node pre[IDX_MAX];	//COMM, POS
int S,E;

void Init();
int getD(int num);
int getS(int num);
int getL(int num);
int getR(int num);

void Dijkstra(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for(int num=0;num<IDX_MAX;num++){
		A[num][0] = {1,getD(num)};
		A[num][1] = {1,getS(num)};
		A[num][2] = {1,getL(num)};
		A[num][3] = {1,getR(num)};
		/*
		revA[A[num][0]][0] = num;
		revA[A[num][1]][1] = num;
		revA[A[num][2]][2] = num;
		revA[A[num][3]][3] = num;
		*/
	}
	
	while(T--){
		cin >> S >> E;
		Init();
		Dijkstra(S);

		vector<int> ans;
		Node cur = pre[E];
		
		while(cur.POS != S){
			ans.push_back(cur.COMM);
			cur = pre[cur.POS];
		}
		
		ans.push_back(cur.COMM);
		//cout << dist[E];
		reverse(ans.begin(),ans.end());
		for(int tmp:ans){
			if(tmp==0) cout << "D";
			else if(tmp==1) cout << "S";
			else if(tmp==2) cout << "L";
			else cout << "R";
		}
		cout << "\n";
	}
	return 0;
}

void Init(){
	for(int i=0;i<IDX_MAX;i++){
		dist[i] = INF;
	}
	for(int i=0;i<IDX_MAX;i++){
		pre[i] = {0,0};
	}
}

void Dijkstra(int start){
	priority_queue<Edge,vector<Edge>,greater<Edge>> Q; Q.push({0,start});
	dist[start] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(cur.DIST != dist[cur.POS]) continue;
		if(cur.POS == E) return;
		for(int comm = 0; comm<4;comm++){
			Edge next = A[cur.POS][comm];
			if(dist[cur.POS] + next.DIST < dist[next.POS]){
				dist[next.POS] = dist[cur.POS] + next.DIST;
				pre[next.POS] = {comm, cur.POS};
				Q.push({dist[next.POS],next.POS});
			}
		}
	}
}

int getD(int num){
	return num*2%10000;
}

int getS(int num){
	num--;
	if(num<0) num=9999;
	return num;
}

int getL(int num){
	return num%1000*10 + num/1000;
}

int getR(int num){
	return num/10 + num%10*1000;
}


/*
11:02 Problem Analysis.
22:41 main() Completed.
25:00 4 function Completed.	//스톱워치 꺼짐.. 
32:15 Dijkstra(), Init() Completed.

38:07 TC passed.
시간초과...
40:54 Dijkstra()에 return 탈출문 추가.
43:47 reverse 추가...
정답!!
240502 43:47
*/
