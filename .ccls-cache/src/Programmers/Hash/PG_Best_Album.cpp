#define INF 0x3f3f3f3f3f3f3f3f
#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> Node; //재생횟수, 일련번호
unordered_map <string,ll> numOfGenre;  //0 or Not 0, for check
unordered_map <string,ll> genre_myIndex;  //1-indexed. 1~cntOfGenre.
ll cntOfGenre;
int N;

vector<string> myGenre; //int -> string
vector<vector<Node>> A; //모든 곡을 장르별 분류

bool cmp1(const vector<Node> &a, const vector<Node> &b);
bool cmp2(const Node &a, const Node &b);

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	N = (int)genres.size();
	A.push_back(vector<Node>());    //장르 이름이 1-indexed 이기 때문. 
	//A[장르이름][장르별 갯수] A[장르][노래]
	A[0].push_back({INF,0});
	for(int i=0;i<N;i++){
		Node cur = {plays[i],i};
		string s = genres[i];
		if(numOfGenre[s] == 0){
			genre_myIndex[s] = ++cntOfGenre;
			A.push_back(vector<Node>());
		}
		numOfGenre[s]++;
		myGenre.push_back(s);
		A[genre_myIndex[s]].push_back(cur);
	}

	sort(A.begin(),A.end(),cmp1);// 장르별 정렬

	for(int i=1;i<=cntOfGenre;i++){
		sort(A[i].begin(),A[i].end(),cmp2); //장르 내부에서, 재생순 정렬, 고유번호 순 정렬,
	}

	// answer.push_back(A[1][0].Y);
	// answer.push_back(A[1][1].Y);
	// answer.push_back(A[2][0].Y);
	// answer.push_back(A[2][1].Y);

	for(int i=1;i<=cntOfGenre;i++){
		//if(i>cntOfGenre) continue;  //A[i]가 OOB라면, PASS.
		for(int j=0;j<=1;j++){
			if(j>=(int)A[i].size()) continue;  //A[i][j]가 OOB라면, PASS.
			cout << "   A[i][j].Y :" << A[i][j].Y;
			cout << "   myGenre[A[i][j].Y] :" << myGenre[A[i][j].Y];
			cout << "\n";
			answer.push_back(A[i][j].Y);
		}
	}

	cout << "   cntOfGenre : " << cntOfGenre;
	cout << "\n";
	return answer;
}

bool cmp1(const vector<Node> &a, const vector<Node> &b){
	ll sum1=0;
	ll sum2=0;
	for(Node cur: a)
		sum1+=cur.X;
	for(Node cur: b)
		sum2+=cur.X;
	return sum1 > sum2;
}

bool cmp2(const Node &a, const Node &b){
	if(a.X != b.X) return a.X>b.X;
	return a.Y < b.Y;
}

/*
39:29 해시 STL 다시 보기..
50:26 AC...

틀린 이유..
두 장르가 아니라 모든 장르임..
50:33만큼 낭비함..

240507 36:54+50:33
*/