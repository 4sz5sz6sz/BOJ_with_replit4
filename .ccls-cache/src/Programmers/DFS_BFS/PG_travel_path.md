문제 설명
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.

항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
모든 공항은 알파벳 대문자 3글자로 이루어집니다.
주어진 공항 수는 3개 이상 10,000개 이하입니다.
tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
주어진 항공권은 모두 사용해야 합니다.
만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
입출력 예
tickets	return
[["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]	["ICN", "JFK", "HND", "IAD"]
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]	["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
입출력 예 설명
예제 #1

["ICN", "JFK", "HND", "IAD"] 순으로 방문할 수 있습니다.

예제 #2

["ICN", "SFO", "ATL", "ICN", "ATL", "SFO"] 순으로 방문할 수도 있지만 ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"] 가 알파벳 순으로 앞섭니다.

### solution
- 한붓그리기
~~우선, BFS 통해서 dist[] 매긴다. 이것 또한 알파벳 순으로 방문한다.~~
갈 수 있는 모든 경로 중, 
~~1. 최대한 dist[]가 큰 곳으로 가야한다.~~ 
//큰 순환형, 양방향 간선이면 어떡하지?	// 10000*10000이라 가능할 듯..


1. 알파벳 순으로 방문해야 한다.
DFS 종료시, 모든 간선을 다 돌지 못했다면 return;

입력값 받을 때, 
int -> string	//vector<> myName;
string -> int 	//unordered_map	myIndex;
가능하게끔 전처리한다.

새로운 문자열이면, myIndex["name"] = ++cntOfAirport;

vector<vector<int>> A;	//알파벳순으로 각각 정렬한다.

15:22 Problem Analysis.
32:20 main() Completed.
35:35 DFS() Completed.
37:19 cmp() Completed.
40:50 TC passed.