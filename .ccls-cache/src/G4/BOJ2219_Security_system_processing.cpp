#define INF 0x3f3f3f3f
#define IDX_MAX 201
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct Edge{
	int S,E;
	int V;
	bool operator < (struct Edge &temp){
		return V < temp.V;
	}
}Edge;

vector<int> parent;
vector<Edge> A;

int dist[IDX_MAX][IDX_MAX];

int N,M;

void Init();
bool CheckSame(int a, int b);
void munion(int a, int b);
int find(int a);
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	Init();
	for(int i=0;i<M;i++){
		int s,e,v;
		cin >> s >> e >> v;
		//A.push_back({s,e,v});
		dist[s][e] = v;
		dist[e][s] = v;
	}
	//sort(A.begin(), A.end());


	
	/*
	for(int i=0;i<M;i++){
		if(CheckSame(A[i].S,A[i].E)) continue;
		munion(A[i].S,A[i].E);
		dist[A[i].S][A[i].E] = A[i].V;
		dist[A[i].E][A[i].S] = A[i].V;
	}*/

	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	//ShowArr();

	int ans;
	int _min = INF;
	for(int i=1;i<=N;i++){
		int sum=0;
		for(int j=1;j<=N;j++){
			if(i==j) continue;
			sum+=dist[i][j];
		}
		if(sum < _min){
			_min = sum;
			ans = i;
		}
	}

	cout << ans << "\n";
	
	return 0;
}

void Init(){
	parent.resize(N+1,-1);
	for(int i=0;i<IDX_MAX;i++){
		for(int j=0;j<IDX_MAX;j++){
			dist[i][j] = INF;
		}
	}

	for(int i=0;i<IDX_MAX;i++)
		dist[i][i] = 0;
}

bool CheckSame(int a, int b){
	return find(a) == find(b);
}

void munion(int a, int b){
	a = find(a);
	b = find(b);
	if(CheckSame(a,b)) return;
	parent[a] += parent[b];
	parent[b] = a;
}

int find(int a){
	if(parent[a] < 0)
		return a;
	return parent[a] = find(parent[a]);
}

void ShowArr(){
	cout << "**ShowArr()**\n";
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << dist[i][j] <<" ";
		}
		cout << "\n";
	}
}


/*
25:37 Problem Analysis
44:33 main() Completed.
47:13 Init() Completed.
49:39 UF func 3 Completed.
50:47 TC passed.

59:00 1번 조건이랑 2번 조건 중, 어느 것에 우선을 둬야할 지 모르겠음..

01:00:37 1번 조건 무시해보고 출력, MST 삭제.
맞았습니다!!
240328 01:00:50
*/