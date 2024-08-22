#define IDX_MAX 4000*1000+5
#include<bits/stdc++.h>
using namespace std;

// vector<string> vc;
// vector<string> vn;
vector<string> vq;
unordered_map<string,int> m;
unordered_map<string,int> mN;
int C,N;
int Q;

int ROOT_1 = 1;
int ROOT_2;
int unused = 2;
int nxt[IDX_MAX][26];
bool chk[IDX_MAX];

void Init();
void insert(int ROOT, string &s);
int find(int startPos, string &s);
int c2i(char c);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Init();
	cin >> C >> N;
	for(int i=0;i<C;i++){
		string s;
		cin >> s;
		// vc.push_back(s);
		insert(ROOT_1, s);
	}
	ROOT_2 = unused++;

	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		mN[s] = true;
		// vn.push_back(s);
		// insert(ROOT_2, s);
	}

	cin >> Q;
	for(int i=0;i<Q;i++){
		string s;
		cin >> s;
		vq.push_back(s);
		find(0,s);
		// if(find(0,s))
		// 	cout << "Yes\n";
		// else
		// 	cout << "No\n";
	}

	// for(int i=0;i<C;i++){
	// 	int ptr = find(ROOT, 0, vc[i]);
	// 	if(!ptr) continue;
	// 	for(int j=0;j<N;j++){
	// 		//if(vc[i].size() + vn[j].size())
	// 		int ret = find(ptr, vc[i].size(), vn[j]);
	// 		if(ret>0){
	// 			m[vc[i]+vn[j]] = true;
	// 		} 
	// 	}
	// }

	for(int i=0;i<Q;i++){
		string s = vq[i];
		if(m[s])
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	
	return 0;
}

void Init(){
	for(int i=0;i<IDX_MAX;i++)
		fill(nxt[i],nxt[i]+26,-1);
}

void insert(int ROOT, string &s){
	int cur = ROOT;
	for(char c:s){
		if(nxt[cur][c2i(c)] == -1)
			nxt[cur][c2i(c)] = unused++;
		cur = nxt[cur][c2i(c)];
	}
	chk[cur] = true;
}

int find(int startPos, string &s){
	int cur;
	if(startPos == 0) cur = ROOT_1;
	else cur = ROOT_2;
	
	for(int i=startPos;i<s.size();i++){
		char c = s[i];
		if(nxt[cur][c2i(c)] == -1)
			return false;
		cur = nxt[cur][c2i(c)];
		
		if(startPos==0 && chk[cur]){ //이 자리가 맞나?
			string str = s.substr(i+1, (int)s.size()-i);
			// cout << str;
			// cout << "\n";
			if(mN[str]){
				m[s]=true;
				return true;
			}
				
			// if문 한줄 잠시만 제거
			/*
			if(find(i+1, s)){
				m[s]=true;
				return true;
			}
			*/
		}
		
	}
	// cout << "	depth : " << depth;
	// cout << "	s : " << s;
	// cout << "		cur : " << cur;
	// cout << "		prev : " << prev;
	// cout << "		chk[cur] : " << chk[cur];
	// cout << "\n";
	return chk[cur];
	// if(depth==0 || chk[cur]) return cur;
	// return false;
}

int c2i(char c){
	return c-'a';
}



/*
03:44 Problem Analysis.
15:41 main() Completed.
18:55 Init() Completed.
21:34 insert() Completed.
25:23 find() Completed.
25:35 c2i() Completed.
WA...
35:47 Init() 삽입...
36:47 TC passed.

01:12:03 새로 구현 완료. TC passed.
Wa...
01:17:07 return chk[cur]; 삽입.
82% TLE...
01:22:22
82% 틀렸습니다...
01:34:03 트리 하나, substr 도입.
82% MLE...
01:35:53 IDX_MAX 값을 4000*1000으로 하향.
240822 01:36:03
*/