#define IDX_MAX 16
#include<bits/stdc++.h>
using namespace std;

int _min;
int N;
int chk[IDX_MAX];
int isused[IDX_MAX];
int arr[3];
string stdstr = "ISFJ";	//standard MBTI : ISFJ

void Init();
void Backtracking(int depth);
int calc();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		int flag=0;
		Init();
		cin >> N;
		//cout << "	N : " << N << "\n";
		for(int i=0;i<N;i++){
			string s;
			cin >> s;
			int result=0;
			for(int j=0;j<4;j++){
				if(stdstr[j] == s[j])
					result+=(1<<j);
			}
			chk[result]++;
			/*
			cout << "	result : " << result << "\n";
			if(++chk[result] <= 2) continue;
			else{	//무조건 최솟값(출력값)이 0으로 확정.
				cout << "0" << "\n";
				flag = 1;
				break;
			}
			*/
		}
		//if(flag) continue;
		
		//int numOfMBTI=0;

		//For debugging
		for(int i=0;i<IDX_MAX;i++){
			if(chk[i] >= 3) flag=1; 
			// cout << "	i : " << i;
			// cout << "	chk[i] : " << chk[i];
			// cout << "\n";
		}

		if(flag){
			cout << "0\n";
			continue;
		}
		
		Backtracking(0);
		cout << _min << "\n";
	}
	
	return 0;
}

void Init(){
	_min = INT_MAX;
	for(int i=0;i<IDX_MAX;i++)
		chk[i] = 0;
	for(int i=0;i<IDX_MAX;i++)
		isused[i] = 0;
	for(int i=0;i<3;i++)
		arr[i] = 0;
}

void Backtracking(int depth){
	if(depth >= 3){
		int cnt = calc();
		_min = min(cnt,_min);

		/*
		for(int i=0;i<depth;i++){
			cout << "	i : " << i;
			cout << "	arr[i] : " << arr[i];
			cout << "\n";
		}
		cout << "	cnt : " << cnt;
		cout << "\n";
		*/
		return;
	}

	for(int i=0;i<IDX_MAX;i++){
		if(isused[i] < chk[i] && (depth == 0 || i>=arr[depth-1])){
			isused[i]++;
			arr[depth] = i;
			Backtracking(depth+1);
			isused[i]--;
			arr[depth] = -1;
		}
	}
}

int calc(){
	int ret=0;
	for(int i=0;i<3;i++){
		int mask=0;
		mask = mask ^ arr[i];
		for(int j=0;j<3;j++){
			mask = mask ^ arr[j];
		}
		//mask에는 arr[j]를 제외한 나머지 2개의 값만 저장.

		int cnt=0;
		for(int i=1;i<=(1<<3);i<<=1){
			if(i & mask) cnt++;
		}
		//cout << "	cnt :	" << cnt << "\n";
		ret+=cnt;
	}
	//cout << "\n";
	//cout << "	ret : " << ret << "\n";
	return ret;
}


/*
10:10 Problem Analysis.
18:32 main() Completed.
20:07 Init() Completed.
25:19 Backtracking() Completed.
29:24 calc() Completed.
31:14 WA... 전부 888 출력..
36:56
MBTI가 같은 사람을 골라야 하는 경우가 있을 수도 있다.
전체적으로 수정하기.

44:37
_max을 _min으로 수정..
isused[]를 1 or 0이 아닌, 사용 횟수를 기록하도록 수정.

53:07
if(isused[i] < chk[i] && depth == 0 || i>=arr[depth-1])
에서
if(isused[i] < chk[i] && (depth == 0 || i>=arr[depth-1]))
로 수정하니 정상 작동.

53:52 TC passed.
01:06:16 string 입력이 끝나지 않은 상태인데, 도중에 break되는 현상 발생.
	flag = 1;
	break; //이게 너무 빨리 작동함.

01:09:28 TC passed.

240422 01:09:49
*/