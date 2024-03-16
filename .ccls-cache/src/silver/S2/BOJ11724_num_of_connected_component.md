# 연결 요소의 개수
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
3 초	512 MB	126059	56867	37386	42.058%
### 문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

### 출력
첫째 줄에 연결 요소의 개수를 출력한다.


### 예제 입력 1 
```
6 5
1 2
2 5
5 1
3 4
4 6
```
### 예제 출력 1 
```
2
```
### 예제 입력 2 
```
6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3
```
### 예제 출력 2 
```
1
```

### 풀이
- BFS
	- flood fill



### 접근 방법
BFS를 이용하여 풀었습니다.


### 구현 방법
모든 점에서 BFS를 수행하도록 하였으며, 한번 방문한 정점에 대해서는 BFS를 시행하지 않았습니다.

### 시행 착오
없습니다.

### 배운 점
문제 내용과 관련해서는 없습니다.
이번 문제는 특별히 vim을 이용하여 풀었습니다.
다중 커서 기능을 활용하였습니다.
https://jybaek.tistory.com/758

