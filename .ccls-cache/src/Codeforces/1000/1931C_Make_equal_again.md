# C. Make Equal Again
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have an array a of n integers.

You can no more than once apply the following operation: select three integers i, j, x (1≤i≤j≤n) and assign all elements of the array with indexes from i to j the value x. The price of this operation depends on the selected indices and is equal to (j−i+1) burles.

For example, the array is equal to [1,2,3,4,5,1]. If we choose i=2,j=4,x=8, then after applying this operation, the array will be equal to [1,8,8,8,5,1].

What is the least amount of burles you need to spend to make all the elements of the array equal?

### Input
The first line contains a single integer t (1≤t≤104) — the number of input test cases. The descriptions of the test cases follow.

The first line of the description of each test case contains a single integer n (1≤n≤2⋅105) — the size of the array.

The second line of the description of each test case contains n integers a1,a2,…,an (1≤ai≤n) — array elements.

It is guaranteed that the sum of n for all test cases does not exceed 2⋅105.

### Output
For each test case, output one integer — the minimum number of burles that will have to be spent to make all the elements of the array equal. It can be shown that this can always be done.

### Example
inputCopy
8
6
1 2 3 4 5 1
7
1 1 1 1 1 1 1
8
8 8 8 1 2 8 8 8
1
1
2
1 2
3
1 2 3
7
4 3 2 7 1 1 3
9
9 9 2 9 2 5 5 5 3
### outputCopy
4
0
2
0
1
2
6
7
### Solution
- greedy

왼쪽에서부터 같은 숫자 세보기.
오른쪽에서부터 같은 숫자 세보기.

int numL, numR;
둘이 같은 숫자라면, 
	len - (cntL + cntR) 출력
둘이 다른 숫자라면,
	len - max(cntL, cntR) 출력.


모든 숫자가 같다면, 2번의 검사를 하는 과정에서 ans에 음수가 저장된다. ans가 음수라면, 0으로 바꿔주기.