import random
def isPrime(num):
    for e in range(2, num):
        if num % e == 0: return False
    return True

L = random.choices(range(101, 900), k = 100)
print(L)
# i
for num in L:
    if num & 1: print(num) 
# ii
for num in L:
    if (num % 2 == 0): print(num)
# iii
for num in L:
    if isPrime(num): print(num)