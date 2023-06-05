# for importing the random function to generate list of random numbers
import random
list1 = random.sample(range(1,100),15);

list1.sort()

print("The random list is : ", list1)

num = int(input("Enter the number you want to search : "))

def binary_searcher(list1, num, low, high) :
    while(high-low > 1):
        mid = (low + high)//2
        if(list1[mid]>num):
            high = mid-1
        elif(list1[mid]<num):
            low = mid+1
        else : 
            return mid
    if(list1[high] == num):
        return high
    elif(list1[low]==num):
        return low
    else:
        return -1

ans = binary_searcher(list1, num,0,len(list1)-1)+1

if(ans == 0) :
    ans = "Not Available"
print("The position of the number : ", num , " in the list : ", list1, " is : ", ans)