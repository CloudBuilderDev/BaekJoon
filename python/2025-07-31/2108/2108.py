# BOJ 2108
import sys
n = int(input())
nums =  [int(sys.stdin.readline().rstrip()) for _ in range(n)]
print(round(sum(nums)/n))
nums.sort()
print(nums[n//2])

dict = {}
for num in nums:
    if num in dict:
        dict[num] += 1
    else :
        dict[num] = 1
max_frequency = max(dict.values())
list_max_freq = [k for k,v in dict.items() if v == max_frequency]
list_max_freq.sort()

print(list_max_freq[0] if len(list_max_freq)==1 else list_max_freq[1])
print(nums[-1]-nums[0])


