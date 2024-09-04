#define INF 0x3f3f3f3f
#define IDX_MAX 107
#include<bits/stdc++.h>
using namespace std;

int table[IDX_MAX];
int input[IDX_MAX];

int N,K;
int ans;

void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for(int i=0;i<K;i++){
		cin >> input[i];
	}

	for(int i=0;i<K;i++){
		bool flag = true;
		int cur = input[i];
		int _max = -INF;
		//int addNode;
		int delNode=INF;
		for(int j=0;j<N;j++){
			if(table[j]==0 || table[j]==cur){
				delNode = j;
				flag=false;
				break;
			}
			int curMax=-INF;	//등장여부
			for(int k=i+1;k<K;k++){ // k : curMax
				if(table[j] == input[k]){
					curMax = k;
					if(curMax > _max){
						_max = curMax;
						delNode = j;
					}
					break;	//추가. if문 밖으로 빼냄.
				}
			}
			if(curMax < 0){
				_max = INF;
				delNode = j;
				//break;
				//미등장하더라도 전수조사 해봐야 함.
			}
		}
		table[delNode] = cur;
		if(flag) ans++;
		// ShowArr();
	}

	cout << ans << "\n";
	
	return 0;
}

void ShowArr(){
	for(int i=0;i<N;i++){
		cout << "	" << table[i];
	}
	cout << "\n";
}

/*
13:22 Problem Analysis.
13:22+22:23 main() Completed.
+28:41 3 출력.
+33:23 TC passed.
WA...
35:57 미 등장 시 break; 제거.
WA...

57:50
정해가 아닌거 같기도 하다. cur 1 2 3 3 3 3 1
이면 1이 선정된다.
01:02:37 break; 추가. curMax부분. 
01:05:49 + if문 밖으로 빼냄.
240904 13:22+01:05:51
*/