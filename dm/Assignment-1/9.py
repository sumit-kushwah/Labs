import random, string
with open('./9.txt', 'w') as f:
    for i in range(100):
        len = random.randint(11, 14)
        f.write(''.join(random.choices(string.ascii_lowercase + 
            string.ascii_uppercase + string.digits, k = len)) + "\n")
    f.close()