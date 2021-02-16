S1 = set([10, 20, 30, 40, 50, 60])
S2 = set([40, 50, 60, 70, 80, 90])

# i
S1.add(55)
S1.add(66)
print(S1)
# ii
S1.remove(10)
S1.remove(30)
print(S1)
# iii
if 40 in S1: print("yes")
else: print("no")
# iv
print(S1.union(S2))
# v
print(S1.intersection(S2))
# vi
print(S1)
print(S2)
print(S1 - S2)
