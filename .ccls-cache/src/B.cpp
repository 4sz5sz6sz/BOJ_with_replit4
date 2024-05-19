#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

vector<int> A;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	//int ans=INF;
	cin >> N >> M;

	int cntOfP=0;

	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		A.push_back(num);
		if(num>0)
			cntOfP++;
	}

	sort(A.begin(),A.end(),greater<int>());
	int ans=0;
	//int len = min((int)ceil(M/2.0),cntOfP);
	int len = min(M,cntOfP);
	len = min(len, (int)ceil(N/2.0));
	//cout << "	len : " << len << "\n";
	for(int i=0;i<len;i++){
		ans+=A[i];
	}

	cout << ans << "\n";
	
	return 0;
}

/*
08:20 Problem Analysis.
13:36 main() Completed.
15:27 M/2.0에서 M으로 변경.
20:51 TC passed.
240519 20:54
*/