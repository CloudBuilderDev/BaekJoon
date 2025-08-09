
#when list = [] empty, print(list)?
a= []
print(a) # []
# print(a[0]) # out of bound

b = [0,1,2,[3,4]]
print(b)
print(b[0])
print(b[3])
print(b[3][0])

c = [0]
c  = 10*c
print(c)

a = [0,1,2,3,4,5,6]
print(a[-1])
print(a[-0])

print(a[0:3])

#list 컴프리헨션
array = [i for i in range(10)] 
print(array)

array2 = [i*i for i in range(20) if(i%2 == 0)]
print(array2)


n = 3;m =4
array3 = [[0]*m for _ in range(n)]
array3[1][1] = 5
print(array3)


#이렇게 하면, 모든 행의 1번째에 5가들어가게 된다...
array4 = [[0]*m] * n
array4[1][1] = 5
print(array4)

for i in range(3): #0~2번째 인덱스까지
    print(array4[i])


a = [1,4,3]
a.append(2)

a.sort()
print(a)
a.sort(reverse=True)
print(a)
a.reverse()
print(a)

a.insert(2,5)
print(a)
print(a.count(5))
a.remove(5)
print(a)

array5 = [1,2,3,4,5,5,5]
remove_set = {3,5}
result = [i for i in a if i not in remove_set]
print(result)