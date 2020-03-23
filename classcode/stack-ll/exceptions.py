
def divide(a,b):
    return a/b


a = 10
b = 0

try:
    print("Things worked")
    result = a/b
    
    print(result)
except:
    print("WE HAVE AN ERROR")
    result = 0

print(result)
