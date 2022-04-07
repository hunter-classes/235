

def divide(a,b):
    return a/b

a=10
b=0
try:
    print("Trying to divide")
    result  = divide(a,b)
    print("It worked, the result is",result);
except:
    print("We got an exception so that it worked line isn't printed")

print("done")

