#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	int ans=0;
	//int arr[3];
	for(int i=0;i<3;i++){
		//cin >> arr[i];
		int num;
		cin >> num;
		ans += min(num,N);
	}
	cout << ans << "\n";
	
	return 0;
}

/*
01:02
240713
*/