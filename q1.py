
R_class = input("R_class=");

S_class = input("S_class=");

R_age = int(input("R_age="));

S_age = int(input("S_age="));

R_math = int(input("R_math="));

S_math = int(input("S_math="));

R_sci = int(input("R_sci="));

S_sci = int(input("S_sci="));

print("Both are in same class ? {} ".format(R_class==S_class));
print("Both are of different age ? {} ".format(R_age!=S_age));
print("Ram score more than Shyam in Math ? {} ".format(R_math>S_math));
print("Ram score less than Shyam in Science ? {} ".format(R_sci<S_sci));
print("Ram score more or equal than Shyam in Math? {} ".format(R_math>=S_math));