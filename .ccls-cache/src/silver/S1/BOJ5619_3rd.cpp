#define IDX_MAX 10007
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> A;
int isused[IDX_MAX];

ll func(ll a, ll b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		if(isused[num]>=3) continue;
		isused[num]=1;
		A.push_back(num);
		//cout << "	num :" << num << "\n";
	}

	sort(A.begin(),A.end());

	//long long ans=0x3f3f3f3f3f3f3f3f;

	vector<ll> ans;
	ans.push_back(func(A[0],A[1]));
	ans.push_back(func(A[0],A[2]));
	if(N>=4)
		ans.push_back(func(A[0],A[3]));
	
	ans.push_back(func(A[1],A[0]));
	ans.push_back(func(A[1],A[2]));
	if(N>=4)
		ans.push_back(func(A[1],A[3]));

	ans.push_back(func(A[2],A[0]));
	ans.push_back(func(A[2],A[1]));
	if(N>=4)
		ans.push_back(func(A[2],A[3]));

	if(N>=4){
		ans.push_back(func(A[3],A[0]));
		ans.push_back(func(A[3],A[1]));
		ans.push_back(func(A[3],A[2]));
	}
	


	sort(ans.begin(),ans.end());


	cout << ans[2] << "\n";
	
	return 0;
}

ll func(ll a, ll b){
	string s = to_string(a) + to_string(b);
	return stoll(s);
}

/*
12:05 Problem Analysis.
20:03 TC passed.
wA..

24:48 경우의 수 추가.
32:44 A[3] 조건 제한 더 추가. cnt 3넘어가면 continue;
240512 32:56
*/