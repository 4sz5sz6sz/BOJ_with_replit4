#define DATA first
#define INDEX second
#define IDX_MAX 1001
#include <bits/stdc++.h>
using namespace std;

typedef pair<string,int> Node;

int N;
string str;
vector<vector<Node>> v(IDX_MAX);
vector<int> vis;
vector<string> arr;

bool CheckSame(string s1, string s2);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> str;
	vis.resize(N);
	arr.resize(N);

	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		if(s==str) vis[i]=1;
		v[s.length()].push_back({s,i});
		arr[i] = s;
	}

	for(int i=3;i<IDX_MAX-1;i++){
		for(int j=0;j<v[i].size();j++){
			if(vis[v[i][j].INDEX]==0) continue;	//미방문시 pass.
			for(int k=0;k<v[i+1].size();k++){
				if(vis[v[i+1][k].INDEX]) continue;	//이미 방문했다면 pass.
				if(CheckSame(v[i][j].DATA, v[i+1][k].DATA)){
					// cout << "	i :	" << i;
					// cout << "	j :	" << j;
					// cout << "	k :	" << k;
					// cout << "\n";
					vis[v[i+1][k].INDEX] = 1;
				}
			}
		}
	}

	int _max = 0;
	string ans="ERROR";
	for(int i=0;i<N;i++){
		if(vis[i]){
			//cout << "*";
			// cout << "	arr[i] :" << arr[i];
			// cout << "	arr[i].length() :" << arr[i].length();
			// cout << "	_max :" << _max;
			// cout << "\n";
			if(arr[i].length() > _max){
				// cout << "*";
				_max = arr[i].length();
				ans = arr[i];
			}
		}
	}

	cout << ans << "\n";
	
	return 0;
}

bool CheckSame(string s1, string s2){
	int i=0;
	int pass=0;
	for(int j=0;j<s2.length();j++){
		while(s1[i] == s2[j]){
			i++; j++;
		}
		if(i>=s1.length()) break;
		pass++;
		if(pass>1) break;
	}
	if(pass>1) return false;
	else return true;
}

/*
15:04 Problem Analysis.

0초부터 재개,

18:30 main() Completed.
32:26 CheckSame() Completed.

47:26 
	if(arr[i].length() > _max){
	해당 조건문을 절대 만족하지 않는 경우 발생함.
	
	int _max = -1;
	에서
	int _max = 0;
	로 수정하니 잘 됨.

48:38 TC passed.

unsigned int 와 int 형을 비교연산하면 int형의 형 변환이 일어난다.
사칙연산 뿐만 아니라, 비교연산에도 형 변환이 일어난다.

240327 15:04+48:46
*/