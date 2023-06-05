def calculator() : 
    str = input("Enter the string : ")

    upper=0
    lower = 0

    for i in str:
        if(i >= 'a' and i<= 'z'):
            lower+=1
        elif(i>= 'A' and i<='Z'):
            upper+=1

    print('The number of lowercase letters = ', lower)
    print('The number of uppercase letters = ', upper)

calculator()