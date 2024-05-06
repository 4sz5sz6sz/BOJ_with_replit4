#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> A;
bool cmp(const string &a, const string &b);

string solution(vector<int> numbers) {
	string answer = "";
	N = (int)numbers.size();
	long long sum=0;
	for(int i=0;i<N;i++){
		A.push_back(to_string(numbers[i]));
		//cout << to_string(numbers[i]);
		sum += numbers[i];
	}
	if(sum == 0) return "0";
	// cout << "   N : " << N;
	// cout << "\n";
	// string s1 = "0";
	// string s2 = "999";
	// cout << stoi(s1+s2);
	sort(A.begin(),A.end(),cmp);
	cout << A.size();

	for(int i=0;i<N;i++){
		/*
		answer+=A[i];
		cout << "   i :" << i;
		cout << "   A[i] :" << A[i];
		cout << "\n";
		*/
		int len = (int)A[i].size();
		for(int j=0;j<len;j++)
			answer.push_back(A[i][j]);

	}

	return answer;
}

bool cmp(const string &a, const string &b){
	long long n1 = stoull(a+b);
	long long n2 = stoull(b+a);
	return n1 > n2;
}

/*
09:22 Problem Analysis.
20:15 정렬 함수 만들다가. 
자정 STOP..

240506 재개
51:00 통과..
비교함수에서 두 값이 같을 때, true를 반환하면 안된다.
-> quick sort의 공간복잡도는 평균적으로 O(log N) 이지만, 최악의 경우에 O(N)이기 때문.
만약, 100,000개의 값이 있다면 재귀함수를 10만번 호출하게 된다.
즉, 모든 값이 같을 때, 비교함수에서 두 값이 같을 때 true를 반환한다면 메모리 초과로 이어진다.


*/