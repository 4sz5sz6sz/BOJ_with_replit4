#define IDX_MAX 200001
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,K;
string s;
ll ans;
int cnt;
int DP_P[IDX_MAX];
int DP_C[IDX_MAX];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	string input;
	cin >> input;
	s.push_back(0);
	for(int i=0;i<N;i++)
		s.push_back(input[i]);
	

	int r=N;
	for(int l=1;l<N;l++){
		//if(r<=l) break;
		if(s[l] == 'P') continue;
		for(;r>l;r--){
			if(s[r] == 'C') continue;
			if(cnt >= K) break;
			swap(s[l],s[r]);
			r--;
			//cout << "swap!\n";
			cnt++;
			break;
		}
		if(cnt > K) break;
	}

	for(int i=1;i<=N;i++){
		DP_P[i] = DP_P[i-1];
		if(s[i-1] == 'P') DP_P[i]++;
	}

	for(int i=N-1;i>=0;i--){
		DP_C[i] = DP_C[i+1];
		if(s[i+1] == 'C') DP_C[i]++;
	}

	for(int i=1;i<=N-1;i++){
		if(s[i] == 'P'){
			ans+=(ll)DP_P[i]*DP_C[i];
		}
	}

	/*
	//FOR DEBUGGING
	for(int i=1;i<=N;i++){
		cout << s[i] <<"	";
	}
	cout << "\n";
	for(int i=1;i<=N;i++){
		cout << DP_P[i] <<"	";
	}
	cout << "\n";
	for(int i=1;i<=N;i++){
		cout << DP_C[i] <<"	";
	}
	cout << "\n";
	*/
	

	cout << ans << "\n";
	return 0;
}

/*
07:04 문제 분석
12:47 PC 교환 코드 작성 완료.
14:57 DP_x[] 2개 작성 완료.
19:14 WA..

23:05
	ans+=(ll)DP_P[i]*DP_C[i];
에서
if(s[i] == 'P'){
	ans+=(ll)DP_P[i]*DP_C[i];
}
로 변경.
26:46 TC passed.
240428 26:53 
*/