#include<bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int a);
void munion(int a, int b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int cnt=0;
	int N,K;
	cin >> N >> K;
	
	p.resize(N+1,-1);

	for(int i=0;i<K;i++){
		int cur;
		cin >> cur;

		if(find(cur)==0){
			break;
		}

		//cur번 게이트 폐쇄. 표지판 변경.
		munion(find(find(cur)-1),find(cur));
		cnt++;
		// cout << "	cnt :	" << cnt;
		// cout << "\n";
	}

	cout << cnt << "\n";
	
	return 0;
}

int find(int a){
	if(p[a]<0)
		return a;
	return p[a] = find(p[a]);
}

void munion(int a, int b){
	a = find(a);
	b = find(b);
	if(a>b) swap(a,b);
	p[a]+=p[b];
	p[b]=a;
}


/*
17:20 문제 분석
25:02 main() 작성 완료.
checkSame() 작성 생략.
28:30 함수 2개 작성 완료.
33:21 테스트 케이스 통과

240229 34:33
*/