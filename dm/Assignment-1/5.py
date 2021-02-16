import random

L1 = random.choices(list(range(11, 30)), k = 10)
L2 = random.choices(list(range(11, 30)), k = 10)
print(L1)
print(L2)
# i
print(set(L1).intersection(set(L2)))
# ii
print(set(L1))
print(set(L2))
# iii
print(min(L1))
print(min(L2))
# iv
print(max(L1))
print(max(L2))
# v
print(sum(L1))
print(sum(L2))