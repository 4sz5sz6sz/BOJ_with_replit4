#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int arr[5];
	int ans=0;
	for(int i=0;i<5;i++)
		cin >> arr[i];

	ans = arr[0] * arr[1] - arr[2] * arr[3] * arr[4];
	cout << ans << "\n";
	return 0;
}

/*
02:07
240702 
*/