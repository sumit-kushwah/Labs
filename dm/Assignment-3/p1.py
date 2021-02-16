import random, string
for filenum in range(1, 501):
    with open("./files/" + str(filenum) + ".txt", 'w') as f:
        for linenum in range(20000):
            f.write(''.join(random.choices(string.ascii_lowercase + 
            string.ascii_uppercase + string.digits, k = 20)) + "\n")
        f.close()