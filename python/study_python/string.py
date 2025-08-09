a = '"Hello World"'
print(a)
b = a[1:6]
c = a[7:]
print(b)
print(c)
print(b,c)
print(b+c)

#a[2] = 'o' #이건 불가능하다. string객체는 파이썬에서 변경 불가능한 객체이다. 
a_list = list(a)
print(a)
a_list[2] = 'o'
print(a_list)
a = ''.join(a_list)
print(a)