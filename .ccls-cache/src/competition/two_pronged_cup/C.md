#### 테스트 케이스 분석
N==2
2C2 / 1!

N==4

4C2 * 2C2 / 2!



#### N에 대해 일반화

NC2 * (N-2)C2 * ... * 2C2 / (N/2)!

14! 는 long long형으로 계산 가능하다.

ll ans = 1;
for(int i=N;i>=2;i-=2){
	ans*= dp[i][2];
}

ans /= fact(N/2);




#### 다시 일반화
N! / 2^(N/2) / (N/2)!

8 9 10 11 12 13 14

->

N 입력되면,

- N/2+1부터 N까지 곱하기.	
-> 3.4E+18 이므로. 9.22E+18을 넘기지 않아 오버플로우 발생하지 않는다.
- 그 이후, 2^(N/2)로 나누기.






#### 조합 계산
aC2 = a*(a-1)/2;