#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	vector<int> arr;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}
	for(int i=0;i<M;i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(),arr.end());

	for(int i=0;i<N+M;i++)
		cout << arr[i] << " ";
	return 0;
}
/*
240710 03:37 
*/