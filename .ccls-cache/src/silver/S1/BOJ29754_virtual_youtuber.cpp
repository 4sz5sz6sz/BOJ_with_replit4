#define TIME first
#define CNT second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;	//TIME,CNT

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int cntOfMember=0;
	int N,M;
	cin >> N >> M;
	int maxW = M/7;
	//vector<unordered_map<string,Node>> m(maxW);
	unordered_map<string,int> m;	//pointer to index;
	vector<vector<Node>> arr(N+1,vector<Node>(maxW,{0,0}));	//[N][maxW] .TIME .CNT;
	vector<string> name;	//0-indexed

	for(int i=1;i<=N;i++){
		string n;
		int d;
		string s1, s2;
		cin >> n >> d >> s1 >> s2;
		
		int t1 = stoi(s1.substr(0,2)) * 60 + stoi(s1.substr(3,2));
		int t2 = stoi(s2.substr(0,2)) * 60 + stoi(s2.substr(3,2));
		if(m[n]==0){
			m[n]=i;
			cntOfMember++;
			name.push_back(n);
		} 
		arr[m[n]][(d-1)/7].TIME += t2-t1;
		arr[m[n]][(d-1)/7].CNT++;

		// cout << "		n : " << n;
		// cout << "		arr[m[n]][(d-1)/7].TIME : " << arr[m[n]][(d+1)/7].TIME;
		// cout << "		t2-t1 : " << t2-t1;
		// cout << "\n";
	}

	vector<string> ans;
	for(int i=0;i<name.size();i++){
		int flag=0;
		// cout << "	***name[i] :	" << name[i];
		for(int j=0;j<maxW;j++){
			if(!(arr[m[name[i]]][j].TIME >= 3600 && arr[m[name[i]]][j].CNT >= 5)) flag=1;
			// cout << "	arr[m[name[i]]][j].TIME :	" << arr[m[name[i]]][j].TIME;
			// cout << "	arr[m[name[i]]][j].CNT :	" << arr[m[name[i]]][j].CNT;
			// cout << "\n";
		}
		
		
		if(!flag)
			ans.push_back(name[i]);
	}

	sort(ans.begin(),ans.end());

	if(ans.size()==0)
		cout << -1;
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << "\n";
	}
	
	return 0;
}

/*
22:46 Problem Analysis.
35:00 first comfile
50:09 unordered_map 형식 변경
54:17 TC 오답..
01:02:16 d/7에서 (d-1)/7로 변경. 값 추적 통해서 찾아냄.
@@ vi에서, /같은 특수문자 처리는 어쩌지??

01:06:37 TC passed.

핵심 아이디어 : unordered_map 을 통해서 인덱스 가르키기.
240323 01:08:15
*/