# 도로 네트워크
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	11715	4490	2971	37.503%
### 문제
N개의 도시와 그 도시를 연결하는 N-1개의 도로로 이루어진 도로 네트워크가 있다. 

모든 도시의 쌍에는 그 도시를 연결하는 유일한 경로가 있고, 각 도로의 길이는 입력으로 주어진다.

총 K개의 도시 쌍이 주어진다. 이때, 두 도시를 연결하는 경로 상에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 N이 주어진다. (2 ≤ N ≤ 100,000)

다음 N-1개 줄에는 도로를 나타내는 세 정수 A, B, C가 주어진다. A와 B사이에 길이가 C인 도로가 있다는 뜻이다. 도로의 길이는 1,000,000보다 작거나 같은 양의 정수이다.

다음 줄에는 K가 주어진다. (1 ≤ K ≤ 100,000)

다음 K개 줄에는 서로 다른 두 자연수 D와 E가 주어진다. D와 E를 연결하는 경로에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 구해서 출력하면 된다.

### 출력
총 K개 줄에 D와 E를 연결하는 경로에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 출력한다.

### 에제 입력 1 
```
5
2 3 100
4 3 200
1 5 150
1 3 50
3
2 4
3 5
1 2
```
### 에제 출력 1 
```
100 200
50 150
50 100
```
### 에제 입력 2 
```
7
3 6 4
1 7 1
1 3 2
1 2 6
2 5 4
2 4 4
5
6 4
7 6
1 2
1 3
3 5
```
### 에제 출력 2 
```
2 6
1 4
6 6
2 2
2 6
```
### 에제 입력 3 
```
9
1 2 2
2 3 1
3 4 5
2 7 4
1 5 3
5 6 1
5 9 2
1 8 3
5
6 9
7 8
9 4
1 2
7 3
```
### 에제 출력 3 
```
1 2
2 4
1 5
2 2
1 4
```

### 풀이
- Lowest Common Ancestor
- Graph
	- max Weight, min Weight


D[MXN][MXDEPTH]

dist_max[MXN][MXDEPTH]
dist_min[MXN][MXDEPTH]

토너먼트 식으로, 병합정렬 하듯이, 가장 긴 경로와 가장 작은 경로를 계속 갱신하기.

D[cur][0] = ??

정점의 인덱스 2개만 가지고 거리의 값 가져오기?
	해시? (X)
cur과 parent의 거리 : dist[cur]-dist[parent]

dist_max[cur][0] = dist[cur]-dist[parent];
dist_min[cur][0] = dist[cur]-dist[parent];

dist_max[cur][1 ~ MAXDEPTH-1] = max(dist_max[cur][i-1], dist_max[D[cur][i-1]][i-1]);
나부터 부모까지, 부모부터 부모^2까지 가장 긴 도로의 길이 비교,
dist_min[cur][1 ~ MAXDEPTH-1] = min(dist_min[cur][i-1], dist_min[D[cur][i-1]][i-1]);
나부터 부모까지, 부모부터 부모^2까지 가장 짧은 도로의 길이 비교,



//max(dist[cur]-dist[D[cur][i-1]], dist[D[cur][i]] - dist[D[cur][i-1]])
//dist_min[cur][1 ~ MAXDEPTH-1] = dist[cur]-dist[D[cur][i-1]];


나머지는 똑같이 구현해주기.
BFS도 구현해주기.

#### lca 구한 뒤,
D[tempA][0~MXDEPTH-1] == lca 이 될 때까지, 계속 탐색.
D[tempA][i] == lca이면,
	ans1 = dist_min[tempA][i];

D[tempB][0~MXDEPTH-1] == lca 이 될 때까지, 계속 탐색.
D[tempB][i] == lca이면,
	ans1 = min(ans1, dist_min[tempB][i]);

ans2도 같은 방식으로 반복.
tempB도.

	