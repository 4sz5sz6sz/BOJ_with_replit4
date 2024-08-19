#define INF 0x7f7f7f7f7f7f7f7f
#define POS first
#define COST second
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> Node;

vector<Node> input;
vector<Node> arr;

ll ans;

int main(){
	ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	input.resize(N);

	for(int i=1;i<N;i++){
		ll W;
		cin >> W;
		input[i].POS = input[i-1].POS + W;
	}

	for(int i=0;i<N;i++){
		cin >> input[i].COST;
	}

	input[N-1].COST = -1;

	//arr.push_back(input[0]);
	Node last = input[0];
	for(int i=1;i<N;i++){
		Node cur = input[i];
		//Node last = arr[arr.size()-1];
		if(last.COST >= cur.COST){
			ans += last.COST * (cur.POS - last.POS);
			last = cur;
			// cout << "	ans : " << ans << "\n";
		}
			//arr.push_back(cur);
	}

	cout << ans << "\n";
	
	return 0;
}


/*
13:26 Problem Analysis.
23:32 main() Completed
27:28 TC passed.
17 point...
31:40 input[N-1]의 COST를 -1로 설정.
240819 32:24
*/