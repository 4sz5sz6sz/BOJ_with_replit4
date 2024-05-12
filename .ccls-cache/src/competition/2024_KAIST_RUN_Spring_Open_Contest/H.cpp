#define INF 0x3f3f3f3f
#define IDX_MAX 1007
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N,Q;
ll arr[IDX_MAX];
vector<vector<int>> A;
ll ans;

ll DFS(int cur, int parent);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> arr[i];
	}

	A.resize(N+1);

	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	cin >> Q;
	for(int i=0;i<Q;i++){
		ll a,b;
		ans = 0;
		cin >> a >> b;
		arr[a] = b;
		DFS(1,0);
		if(ans == 0){
			ans=-INF;
			for(int j=1;j<=N;j++){
				ans = max(ans, arr[j]);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}

ll DFS(int cur, int parent){
	ll ret = arr[cur];
	for(int next:A[cur]){
		if(next == parent) continue;
		ret += max(DFS(next,cur), 0ll);
	}
	ans = max(ans,ret);
	return ret;
}

/*
08:42 Problem Analysis.
13:29 main(), DFS() Completed.
반례: 
1이 아니라 3이 최대인 경우
전부 음수인 경우

27:24 TC passed.
240511 27:30
*/