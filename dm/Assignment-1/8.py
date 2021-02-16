L = ["one", "two", "three", "four", "five"]
with open('./8.txt', 'w') as f:
    for e in L:
        f.write(e + ", "+ str(len(e)) + "\n")
    f.close()