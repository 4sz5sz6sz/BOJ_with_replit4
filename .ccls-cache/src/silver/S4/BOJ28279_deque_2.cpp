#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	deque<int> Q;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int comm;
		int data;
		cin >> comm;
		if(comm == 1){
			cin >> data;
			Q.push_front(data);
		}
		else if(comm == 2){
			cin >> data;
			Q.push_back(data);
		}
		else if(comm == 3){
			if(Q.empty())
				cout << "-1\n";
			else{
				cout << Q.front() << "\n";
				Q.pop_front();
			}
		}
		else if(comm == 4){
			if(Q.empty())
				cout << "-1\n";
			else{
				cout << Q.back() << "\n";
				Q.pop_back();
			}
		}
		else if(comm == 5){
			cout << Q.size() << "\n";
		}
		else if(comm == 6){
			if(Q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if(comm == 7){
			if(!Q.empty())
				cout << Q.front() << "\n";
			else
				cout << "-1\n";
		}
		else{
			if(!Q.empty())
				cout << Q.back() << "\n";
			else
				cout << "-1\n";
		}
	}

	return 0;
}

/*
07:00
240618 
*/