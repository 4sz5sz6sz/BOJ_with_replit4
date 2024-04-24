#include<bits/stdc++.h>
using namespace std;

int solution(vector<string> arr)
{
	int len = arr.size();
	int N = (len+1)/2;
	vector<int> num(N);
	vector<char> op(N);
	vector<int> dp(N);

	//string to op,num
	for(int i=0;i<len;i++){
		int curIdx = (i+1)/2;	//arr[index] -> num[curIdx] or op[curIdx]
		if(i & 1){	//operator
			op[curIdx] = arr[i][0];
		}
		else{	//number
			num[curIdx] = stoi(arr[i]);
		}
	}

	for(int i=1;i<N;i++){
		if(op[i] == '-'){
			int nxt_pos=i+1;
			int sum=0;
			while(nxt_pos<N && op[nxt_pos] == '+'){
				sum+=num[nxt_pos];
				nxt_pos++;
			}
			dp[i] = sum;
			//nxt_pos is next minus's pos.

			i = nxt_pos-1;	//i++과 상쇄
			
		}
	}

	
	int answer = -1;
	return answer;
}

/*
12:42 Problem Analysis.
18:15 string to op,num Completed.
39:30 gg..
240423 
*/