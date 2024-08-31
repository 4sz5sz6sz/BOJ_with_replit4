#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> Node;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<Node> arr;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		ll s,e;
		cin >> s >> e;
		if(s>e) swap(s,e);
		arr.push_back({s,e});
	}
	sort(arr.begin(),arr.end());

	Node last = arr[0];
	ll ans = arr[0].Y - arr[0].X;
	for(int i=1;i<N;i++){
		Node cur = arr[i];
		if(cur.Y<=last.Y) continue;
		ll add = cur.Y - cur.X;
		if(cur.X < last.Y) add-= last.Y - cur.X;
		if(cur.Y > last.Y) last.Y = cur.Y;
		ans+=add;
	}
	cout << ans << "\n";
	
	return 0;
}

/*
28:34 Problem Analysis.
37:01 TC passed.
41:49 s e swap 추가, 선분이 다른 선분을 포함하는 경우 조건문 추가.
240831 42:05
*/