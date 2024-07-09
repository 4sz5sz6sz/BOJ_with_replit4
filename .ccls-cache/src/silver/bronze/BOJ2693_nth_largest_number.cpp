#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		int N = 7;
		vector<int> arr;
		for(int i=0;i<10;i++){
			int num;
			cin >> num;
			arr.push_back(num);
		}
		sort(arr.begin(),arr.end());
		cout << arr[N] << "\n";
	}
	
	return 0;
}

/*
240709
*/