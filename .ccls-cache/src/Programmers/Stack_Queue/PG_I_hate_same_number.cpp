#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
	int N = arr.size();
	vector<int> answer;

	answer.push_back(arr[0]);
	for(int i=1;i<N;i++){
		if(arr[i-1]==arr[i]) continue;
		answer.push_back(arr[i]);
	}

	return answer;
}

/*
02:50 solution() Completed.
240419 10:00
*/

