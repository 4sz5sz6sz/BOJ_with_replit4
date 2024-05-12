//#define X first
//#define Y second
#include<bits/stdc++.h>
using namespace std;

//typedef pair<string,string> Node;
typedef struct Node{
	int INDEX;
	string X,Y;
	bool operator <(struct Node &temp){
		if(INDEX != temp.INDEX) return INDEX < temp.INDEX;
		if(X != temp.X) return X < temp.X;
		return Y < temp.Y;
	}
}Node;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;
	vector <string> Q(N);
	vector <string> A(N);

	for(int i=0;i<N;i++){
		cin >> Q[i] >> A[i];
	}

	for(int i=0;i<M;i++){
		//int cnt=0;
		string s;
		vector<Node> ans;
		cin >> s;
		for(int j=0;j<N;j++){
			int pos = 0;
			while(pos < s.size()){
				int nxt_pos = s.find(Q[j],pos);
				//if(nxt_pos < 0) nxt_pos = s.size();
				//if(nxt_pos - pos > 0){
				if(nxt_pos >= 0)
					ans.push_back({nxt_pos,Q[j],A[j]});
				else{
					nxt_pos = s.size();
				}
				//pos = nxt_pos + Q[j].size();
				pos = nxt_pos + 1;
			}
		}
		sort(ans.begin(),ans.end());
		if((int)ans.size()>0){
			for(Node cur:ans){
				cout << cur.Y;
			}
		}

		else{
			cout << "-1";
		}
		
		cout << "\n";
	}
	
	return 0;
}

/*
06:59 Problem Analysis.
14:42 TC passed.
WA..
34:16 두번 대답하는 기능 구현. split 변형.
37:26 pos = nxt_pos + 1로 변경.
gg..

00:02 재개..
k 순서대로 정렬하는 조건 추가하기.
03:23 구현 완료.

240512 37:38 + 03:29
*/
