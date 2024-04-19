#include<bits/stdc++.h>
using namespace std;



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	if(N==0){
		cout << 0;
		return 0;
	}
	vector<int> arr(N);
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}

	sort(arr.begin(),arr.end());

	int P = round((N*0.15));

	int sum=0;
	for(int i=P;i<N-P;i++)
		sum += arr[i];


	/*
	cout << "	sum : " << sum;
	cout << "	N : " << N;
	cout << "	P : " << P;
	cout << "\n";
	*/
	

	int ans = round(((float)sum/(N-2*P)));
	cout << ans << "\n";

	return 0;
}

/*
06:13 Problem Analysis.
08:01 main() Completed.
13:13 WA..
	int P = ceil((N/0.15)+0.5);
	에서
	int P = floor((N*0.15)+0.5);
	로 수정.

13:34 TC passed.
	틀렸습니다..

round()로 변경.

18:26 반례 발견, 0일때 오류.
예외처리 함.

240418 18:38
*/