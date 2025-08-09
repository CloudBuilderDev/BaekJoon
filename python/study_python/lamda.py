array = [('홍길동', 50), ('이순신',32),('아무개',74)]

def my_key(x):
    return x[1]

print(sorted(array, key=my_key))
print(sorted(array, key=lambda x:x[1]))

print("---------------------")

list1 = [1,2,3,4,5]
list2 = [6,7,8,9,10]

result = map(lambda a, b: a+b,list1,list2)
print(list(result))