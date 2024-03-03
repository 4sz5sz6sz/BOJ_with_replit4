#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
	return b ? GCD(b,a%b):a;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> v(N);
		for(int i=0;i<N;i++){
			cin >> v[i];
		}

		long long sum=0;
		
		for(int i=0;i<N-1;i++){
			for(int j=i+1;j<N;j++){
				sum+=GCD(v[i],v[j]);
			}
		}

		cout << sum << "\n";
	}
	
	return 0;
}



/*
03:56 문제 분석
06:39 main() 작성 완료
240227 
*/