#define MOD 1000000007
#define MX 19
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL POW(LL a, LL b, LL MMM);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		vector<int> ans;
		int a,b,l;
		cin >> a >> b >> l;

		for(int x=0;x<=MX;x++){
			for(int y=0;y<=MX;y++){
				LL pa = POW(a,x,MOD);
				LL pb = POW(b,y,MOD);
				if(x!=0 && pa % a != 0) break;	//오버플로우 발생.
				if(y!=0 && pb % b != 0) break;	//오버플로우 발생.
				if(pa > l || pb > l || pa * pb > l) break;
				if(l%(pa*pb)!=0) continue;
				ans.push_back(l/(pa*pb));
			}
		}

		sort(ans.begin(),ans.end());

		int cnt=1;
		for(int i=1;i<ans.size();i++){
			if(ans[i] == ans[i-1]) continue;
			cnt++;
		}
		cout << cnt << "\n";
	}
	
	return 0;
}

LL POW(LL a, LL b, LL MMM){
	LL ret = 1;
	for(;b;b>>=1,a=(a*a)){
		if(a>MMM || ret>MMM) return MMM;	//수정
		if(b & 1)
			ret = ret * a;
	}
	return ret;
}

/*
22:47 Problem Analysis.
28:39 main() Completed.
30:10 POW() Completed.
MMM이 10억일 때 오답 발생.
32:38 TC passed.
런타임 에러..

if(pa * pb > l) break;
에서
if(pa > l || pb > l || pa * pb > l) break;
로 수정.

if(x!=0 && pa % a != 0) continue;	//오버플로우 발생.
삽입. x!=0을 반드시 넣어야 예외 처리 가능.

42:10 TC passed

POW함수 조금 건듬.
52:28 TC passed

어째서인지 AC 받음.

if(x!=0 && pa % a != 0) break;	//오버플로우 발생.
if(y!=0 && pb % b != 0) break;	//오버플로우 발생.
에 문제가 있는건가??


240317 52:38
*/