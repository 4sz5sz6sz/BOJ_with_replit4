#define IDX_MAX 21
#define MODE_UPDATE 0
#define MODE_QUERY 1
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,T;
vector<int> A;
//int arr[IDX_MAX];
int st,en;
ll ans;
ll sum;

unordered_map<int,int> m;

void Backtracking(int cur,int mode){
	if(cur >= en){
		if(mode == MODE_UPDATE)
			m[sum]++;
		else{
			// cout << "		sum : " << sum;
			// cout << "		m[T-sum] : " << m[T-sum];
			// cout << "\n";
			ans+=m[T-sum];
		}
			
		return;
	}
	sum+=A[cur];
	Backtracking(cur+1,mode);
	sum-=A[cur];
	Backtracking(cur+1,mode);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> T;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		A.push_back(num);
	}

	if(N==1){
		if(T == A[0]){
			cout << "1\n";
		}
		else
			cout << "0\n";
		return 0;
	}
	st=0; en = N/2;
	Backtracking(st,MODE_UPDATE);
	st = en; en = N;
	Backtracking(st,MODE_QUERY);
	if(T==0) ans--;	//공집합 처리.
	cout << ans << "\n";
	
	return 0;
}
/*
11:20 main() Completed.
17:48 TC wa..
26:50 TC가 2로 출력.. 공집합 처리 해야 된다..
28:07 TC passed.
240507 28:05
*/