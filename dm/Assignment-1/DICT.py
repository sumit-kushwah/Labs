D = {
    1: 5.6,
    2: 7.8,
    3: 6.6,
    4: 8.7,
    5: 7.7
}
# i
D[8] = 8.8
print(D)
# ii
D.pop(2)
print(D)
# iii
if 6 in D: print("yes") 
else : print("no")
# iv
print(len(D))
# v
sum = 0
for v in D.values(): sum += v
print(sum)
# vi
D[3] = 7.1
print(D)
# vii
D.clear()
print(D)



