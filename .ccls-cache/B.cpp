#include<bits/stdc++.h>
using namespace std;

vector<string> split(string s, string sep){
	vector<string> ret;
	int pos=0;
	while(pos < s.size()){
		int nxt_pos = s.find(sep,pos);
		if(nxt_pos == -1) nxt_pos = s.size();
		if(nxt_pos - pos > 0) 
			ret.push_back(s.substr(pos,nxt_pos-pos));
		pos = nxt_pos + sep.size();
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans=0;
	int N;
	string target;
	
	cin >> N;
	cin >> target;

	for(int i=0;i<N;i++){
		string item;
		int num;
		cin >> item;
		cin >> num;

		vector<string> chunks = split(item,"_");
		for(string chunk:chunks){
			if(chunk == target){
				ans+=num;
				break;
			}
		}
	}

	cout << ans << "\n";
	
	return 0;
}

/*
11:22 문제 분석 및 main() 작성 완료,
17:00 split() 작성 완료.
	-> 테스트 케이스 통과
240302 17:49
*/