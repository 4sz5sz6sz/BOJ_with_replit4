#define HEIGHT first
#define NAME second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;	//height, name

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;
	// vector<Node> arr(2*M);
	vector<Node> arr;

	for(int i=0;i<M;i++){
		int num1, num2;
		cin >> num1 >> num2;
		arr.push_back({num1,i+1});
		arr.push_back({num2,i+1});
	}

	sort(arr.begin(),arr.end());

	cout << arr[(N-1)%(2*M)].NAME << "\n";

	return 0;
}

/*
07:09 Problem Analysis.
09:21 런타임에러..
Node 도입.
240504 16:35
*/