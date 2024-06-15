#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<string> arr(9);
	arr[0] = "PROBRAIN";
	arr[1] = "GROW";
	arr[2] = "ARGOS";
	arr[3] = "ADMIN";
	arr[4] = "ANT";
	arr[5] = "MOTION";
	arr[6] = "SPG";
	arr[7] = "COMON";
	arr[8] = "ALMIGHTY";
	
	int N;
	int loop = 9;
	int ans;
	int _max = -1;
	cin >> N;
	for(int i=0;i<loop;i++){
		for(int j=0;j<N;j++){
			int num;
			cin >> num;
			if(num > _max){
				_max = num;
				ans = i;
			}
		}
	}
	cout << arr[ans] << "\n";
	
	return 0;
}

/*
04:35
240615 09:42
*/