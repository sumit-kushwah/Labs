def isPrime(num):
    for e in range(2, num):
        if num % e == 0: return False
    return True

with open('./10.txt', 'w') as f:
    for e in range(600, 800):
        if isPrime(e):
            f.write(str(e) + "\n")
    f.close()