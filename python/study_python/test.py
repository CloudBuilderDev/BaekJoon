a = 7
b = 3
print(a/b)

print(a//b)

a = 'a'
# print(int(a)) #아래와 같은 경우만 int()로 형 변환할 수 있다. 
b = '1'
print(int(b))

#만약 아스키코드에 대응하는 정수를 알고 싶다면 다음과 같이 해야한다. 
a = ord(a)
print(a) #97
print(chr(a)) # 다시 아스키코드 97에 대응하는 문자로 변환 => 'a'

num = 66
print(chr(num))

