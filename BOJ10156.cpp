a,b,c=map(int,input().split())
ans = a*b-c
if ans<0:
	ans=0
print(ans)