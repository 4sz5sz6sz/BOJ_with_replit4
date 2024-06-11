#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll GCD(ll a, ll b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	unordered_map<int,int> m;
	vector<int> arr;
	vector<int> delta;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		m[num] = 1;
		arr.push_back(num);
	}

	for(int i=0;i<N-1;i++){
		delta.push_back(arr[i+1] - arr[i]);
	}

	int gcd = delta[0];
	for(int i=1;i<N-1;i++){
		int cur = delta[i];
		gcd = GCD(gcd, cur);
	}

	int ans=0;
	/*
	for(int i=arr[0];i<=arr[N-1];i+=gcd){
		if(m[i] != 1) ans++;
	}
	*/

	ans = (arr[N-1] - arr[0]) / gcd + 1 - N;
	

	cout << ans << "\n";
	
	return 0;
}

ll GCD(ll a, ll b){
	return b?GCD(b,a%b):a;
}

/*
04:25 Problem Analysis.
10:27 main() Completed.
11:20 TC Passed.
MLE..
20:57 ans 식 변경.
240611 21:04
*/