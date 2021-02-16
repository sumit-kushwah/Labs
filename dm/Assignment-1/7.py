D = {
    1: "One",
    2: "Two",
    3: "Three",
    4: "Four",
    5: "Five"
}
with open('./7.txt', 'w') as f:
    for key in D:
        f.write(str(key) + ", "+ D[key] + "\n")
    f.close()