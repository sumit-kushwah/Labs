# given list
L = [11, 12, 13, 14]
# i
L.append(50)
L.append(60)
print(L)
# ii
L.remove(11)
L.remove(13)
print(L)
# iii
L.sort()
print(L)
# iv
# L = sorted(L, reverse=True)
L.reverse()
print(L)
# v
print(13 in L)
# vi
print(len(L))
# vii
sum = 0
for v in L: sum += v
print(sum)
# viii
sum = 0
for v in L:
    if v & 1: sum += v
print(sum)
# ix
sum = 0
for v in L:
    if ~(v & 1): sum += v
print(sum)
# x
sum = 0
def isPrime(num):
    for i in range(2, num):
        if (num % i == 0): return False
    return True

for v in L:
    if isPrime(v): sum += v
print(sum)
# xi
L.clear()
print(L)
#xii
del(L)
print(L) # This line will output an error