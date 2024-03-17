//#define E first
//#define S second
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

//typedef pair<int,int> Edge;
typedef struct Edge{
	int S,E,V;
	/*
	bool operator < (struct Edge &temp){
		if(E!=temp.E) return E<temp.E;
		return S<temp.S;
	}
	*/
}Edge;

bool cmp1(Edge a, Edge b){
	if(a.E!=b.E) return a.E<b.E;
	return a.S<b.S;
}

bool cmp2(Edge a, Edge b){
	if(a.S!=b.S) return a.S<b.S;
	return a.E<b.E;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<Edge> A;
	
	for(int i=0;i<N;i++){
		int st,en,price;
		cin >> st >> en >> price;
		A.push_back({st,en,price});
	}

	sort(A.begin(),A.end(),cmp1);
	vector<Edge> ans;
	//vector<Edge> ans1;
	//vector<Edge> ans2;

	ans.push_back(A[0]);
	for(int i=1;i<N;i++){
		while(ans.size()>0 && A[i].S <= ans[ans.size()-1].E){
			A[i] = {min(ans[ans.size()-1].S,A[i].S),A[i].E, min(A[i].V, ans[ans.size()-1].V)};
			ans.pop_back();
		}
		ans.push_back(A[i]);
	}

	/*
	int prevS=A[0].S;
	int prevE=A[0].E;
	int minP=A[0].V;
	for(int i=0;i<N;i++){
		Edge cur = A[i];
		if(cur.S <= prevE){
			minP = min(minP,cur.V);
			prevE = cur.E;
		}
		else{
			ans1.push_back({prevS,prevE,minP});
			prevS = cur.S;
			prevE = cur.E;
			minP=cur.V;
		}
	}

	ans1.push_back({prevS,prevE,minP});
	//2구간 
	
	sort(ans1.begin(),ans1.end(),cmp2);

	prevS=ans1[ans1.size()-1].S;
	prevE=ans1[ans1.size()-1].E;
	minP=ans1[ans1.size()-1].V;
	for(int i=ans1.size()-1;i>=0;i--){
		Edge cur = ans1[i];
		if(cur.E >= prevS){
			minP = min(minP,cur.V);
			prevE = cur.E;
		}
		else{
			ans2.push_back({prevS,prevE,minP});
			prevS = cur.S;
			prevE = cur.E;
			minP=cur.V;
		}
	}
	ans2.push_back({prevS,prevE,minP});
	sort(ans2.begin(),ans2.end(),cmp2);
	*/
	
	cout << ans.size() << "\n";
	for(Edge cur:ans){
		cout << cur.S << " " << cur.E << " " << cur.V << "\n";
	}
	
	return 0;
}

/*
07:32 Problem Analysis
22:17 main() Completed.
TC 오답..
30:18 TC passed.
틀렸습니다..

43:33 cmp2 도입.
48:36 for문 2개로 늘림. 테스트 케이스 통과.

56:35 2번째 for문 역순으로 바꿈.

재개
새로운 아이디어, 스택에 저장하기.
반례가 존재한다. top()이랑 안 겹칠때까지, 계속 합체한다.

10:08 테스트 케이스 통과
틀렸습니다..

16:12 반례에 대한 코드 수정.
3
1 3 10
4 6 10
3 7 10
정답 : 1\n 1 7 10
오답 : 2\n 1 3 10\n 4 7 10
	A[i] = {ans[ans.size()-1].S,A[i].E, min(A[i].V, ans[ans.size()-1].V)};
	에서
	A[i] = {min(ans[ans.size()-1].S,A[i].S),A[i].E, min(A[i].V, ans[ans.size()-1].V)};
	로 수정.

240317 17:19
*/