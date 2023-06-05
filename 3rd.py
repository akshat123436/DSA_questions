print("\nAKSHAT KOTHAVADE 0901IT201005\n")
school_name = "\nMadhav school of science and commerce\n"
student_names = ["Akshat Kothavade", "Shrey Bindal", "Kanha Bindal", "Pulkit Kumar"]
percentage = (98, 95, 95, 92)
rollnumber = {
    "Akshat Kothavade" : "0901IT201005",
    "Shrey Bindal" : "0901IT201054",
    "Kanha Bindal" : "0901IT201029",
    "Pulkit Kumar" : "0901IT201045"
}
marks = {98, 95, 95, 92}

print(school_name)
print ("Marks of All students : \n")
for i in range (len(student_names)):
    print(student_names[i], " ", rollnumber[student_names[i]])
    print("Marks : ", percentage[i],"\n")

print("Average Marks of all students : ")
sum = 0
for a in marks:
    sum += a
print(sum/len(marks), "\n")

print("Maximum Marks : ")
max = 0
name = ""
for i in range(len(percentage)):
    if(percentage[i] > max):
        max = percentage[i]
        name = student_names[i]

print(name, " - ", max, "\n")

