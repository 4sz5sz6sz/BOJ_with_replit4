#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> arr(N+1);

	int ans=0;
	for(int i=1;i<=N;i++){
		cin >> arr[i];
		if(arr[i-1] && arr[i]!=0)
			arr[i] = arr[i-1]+1;
		ans += arr[i];
	}

	cout << ans << "\n";
	
	return 0;
}