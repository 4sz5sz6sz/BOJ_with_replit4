#define IDX_MAX 2000001
#define ADD 1000000
#include<bits/stdc++.h>
using namespace std;

//int cnt[IDX_MAX];

//void Init();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		int N;
		int numOfQ=0;
		cin >> N;
		//vector<int> cnt(IDX_MAX);
		unordered_map<int,int> cnt;
		priority_queue<int,vector<int>,greater<int>> PQ1;	
		//최소힙
		priority_queue<int,vector<int>,less<int>> PQ2;	
		//최대힙
		for(int i=0;i<N;i++){
			string comm;
			int num;
			cin >> comm >> num;
			if(comm == "I"){
				PQ1.push(num);
				PQ2.push(num);
				cnt[num]++;
				numOfQ++;
			}
			else{
				if(num>0){
					while(!PQ2.empty()){
						int cur = PQ2.top(); PQ2.pop();
						if(cnt[cur] > 0){
							cnt[cur]--;
							numOfQ--;
							break;
						}
						//실제 존재한다면, 삭제 후 탈출,
						//이미 삭제된 노드라면, 다시 뽑기.
					}
				}
				else{
					while(!PQ1.empty()){
						int cur = PQ1.top(); PQ1.pop();
						if(cnt[cur] > 0){
							cnt[cur]--;
							numOfQ--;
							break;
						}
					}
				}
			}
		}
		
		while(!PQ1.empty()){
			int cur = PQ1.top(); PQ1.pop();
			if(cnt[cur] > 0){
				PQ1.push(cur);	//다시 원상복구.
				//cnt[cur]--;
				//numOfQ--;
				break;
			}
		}
		while(!PQ2.empty()){
			int cur = PQ2.top(); PQ2.pop();
			if(cnt[cur] > 0){
				PQ2.push(cur);	//다시 원상복구.
				//cnt[cur]--;
				//numOfQ--;
				break;
			}
		}
		
		if(numOfQ == 0){
			cout << "EMPTY\n";
		}
		else{
			cout << PQ2.top() << " " << PQ1.top() << "\n";
		}
	}	
	return 0;
}

/*
06:03 Problem Analysis.
26:43 세그먼트 폴트 오류.. ADD 도입.

PQ2.push(cur);	//다시 원상복구.
추가.
29:30 TC passed. 

31:51 WA.. 조건 빼먹음.
수의 범위는 int 전체 범위이다.
unordered_map<int,int> m; 도입.

33:25 TC passed.

240423 33:30
*/