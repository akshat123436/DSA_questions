import math


English = int(input())
Math = int(input())
Computer = int(input())
Physics = int(input())
Chemistry = int(input())

marks = English + Math + Computer + Physics + Chemistry
percentage = (marks/500) * 100
grade = "Fail"

if(percentage > 90) :
    grade = "A Grade"
elif(percentage>=81):
    grade = "B Grade"
elif(percentage>=71):
    grade = "C Grade"
elif(percentage>=61):
    grade = "D Grade"
elif(percentage>=40):
    grade = "E Grade"
else:
    grade = "Fail"

print("Total Marks =",marks)
print("Marks Percentage =",percentage)
print(grade)
