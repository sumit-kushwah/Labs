import random
import string
# i
for i in range(100):
    len = random.randint(6, 8)
    str = ''.join(random.choices(string.ascii_lowercase 
            + string.ascii_uppercase + string.digits, k = len))
    print(str)
# ii
def isPrime(num):
    for e in range(2, num):
        if num % e == 0: return False
    return True

for num in range(600, 800):
    if isPrime(num):
        print(num)
# iii
for num in range(100, 1000): 
    if num % 63 == 0:  print(num)