#define NUM_MAX 500000
#define DIST first
#define POS second
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<int,int> Node;	//DIST, POS;
int dx[2] = {1,-1};
int N,K;
int curTime;
int ans=-1;
unordered_map<int,int> m[1000];
vector<int> target;	//target[4] : 4초 뒤 동생의 위치.

void BFS(int start);
bool OOB(int nx, int mn, int mx);

struct cmp1{
	bool operator()(const Node &a, const Node &b){
		ld d1 = min((ld)abs(a.POS - target[a.DIST+1]), (ld)log2(target[a.DIST+1]) - log2(a.POS));
		ld d2 = min((ld)abs(b.POS - target[b.DIST+1]), (ld)log2(target[b.DIST+1]) - log2(b.POS));
		return d1>d2;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	int t=K;
	for(int curT=0;t<=NUM_MAX;curT++){
		t+=curT;
		target.push_back(t);
	}
	if(N==K){
		cout << "0\n";
		return 0;
	}
	BFS(N);

	cout << ans;
	// cout << "\n";
	// cout << K;
	
	return 0;
}

void BFS(int start){
	priority_queue<Node, vector<Node>, cmp1> Q; Q.push({0,start});
	while(!Q.empty()){
		Node cur = Q.top(); Q.pop();
		// cout << "	cur.DIST : " << cur.DIST;
		// cout << "	cur.POS : " << cur.POS << "\n";
		int nx;
		int ndist = cur.DIST + 1;
		for(int dir=0;dir<3;dir++){
			//Node next = cur;
			if(dir <= 1)
				nx = cur.POS + dx[dir];
			else
				nx = cur.POS + cur.POS;

			if(OOB(nx,0,NUM_MAX)) continue;
			if(m[ndist][nx]) continue;
			
			if(nx == target[ndist]){
				ans = ndist;
				return;
			}
			
			Q.push({ndist,nx});
			m[ndist][nx]++;
		}
	}
	//cout << "aa";
}

bool OOB(int nx, int mn, int mx){
	return nx < mn || nx > mx;
}

/*
17:51 Problem Analysis.
34:04 TC passed. 시간복잡도 검증은 안해봄..
39:10 priority?
46:19 unordered_map 구현.
55:32 cur.POs == K 제거.

27% 시간초과...

priority로 그리디하게 접근하기? cur.NUM에다가 얼마나 2를 곱해야 K가 되는가?
x = log2(K) - log2(cur)
또는. x = abs(K-cur)

01:14:50 log2(0) 들어간 듯..

01:19:32 포기..

240509 55:32
*/