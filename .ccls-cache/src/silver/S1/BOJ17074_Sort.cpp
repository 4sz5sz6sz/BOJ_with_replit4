#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> arr;
	int N;
	cin >> N;

	arr.resize(N);
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}

	int cnt=0;
	int widx=-1;
	for(int i=1;i<N;i++){
		if(arr[i-1] > arr[i]){
			widx = i;
			cnt++;
		}
	}

	int ans=0;
	if(cnt==0)
		ans=N;
	else if(cnt >= 2)
		ans = 0;
	else{
		if(arr[widx-2] <= arr[widx]) ans++;
		if(widx+1 >= N ||arr[widx-1] <= arr[widx+1]) ans++;
	}

	cout << ans << "\n";
	
	return 0;
}

/*
16:06 Problem Analysis
20:43 main() completed.
21:54 TC passed.
240319 21:57
*/