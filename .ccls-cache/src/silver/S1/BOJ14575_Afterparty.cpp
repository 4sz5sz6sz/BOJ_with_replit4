#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

int N,T;

vector<int> L;
vector<int> R;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> T;

	int sumL=0;
	int sumR=0;
	int maxL=-1;
	int maxR=-1;
	for(int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		L.push_back(a);
		R.push_back(b);
		sumL+=a;
		sumR+=b;
		maxL = max(maxL, a);
		maxR = max(maxR, b);
	}

	if(sumL > T || T > sumR){
		cout << "-1\n";
		return 0;
	}

	int st=maxL;
	int en=maxR;

	while(st<=en){
		int mid = (st+en)/2;
		sumR=0;
		for(int i=0;i<N;i++){
			sumR+=min(mid,R[i]);
		}
		//cout << "	sumR :" << sumR << "\n";
		
		if(T<=sumR){	//성공
			en = mid-1;
		}
		else{	//실패
			st = mid+1;
		}
	}

	cout << st << "\n";
	
	
	return 0;
}

/*
19:36 Problem Analysis.
26:51 main() Completed.
27:10 TC passed.

WA..

36:55
	int en=minR;
	에서
	int en=maxR;
	로 수정.

240326 37:12
*/