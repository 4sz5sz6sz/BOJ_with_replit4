#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		//int ans;
		int N;
		cin >> N;
		if(N==1) cout << "0\n";
		else if(N==2) cout << "11\n";
		else if(N==3) cout << "121\n";
		else{
			cout << "11";
			for(int i=0;i<N-4;i++){
				cout << "0";
			}
			cout << "11\n";
		}
	}
	return 0;
}

/*
06:30 첫 컴파일
ans 주석처리 안하면 에러띄우는 replit.com
08:09 테스트 케이스 통과.
13:45 0은 모든 수의 배수이다. -1이 아니라 0 출력시키기.
240301 13:59
*/