#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,string> Node;
vector<vector<Node>> A;
vector<Node> arr;
int N,M;

bool func1(Node a, Node b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i=0;i<N;i++){
		int num;
		string s;
		cin >> num >> s;
		arr.push_back({num,s});
	}

	for(Node cur:arr){
		int flag = 0;
		for(int i=0;i<A.size();i++){
			if(A[i].size() < M && abs(A[i][0].X - cur.X) <= 10){
				A[i].push_back(cur);
				flag = 1;
				break;
			}
		}
		if(!flag){
			A.push_back(vector<Node>());
			A[A.size()-1].push_back(cur);
		}
	}

	for(int i=0;i<A.size();i++){
		sort(A[i].begin(),A[i].end(),func1);
		if(A[i].size() == M)
			cout << "Started!\n";
		else
			cout << "Waiting!\n";
		for(Node cur:A[i]){
			cout << cur.X << " " << cur.Y << "\n";
		}
	}
		
	
	return 0;
}

bool func1(Node a, Node b){
	return a.Y < b.Y;
}

/*
10:20 Problem Analysis.
17:59 main() Completed.
19:01 func() Completed.
22:18 stop..
재개..
05:00 TC passed.

240427 22:18 + 05:00
*/