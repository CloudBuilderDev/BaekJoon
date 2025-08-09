
#eval() 
result = eval("(3+5)*7")
print(result)



array = [('홍길동', 50), ('이순신',32),('아무개',74)]
result = sorted(array, key=lambda x: x[1], reverse=True)
print(result)


# 순열과 조합 라이브러리 

from itertools import permutations

data = ['A', 'B', 'C']

result = list(permutations(data, 3)) # data에서 3개 뽑아 정렬하는 경우의 수  
print(result)

from itertools import combinations

result = list(combinations(data,2))
print(result)

from itertools import product

print(list(product(data, repeat=2))) # 중복을 허용하여 2개를 뽑는 모든 순열 구하기

from itertools import combinations_with_replacement
print(list(combinations_with_replacement(data,2))) # 중복을 허용하여 2개를 뽑는 모든 조합 구하기 

print("---------------------------")
from collections import Counter

counter = Counter(['red', 'blue', 'red', 'green', 'blue','blue'])

print(counter['blue'])
print(counter['green'])
print(dict(counter))


import math

#최소 공배수(lcm)를 구하는 함수 
def lcm(a,b):
    return a*b // math.gcd(a,b)
a= 21
b = 14
print(math.gcd(a,b))
print(lcm(a,b))
print(math.lcm(a,b))