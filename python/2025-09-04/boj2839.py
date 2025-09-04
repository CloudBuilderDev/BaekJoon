n = int(input())

dp = [0]*(n+3)
dp[1] = -1
dp[2] = -1
dp[3] = 1
dp[4] = -1
dp[5] = 1

for i in range(6, n+1):
    if n<6 :break
    # print(i)
    if dp[i-3]==-1 and dp[i-5]==-1:
        dp[i]=-1
        continue
    elif dp[i-3] ==-1 and dp[i-5] != -1:
        dp[i] = dp[i-5]+1
        # print("in 2 case")
    elif dp[i-3] != -1 and dp[i-5] == -1:
        dp[i] = dp[i-3]+1
        # print("in 3case")
    else :
        dp[i] = min(dp[i-3]+1, dp[i-5]+1)
        # print("in 4 case")
print(dp[n])