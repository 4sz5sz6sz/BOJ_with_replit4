#define IDX_MAX 500
#define DIST first
#define POS second
#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Edge;

int N,M;
Edge A[IDX_MAX][IDX_MAX];
Edge revA[IDX_MAX][IDX_MAX];
int isused[IDX_MAX][IDX_MAX];
int dist_1[IDX_MAX];
int dist_2[IDX_MAX];
int dist_3[IDX_MAX];

int st,en;

void Init();
void Dijkstra_1(int start);
void Dijkstra_2(int start);
void Dijkstra_3(int start);
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while(1){
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		Init();
		cin >> st >> en;

		for(int i=0;i<M;i++){
			int a,b,c;
			cin >> a >> b >> c;
			A[a][b] = {c,b};
			revA[b][a] = {c,a};
		}

		Dijkstra_1(st);
		Dijkstra_2(en);
		Dijkstra_3(st);
		//ShowArr();
		if(dist_3[en] == INF)
			cout << "-1\n";
		else
			cout << dist_3[en] << "\n";
	}
	
	return 0;
}

void Init(){
	for(int i=0;i<IDX_MAX;i++){
		for(int j=0;j<IDX_MAX;j++){
			A[i][j] = {INF,0};
		}
	}

	for(int i=0;i<IDX_MAX;i++){
		for(int j=0;j<IDX_MAX;j++){
			revA[i][j] = {INF,0};
		}
	}

	for(int i=0;i<IDX_MAX;i++){
		for(int j=0;j<IDX_MAX;j++){
			isused[i][j] = 0;
		}
	}

	for(int i=0;i<IDX_MAX;i++){
		dist_1[i] = INF;
	}

	for(int i=0;i<IDX_MAX;i++){
		dist_2[i] = INF;
	}

	for(int i=0;i<IDX_MAX;i++){
		dist_3[i] = INF;
	}
}

void Dijkstra_1(int start){
	priority_queue<Edge,vector<Edge>,greater<Edge>> Q;
	Q.push({0,start}); dist_1[start] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(dist_1[cur.POS] != cur.DIST) continue;
		//for(Edge next:A[cur.POS]){
		for(int i=0;i<IDX_MAX;i++){
			Edge next = A[cur.POS][i];
			if(next.DIST==INF) continue;
			if(dist_1[cur.POS] + next.DIST < dist_1[next.POS]){
				dist_1[next.POS] = dist_1[cur.POS] + next.DIST;
				Q.push({dist_1[next.POS],next.POS});
			}
		}
	}
}


void Dijkstra_2(int start){
	priority_queue<Edge,vector<Edge>,greater<Edge>> Q;
	Q.push({0,start}); dist_2[start] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(dist_2[cur.POS] != cur.DIST) continue;
		for(int i=0;i<IDX_MAX;i++){
			Edge next = revA[cur.POS][i];
			if(next.DIST==INF) continue;
			// cout << "	cur.POS :	" << cur.POS;
			// cout << "	next.POS :	" << next.POS;
			// cout << "	dist_1[next.POS] :	" << dist_1[next.POS];
			// cout << "	next.DIST :	" << next.DIST;
			//cout << "	cur.DIST :	" << cur.DIST;
			//cout << "	dist_2[cur.POS] :	" << dist_2[cur.POS];
			//cout << "	dist_1[en] :	" << dist_1[en];
			//조건 맞나?
			if(dist_2[cur.POS] + next.DIST <= dist_2[next.POS] && dist_1[next.POS] + cur.DIST + next.DIST == dist_1[en]){
				if(isused[next.POS][cur.POS]) continue; //추가 삽입.
				//같을 때는 작동 안함. 최솟값으로 갱신될때만 작동.
				if(dist_2[cur.POS] + next.DIST < dist_2[next.POS])
					dist_2[next.POS] = dist_2[cur.POS] + next.DIST;//이래도 되나??
					Q.push({dist_2[next.POS],next.POS});
				// cout << "	**0 -> 1**";
				isused[next.POS][cur.POS] = 1;
			}
			//cout << "\n";
		}
	}
}


/*
void Dijkstra_2(int start){
	queue<Edge> Q;
	Q.push({0.start}); dist_2[start]=0;
	while(!Q.empty()){
		Edge cur = Q.front(); Q.pop();
		for(int i=0;i<IDX_MAX;i++){
			Edge next = revA[cur]
		}
	}
}
*/

void Dijkstra_3(int start){
	priority_queue<Edge,vector<Edge>,greater<Edge>> Q;
	Q.push({0,start}); dist_3[start] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(dist_3[cur.POS] != cur.DIST) continue;
		for(int i=0;i<IDX_MAX;i++){
			Edge next = A[cur.POS][i];
			if(next.DIST==INF) continue;
			if(isused[cur.POS][next.POS]) continue;
			if(dist_3[cur.POS] + next.DIST < dist_3[next.POS]){
				dist_3[next.POS] = dist_3[cur.POS] + next.DIST;
				Q.push({dist_3[next.POS],next.POS});
			}
		}
	}
}

void ShowArr(){
	cout << "***ShowArr()***\n";
	for(int i=0;i<N;i++){
		cout << "	dist_1[i]	:	" << dist_1[i];
		cout << "\n";
	}

	cout << "\n";
	
	for(int i=0;i<N;i++){
		cout << "	dist_2[i]	:	" << dist_2[i];
		cout << "\n";
	}

	cout << "\n";
	
	for(int i=0;i<N;i++){
		cout << "	dist_3[i]	:	" << dist_3[i];
		cout << "\n";
	}

	cout << "\n";

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << isused[i][j] << " ";
		}
		cout << "\n";
	}
}

/*
05:54 Problem Analysis.
11:25 main() Completed.
12:40 Init() Completed.
17:09 Dijkstra_1() Completed.
30:57 Dijkstra_2() Completed. Dijkstra_3() Completed.
41:33 Tc wrong..
01:03:31 2번은 맞는데, 1 3번 틀림..
01:28:41
	if(dist_1[next.POS] + next.DIST == dist_1[en]){
	에서
	if(dist_1[next.POS] + cur.DIST + next.DIST == dist_1[en]){
	로 수정. 정상 작동.
01:30:05 TC passed.
메모리 초과..

01:35:28
	if(dist_1[next.POS] + cur.DIST + next.DIST == dist_1[en])
	에서
	if(dist_2[cur.POS] + next.DIST < dist_2[next.POS] && dist_1[next.POS] + cur.DIST + next.DIST == dist_1[en])
	로 수정.

58% 틀렸습니다..
	if(dist_2[cur.POS] + next.DIST <= dist_2[next.POS] && dist_1[next.POS] + cur.DIST + next.DIST == dist_1[en])
		로 수정.

시간초과..

01:48:31
	최솟값으로 갱신될때만 if문 진입하는 조건문 작성.
메모리 초과..

01:52:58
if(isused[next.POS][cur.POS]) continue; //추가 삽입.
정답입니다!!

240411 01:53:00
*/