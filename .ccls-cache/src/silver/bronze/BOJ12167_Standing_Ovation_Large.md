Standing Ovation (Large) 다국어
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
5 초	512 MB	177	136	132	78.571%
문제
It's opening night at the opera, and your friend is the prima donna (the lead female singer). You will not be in the audience, but you want to make sure she receives a standing ovation -- with every audience member standing up and clapping their hands for her.


Initially, the entire audience is seated. Everyone in the audience has a shyness level. An audience member with shyness level Si will wait until at least Si other audience members have already stood up to clap, and if so, she will immediately stand up and clap. If Si = 0, then the audience member will always stand up and clap immediately, regardless of what anyone else does. For example, an audience member with Si = 2 will be seated at the beginning, but will stand up to clap later after she sees at least two other people standing and clapping.

You know the shyness level of everyone in the audience, and you are prepared to invite additional friends of the prima donna to be in the audience to ensure that everyone in the crowd stands up and claps in the end. Each of these friends may have any shyness value that you wish, not necessarily the same. What is the minimum number of friends that you need to invite to guarantee a standing ovation?

입력
The first line of the input gives the number of test cases, T.  T test cases follow. Each consists of one line with Smax, the maximum shyness level of the shyest person in the audience, followed by a string of Smax + 1 single digits. The kth digit of this string (counting starting from 0) represents how many people in the audience have shyness level k. For example, the string "409" would mean that there were four audience members with Si = 0 and nine audience members with Si = 2 (and none with Si = 1 or any other value). Note that there will initially always be between 0 and 9 people with each shyness level.

The string will never end in a 0. Note that this implies that there will always be at least one person in the audience.

Limits
1 ≤ T ≤ 100.
0 ≤ Smax ≤ 1000.
출력
For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the minimum number of friends you must invite.

예제 입력 1 
4
4 11111
1 09
5 110011
0 1
예제 출력 1 
Case #1: 0
Case #2: 1
Case #3: 2
Case #4: 0
힌트
In Case #1, the audience will eventually produce a standing ovation on its own, without you needing to add anyone -- first the audience member with Si = 0 will stand up, then the audience member with Si = 1 will stand up, etc.

In Case #2, a friend with Si = 0 must be invited, but that is enough to get the entire audience to stand up.

In Case #3, one optimal solution is to add two audience members with Si = 2.

In Case #4, there is only one audience member and he will stand up immediately. No friends need to be invited.

### solution
int T;
vector<int> arr;
int sum=0;
int ans=0;
int N;

N+1번 반복.

막힐때마다 ans 증가.
sum은 계속 증가.

for(curIdx,0,N+2){
	if(sum < curIdx){
		ans+=curIdx-sum;
		arr[curIdx] -= 
		sum+=curIdx-sum;

	}
}
