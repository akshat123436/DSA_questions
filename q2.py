number = int(input());
sum = 0;

while(number):
    sum += number%10;
    number //= 10;

print("Chulbul agree for the number? {}".format(sum > 12));