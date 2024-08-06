#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> arr;
	unordered_map<int,int> m;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		arr.push_back(num);
		m[num]++;
	}

	sort(arr.begin(),arr.end());

	int X;
	cin >> X;

	int ans=0;
	for(int i=0;i<N;i++){
		int cur = arr[i];
		//if(cur > X) break;
		if(m[X-cur])
			ans++;
	}
	cout << ans/2;
	return 0;
}

/*
02:20 Problem Analysis.
10:26 main() Completed.
10:36 TC passed.
240806 10:50
*/