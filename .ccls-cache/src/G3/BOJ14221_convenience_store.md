# 편의점
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	512 MB	1518	205	138	18.930%
문제
영선이는 이사할 일이 생겨 집을 알아보고 있다. 영선이는 혼자 살기 때문에, 편의점에서 대충 때울 때가 많아, 집을 고르는 기준을 편의점과의 거리가 가장 가까운 곳으로 하려한다.

영선이가 이사할 도시는 정점과 간선으로 표현할 수 있는데, 이사가려 하는 집의 후보들과 편의점은 정점들 위에 있다.

영선이는 캠프 강사 준비로 바쁘므로, 대신하여 집을 골라주자. 만약 거리가 같은 지점이 여러 개라면 정점 번호가 가장 낮은 곳으로 골라주자.

입력
처음 줄에는 정점의 개수 n, 간선의 개수 m이 주어진다.(2 ≤ n ≤ 5,000, 1 ≤ m ≤ 100,000) 다음 m줄에는 a,b,c가 주어지는데 이는 a, b를 잇는 간선의 거리가 c라는 것이다.(1 ≤ a, b ≤ n, 1 ≤ c ≤ 10,000)

다음 줄에는 집의 후보지의 개수 p와 편의점의 개수 q가 주어진다.(2 ≤ p+q ≤ n, 1 ≤ p, 1 ≤ q) 다음 줄에는 집의 후보지들의 정점번호, 그 다음줄에는 편의점의 정점번호가 주어진다. 집의 후보지와 편의점은 서로 겹치지 않는다.

출력
편의점으로부터 가장 가까운 지점에 있는 집 후보의 정점 번호를 출력하시오. 만약 거리가 같은 곳이 여러 군데라면 정점 번호가 낮은 곳을 출력하시오.

예제 입력 1 
6 9
1 4 1
1 5 2
1 6 3
2 4 2
2 5 3
2 6 1
3 4 3
3 5 1
3 6 2
3 3
1 2 3
4 5 6
예제 출력 1 
1


### 풀이
편의점에서부터 다익스트라 수행.
state[] == SHOP이면
	//탐색 종료.    
	continue;
state[] == HOME이면
	//결과 최솟값으로 갱신
	continue;
현재까지 타고온 간선이 최단경로가 아닐 시, 해당 간선은 버린다.


