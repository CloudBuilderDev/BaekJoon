# input 함수는 한 줄의 문자열을 입력받는 함수이다. 
# map() 함수는 리스트의 모든 원소에 각각 특정한 함수를 적용할 때 사용한다. 
# 예를 들어 공백을 기준으로 구분된 데이터를 입력 받을 때 다음과 같이 사용한다. 
# lsit(map(int, input().split()))

# 공백을 기준으로 구분된 데이터의 개수가 많지 않다면, 단순히 다음과 같이 사용한다. 
# a, b, c = map(int, input().split())

data = list(map(int,input().split()))
print(data)


# 빠르게 입력을 받고 싶다면, sys라이브러리에 정의되어 있는 sys.stdin.readline()을 사용하자. 
# 단, 위 함수로 입력을 받을 경우, 엔터가 줄 바꿈 기호로 같이 입력이 되므로, rstrip()을 통해 제거해줄 필요가 있다. 

# import sys
# data = sys.stdin.readline().rsplit()
# print(data)


#a = 1; b=2
#print(a,b)
#print(a,end="")
#print(b,end=" ")
#print("hello")