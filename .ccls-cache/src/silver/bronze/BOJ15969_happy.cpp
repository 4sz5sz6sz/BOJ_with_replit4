#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	vector<int> arr;
	cin >> N;

	arr.resize(N);
	for(int i=0;i<N;i++)
		cin >> arr[i];

	sort(arr.begin(),arr.end());

	cout << arr[arr.size()-1] - arr[0];
	
	return 0;
}

/*
00:58 문제 분석
240307 02:53 
*/