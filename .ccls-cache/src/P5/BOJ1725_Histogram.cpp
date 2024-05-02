#define DATA first
#define POS second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;	//DATA, POS
typedef long long ll;
vector<ll> A;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	stack<Node> S;
	int N;
	
	cin >> N;
	ll ans=0;
	A.resize(N);

	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	
	int originPos;
	for(int i=0;i<N;i++){
		Node newNode = {A[i],i};
		// if(!S.empty())
			originPos = i-1;
			//originPos = S.top().POS;

		//오름차순을 위배하는 경우. pop() 반복.
		while(!S.empty() && S.top().DATA >= A[i]){
			ll w = originPos - S.top().POS + 1;
			ll h = S.top().DATA;
			// cout << "	originPos	:" << originPos;
			// cout << "	S.top().POS	:" << S.top().POS;
			// cout << "	w	:" << w;
			// cout << "	h	:" << h;
			// cout << "\n";
			Node delNode = S.top(); S.pop();
			ans = max(ans, w*h);
			//마무리 작업
			if(S.empty() || S.top().DATA < A[i]){
				newNode.POS = delNode.POS;
			}
		}
		S.push(newNode);
		// cout << "	newNode.POS	:" << newNode.POS;
		// cout << "	newNode.DATA	:" << newNode.DATA;
		// cout << "\n";
	}

	/*
	int originPos;
	if(!S.empty())
		originPos = S.top().POS;
		*/

	while(!S.empty()){
		ll w = originPos - S.top().POS + 1 + 1;
		ll h = S.top().DATA;
		// cout << "	originPos	:" << originPos;
		// cout << "	S.top().POS	:" << S.top().POS;
		// cout << "	w	:" << w;
		// cout << "	h	:" << h;
		// cout << "\n";
		//Node delNode = S.top(); 
		S.pop();
		ans = max(ans, w*h);
	}

	cout << ans << "\n";
	
	return 0;
}



/*
38:08 Problem Analysis.
50:22 스택에 넣을 값 정하기) 구현 완료.
57:34 넓이 최댓값 갱신하기) 구현 완료.
01:00:06 
TC passed.
1 2 3 4 5 성공
5 4 3 2 1 실패..

reverse 넣음.
11% 오답..
1 2 3 4 5 5 4 3 2 1 실패..

01:15:50 
	originPos = S.top().POS;
	에서
	originPos = i-1;
	로 변경.

11% 오답..

01:19:00
ll ans=N
에서
ll ans=0
으로 변경..

34% 오답..

19:11 반례 발견. 
2 1 1 -> 1
3 3 3 3 -> 6

30:46
ll w = originPos - S.top().POS + 1;
에서
ll w = originPos - S.top().POS + 1 + 1;
로 변경.

//originPos = S.top().POS; 제거.

맞았습니다!!
originPos 좌표 설정을, ++ 안해주고, 잘못된 값으로 초기화되서 그런 듯.
마지막 i=N-1 시점에 ++가 안됨.

240501 01:19:00 + 31:32
*/