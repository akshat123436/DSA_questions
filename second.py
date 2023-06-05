temp = []
n = int(input("Enter the number of elements in the list : "))
for i in range(0,n):
    num = int(input())
    temp.append(num)

print (temp)

count =0

for i in temp : 
    if((i%2==0)):
        print(i)

