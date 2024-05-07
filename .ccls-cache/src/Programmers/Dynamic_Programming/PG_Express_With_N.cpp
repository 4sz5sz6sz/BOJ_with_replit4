#define INF 0x3f3f3f3f
#define IDX_MAX 1000001
#define DIST first
#define POS second
#define NUM second
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,ll> Edge; //DIST, POS

int dist[IDX_MAX];
int N;
ll target;
vector<Edge> A;

void MakeEdge();
void Dijkstra(ll start);

int solution(int n, int number) {
	ll answer = 0;

	N = n;
	target = number;
	//N = 5;
	for(int i=0;i<IDX_MAX;i++) dist[i] = INF;
	MakeEdge();
	cout << A.size();
	Dijkstra(N);
	if(dist[number] > 8) answer = -1;
	else answer = dist[number];

	return answer;
}

void MakeEdge(){
	queue<Edge> Q; 
	A.push_back({1,N});
	A.push_back({2,N*11});
	A.push_back({3,N*111});
	A.push_back({4,N*1111});
	A.push_back({5,N*11111});
	A.push_back({6,N*111111});
	Q.push({1,N});
	Q.push({2,N*11});
	Q.push({3,N*111});
	Q.push({4,N*1111});
	Q.push({5,N*11111});
	Q.push({6,N*111111});

	//A.push_back({6,N*11});
	while(!Q.empty()){
		Edge cur = Q.front(); Q.pop();
		//cout << cur.POS << "\n";
		int ndist = cur.DIST + 1;
		ll nx;
		for(int dir=0;dir<4;dir++){
			if(dir==0)
				nx = cur.POS + N;
			else if(dir==1)
				nx = abs(cur.POS - N);
			else if(dir==2)
				nx = cur.POS * N;
			else
				nx = max(cur.POS / N, N / cur.POS);

			if(nx <= 0 || nx >= IDX_MAX) continue;
			if(ndist >= 8) continue;

			A.push_back({ndist,nx});
			Q.push({ndist,nx});
		}
	}
	sort(A.begin(),A.end());
}

void Dijkstra(ll start){
	priority_queue<Edge,vector<Edge>,greater<Edge>> Q; 
	Q.push({1,start});
	Q.push({2,start*11});
	Q.push({3,start*111});
	Q.push({4,start*1111});
	Q.push({5,start*11111});
	Q.push({6,start*111111});
	dist[start] = 1;
	dist[start*11] = 2;
	dist[start*111] = 3;
	dist[start*1111] = 4;
	dist[start*11111] = 5;
	dist[start*111111] = 6;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		//cout << cur.POS << "\n";
		if(cur.DIST != dist[cur.POS]) continue;
		for(int i=0;i<A.size();i++){
			int flag=0;
			Edge next = A[i];
			for(int dir=0;dir<4;dir++){
				if(dir==0)
					next.POS = cur.POS + A[i].NUM;
				else if(dir==1)
					next.POS = abs(cur.POS - A[i].NUM);
				else if(dir==2)
					next.POS = cur.POS * A[i].NUM;
				else
					next.POS = max(cur.POS / A[i].NUM, A[i].NUM / cur.POS);

				if(dist[cur.POS] + next.DIST > 8){
					flag = 1;
					break;
				}
				if(next.POS <= 0 || next.POS >= IDX_MAX) continue;
				if(dist[cur.POS] + next.DIST < dist[next.POS]){
					dist[next.POS] = dist[cur.POS] + next.DIST;
					Q.push({dist[next.POS],next.POS});
					if(cur.POS == 99 && next.POS%9 == 0){
						cout << "	cur.POS : " << cur.POS;
						cout << "	next.POS : " << next.POS;
						cout << "	next.DIST : " << next.DIST;
						cout << "\n";
					}
				}
			}
			if(flag) break;
		}

	}
}