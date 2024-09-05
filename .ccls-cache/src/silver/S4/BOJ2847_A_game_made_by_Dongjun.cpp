#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int cnt=0;
	for(int cur=N-2;cur>=0;cur--){
		while(arr[cur]>=arr[cur+1]){
			arr[cur]--;
			cnt++;
		}
	}
	cout << cnt << "\n";
	
	return 0;
}

/*
03:27 Problem Analysis.
05:59 main() Completed.
240905 06:13
*/