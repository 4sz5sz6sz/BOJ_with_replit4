#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> vecP;
vector<ll> vecM;
int zero;
ll ans = 3987654321ll;
vector<ll> ansV;

void solve(ll target);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ansV.resize(3);
	int N;
	cin >> N;

	for(int i=0;i<N;i++){
		ll temp;
		cin >> temp;
		
		if(temp > 0){
			vecP.push_back(temp);
		}
		else if(temp < 0){
			vecM.push_back(temp);
		}
		else{
			zero=1;
		}
	}

	sort(vecP.begin(),vecP.end());
	sort(vecM.begin(),vecM.end(),greater<ll>());

	//exception case 1
	if(zero==1 && vecP.size()>=2 && abs(0+vecP[0]+vecP[1]) < ans){
		ans = abs(0+vecP[0]+vecP[1]);
		ansV[0] = 0;
		ansV[1] = vecP[0];
		ansV[2] = vecP[1];
	}

	//exception case 2
	if(zero==1 && vecM.size()>=2 && abs(0+vecM[0]+vecM[1]) < ans){
		ans = abs(0+vecM[0]+vecM[1]);
		ansV[0] = 0;
		ansV[1] = vecM[0];
		ansV[2] = vecM[1];
	}

	//exception case 3
	if(vecP.size()>=3 && abs(vecP[0]+vecP[1]+vecP[2]) < ans){
		ans = abs(vecP[0]+vecP[1]+vecP[2]);
		ansV[0] = vecP[0];
		ansV[1] = vecP[1];
		ansV[2] = vecP[2];
	}

	//exception case 4
	if(vecM.size()>=3 && abs(vecM[0]+vecM[1]+vecM[2]) < ans){
		ans = abs(vecM[0]+vecM[1]+vecM[2]);
		ansV[0] = vecM[0];
		ansV[1] = vecM[1];
		ansV[2] = vecM[2];
	}

	//exception case 5
	if(zero==1)
		solve(0);

	for(ll cur:vecP) solve(cur);
	for(ll cur:vecM) solve(cur);

	sort(ansV.begin(),ansV.end());
	for(int i=0;i<3;i++){
		cout << ansV[i] << " ";
	}
	cout << "\n";
	
	return 0;
}

void solve(ll target){
	int pIdx=0;
	int mIdx=0;

	while(pIdx < vecP.size() && mIdx < vecM.size()){
		if(target==vecP[pIdx]){//같은 숫자 2번 등장한 경우.
			pIdx++;
			continue;
		}
		
		if(target==vecM[mIdx]){//같은 숫자 2번 등장한 경우.
			mIdx++;
			continue;
		}
		
		ll curN = target + vecP[pIdx] + vecM[mIdx];
		if(abs(curN) < ans){
			ans = abs(curN);
			ansV[0]=target;
			ansV[1]=vecP[pIdx];
			ansV[2]=vecM[mIdx];
		}
		
		if(curN > 0){
			mIdx++;
		}
		else if(curN < 0){
			pIdx++;
		}

		else{
			return;
		}

		
	}
	
}


/*
24:44 문제 분석
29:47 입력문 구현 완료.
40:38 main() 작성 완료.
43:11 solve() 작성 완료. 첫 컴파일
45:33 -97 -6 -2 출력하는 현상 발생, 최솟값이 아니라, 절댓값을 비교하도록 변경.
47:29 -6,0,6 출력되는 현상 발생, solve(0)은 조건부 호출되도록 변경.

48:22 테스트 케이스 2개 통과.

2% 틀렸습니다...
target에 대한 중복처리 안함.. 이론상 1,1,2 가 출력 가능했던 상황이다. 조건 위배된다.
53:58 중복 생략 구현.

57:14	abs() 처리 안된 부분 한 곳 발견.
	ans = curN;
	에서
	ans = abs(curN);
	로 변경.

240228 58:15
*/