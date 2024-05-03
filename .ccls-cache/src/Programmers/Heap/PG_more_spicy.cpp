#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<ll,vector<ll>, greater<ll>> Q;
	int N = scoville.size();
	for(int cur:scoville){
		Q.push(cur);
	}

	while(Q.size() >= 2 && Q.top() < K){
		ll n1 = Q.top(); Q.pop();
		ll n2 = Q.top(); Q.pop();
		Q.push(n1+n2+n2);
		answer++;
	}

	if(Q.size() <= 1 && Q.top() < K) return -1;

	return answer;
}

/*
06:00 main() Completed.
240506 06:06
*/