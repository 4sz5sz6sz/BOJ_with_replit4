단절점
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	15667	5797	3424	34.797%
문제
그래프가 주어졌을 때, 단절점을 모두 구해 출력하는 프로그램을 작성하시오.

단절점이란 그 정점을 제거했을 때, 그래프가 두 개 또는 그 이상으로 나누어지는 정점을 말한다. 즉, 제거했을 때 그래프의 connected component의 개수가 증가하는 정점을 말한다.

입력
첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이며, 방향은 양방향이다.

입력으로 주어지는 그래프는 연결 그래프가 아닐 수도 있다. 정점은 1부터 V까지 번호가 매겨져 있다.

출력
첫째 줄에 단절점의 개수를 출력한다.

둘째 줄에는 단절점의 번호를 공백으로 구분해 오름차순으로 출력한다.

예제 입력 1 
7 7
1 4
4 5
5 1
1 6
6 7
2 7
7 3
예제 출력 1 
3
1 6 7

### Solution
- 단절점

