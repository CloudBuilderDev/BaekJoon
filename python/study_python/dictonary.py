# 딕셔너리는 키와 값을 쌍으로 가지는 자료형이다. 
# 리스트와 튜플은 값을 순차적으로 저장하지만, 딕셔너리는 그렇지 않다.  
# 키값으로는 변경 불가능한 자료형만을 사용할 수 있다. 
# 파이썬의 딕셔너리는 해시테이블을 이용한 자료형으로, 데이터 조회 및 수정에 있어 O(1)의 시간을 가진다. 

data= dict()
tuple = [1,2,3,4,5]
list = list("abcde")
print(list)
for i in range(5) :
    data[tuple[i]] = list[i]

print(data)

if 'a' in data.values() : 
    print("값 중에 a가 있습니다.")

if 1 in data :
    print("키중에 1이 있습니다.")

# 딕셔너리로부터 키 혹은 값만으로 구성된 리스트를 추출할 수 있다. 
print(data.keys())
print(data.values())