#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> Node;
ll ans;

struct cmp1{
	bool operator()(const Node &a, const Node &b){
		return a.X + a.Y < b.X + b.Y;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	priority_queue<Node,vector<Node>,cmp1> Q;
	for(int i=0;i<N;i++){
		Node tmp;
		cin >> tmp.X >> tmp.Y;
		Q.push(tmp);
	}

	while(Q.size() >= 2){
		Node n1 = Q.top(); Q.pop();
		Node n2 = Q.top(); Q.pop();
		ans += n1.X*n2.Y + n2.X*n1.Y;
		Q.push({n1.X + n2.X ,n1.Y + n2.Y});
	}

	cout << ans << "\n";
	
	return 0;
}

/*
06:05 main() Completed.
07:43 어떻게 하든 128이 출력... 답은 모름.. TC passed.
240509 07:57
*/