import time, random
with open('./13.txt', 'w') as f:
    for num in range(5000, 25001, 5000):
        L = random.choices(range(1, 1000), k = num)
        begin = time.time()
        L.sort()
        end = time.time()
        f.write(str(len(L)) + " " + str(end - begin) + "\n")
    f.close()