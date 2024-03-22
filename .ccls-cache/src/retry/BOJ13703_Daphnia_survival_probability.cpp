#define IDX_MAX 65
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int K,N;
int arr[IDX_MAX];	//for debugging
ll curH;	//기존 Backtracking 에서의 arr[]의 역할.
ll cnt;

void Backtracking(int depth);
void ShowArr(int len);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> K >> N;

	Backtracking(1);	//1-indexed

	// cout << "	1<<N	:	" << (1<<N);
	// cout << "	cnt	:	" << cnt;
	// cout << "\n";
	
	cout << (1<<N) - cnt;
	return 0;
}

void Backtracking(int depth){
	if(depth > N) return;	//base condition 0
	//발동될 일이 있을까?

	if(curH >= K){ //base condition 1
		cnt += 1<<(N-(depth-1));
		/*
		ShowArr(depth-1);
		cout << "	N-depth-1	:	" << N-(depth-1);
		cout << "\n";
		*/
		return;
	}

	if(curH + (N-(depth-1)) < K){ //base condition 2
		//cout << "*";
		return;
	}

	for(int i=-1;i<=1;i+=2){
		if(true){
			curH+=i;
			arr[depth]=i;
			Backtracking(depth+1);
			curH-=i;
			arr[depth]=0;
		}
	}
}

void ShowArr(int len){
	for(int i=1;i<=len;i++){
		if(arr[i] > 0)
			cout << "+";
		else
			cout << "-";
	}
	for(int i=0;i<N-len;i++)
		cout << "@";
	cout << "\n";
}


/*
25:14 Problem Analysis.
33:01 main(), Backtracking() Completed.

cout << "	1<<N	:	" << 1<<N;
를
cout << "	1<<N	:	" << (1<<N);
로 수정.. operator << 에 의해 의도와 다른 출력 발생.

42:55 void ShowArr(int len); Completed.
46:27 
	cnt += 1<<(N-depth+1);
	에서
	cnt += 1<<(N-depth+1);
로 수정.

57:04 TC passed.

240322 57:14
*/