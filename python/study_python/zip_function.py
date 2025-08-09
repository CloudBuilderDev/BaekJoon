# zip()은 파이썬에서 여러 개의 반복 가능한(interable) 객체를 
# 병렬로 묶어서 다룰 수 있게 해주는 내장 함수이다.

# 기본 정의 : zip(iter1, iter2, ...)
# - 각 iterable에서 같은 인덱스의 요소끼리 묶어서 튜플로 반환하는 이터레이터를 생성한다. 
# 가장 짧은 iterable의 길이에 맞춰 동작한다. 

a = [1, 2, 3]
b = ['a', 'b', 'c']

for x, y in zip(a,b): # in 뒤에는 항상 iterable 객체가 와야 한다. 
    print(x,y) # Q: in 문은 항상 for문하고만 쓰이는가? 아니다 

# zip()은 이터레이터이기 때문에 리스트로 감싸야 출력이 보인다. 

# in 문에 대해 알아보자.

# 대표적으로 보통 for.. in 문이 있다. 
# 또 if .. in .. : 도 있다. 
if 3 in [1,2,3] :
    print("thre exits 3")

if 'a' not in 'hello' : # 내부적으로 'hello'.__contains__('a') 호출
    print("not exist a") 

# in 연산은 내부적으로 __contains__() 또는 __iter__()를 호출한다. 
# 즉, in 뒤에는 항상 iterable 객체거나 __contains__()메서드를 가진 객체이어야 한다. 

# 참고로 str과 list는 모두 iterable임과 동시에 __contains_()를 가진다. 
