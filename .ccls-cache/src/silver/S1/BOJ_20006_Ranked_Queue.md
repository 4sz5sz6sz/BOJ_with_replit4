랭킹전 대기열
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	4127	1548	1279	37.409%
문제
종운이는 운영하던 게임에 랭킹전 기능을 추가하려고 한다. 플레이어 간의 실력차이가 있을 수 있기 때문에 입장을 신청하면 자신과 비슷한 레벨의 플레이어들을 매칭하여 게임을 시작하게 하려고 한다.

플레이어 간 매칭을 해주는 시스템은 다음과 같다.

플레이어가 입장을 신청하였을 때 매칭이 가능한 방이 없다면 새로운 방을 생성하고 입장시킨다. 이떄 해당 방에는 처음 입장한 플레이어의 레벨을 기준으로 -10부터 +10까지 입장 가능하다.
입장 가능한 방이 있다면 입장시킨 후 방의 정원이 모두 찰 때까지 대기시킨다.
이때 입장이 가능한 방이 여러 개라면 먼저 생성된 방에 입장한다.
방의 정원이 모두 차면 게임을 시작시킨다.
플레이어의 수 p, 플레이어의 닉네임 n, 플레이어의 레벨 l, 방 한개의 정원 m이 주어졌을 때 위와 같은 방법으로 매칭해주고 최종적으로 만들어진 방의 상태와 입장 플레이어들을 출력하는 프로그램을 작성하자.

입력
첫 번째 줄에는 플레이어의 수 p(1 ≤ p ≤ 300)와 방의 정원 m(1 ≤ m ≤ 300)가 주어진다.

두 번째 줄부터 p개의 줄에는 플레이어의 레벨 l (1 ≤ l ≤ 500)과 닉네임 n이 공백을 두고 주어진다.

입력된 순서대로 게임을 시작한다.

닉네임은 중복되지 않으며 공백을 포함하지 않는 알파벳 소문자로 되어있으며 닉네임의 길이는 16을 넘지 않는다.

출력
모든 생성된 방에 대해서 게임의 시작 유무와 방에 들어있는 플레이어들의 레벨과 아이디를 출력한다. 시작 유무와 플레이어의 정보들은 줄 바꿈으로 구분되며 레벨과 아이디는 한 줄에서 공백으로 구분된다.

방은 생성된 순서대로 출력한다.

방에 있는 플레이어들의 정보는 닉네임이 사전순으로 앞서는 플레이어부터 출력한다.

방이 시작되었으면 Started!를 대기 중이면 Waiting!을 출력시킨다.

예제 입력 1 
10 5
10 a
15 b
20 c
25 d
30 e
17 f
18 g
26 h
24 i
28 j
예제 출력 1 
Started!
10 a
15 b
20 c
17 f
18 g
Started!
25 d
30 e
26 h
24 i
28 j

### Solution
pair<int,string> Node;
vector<vector<Node>> A;

입장 가능한 방이 있다/없다

현재 방의 갯수 : A.size();

for(모든 방){
	if(방 인원이 m명 미만 && 첫 플레이어와 차가 10 이하){
		A[i].push_back(cur);
		flag = 1;
	}
}


if(!flag){	//들어갈 방이 없다면
	A.push_back(vector<Node>());
	A[A.size()-1].push_back(cur);
}


for(모든 방){
	sort(현재방)
	if(방이 꽉 찼다면) Started! 출력.
	else Waiting! 출력.

	for()//		현재방 전부 출력.
}