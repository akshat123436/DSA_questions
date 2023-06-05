def PalidromeChecker(str):
    length = len(str)

    for i in range(0,int(length/2)):
        if(str[i] != str[length-i-1]):
            return 0
    return 1

str = input("Enter the string : ")

if(PalidromeChecker(str) == 0):
    print("The given string is not a palindrome")
else :
    print("The given string is a palindrome")