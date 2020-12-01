"""
    This cipher uses of concept of linear algebra
    It makes uses of modulo arithmetic
    matrix multiplication
    it is also block cipher.
    hill cipher is fairly complex
    **ENCRYPTION**
    E(K, P) = (K*P) mod 26
    k = matrix formed key
    P = plaintex in the form of vector
    **DECRYPTION**
    D(K, C) = (K-1 *C) mod 26
    
    reference: "https://www.educative.io/edpresso/what-is-the-hill-cipher"
"""


import numpy as np

#key is "dcdf"  which represents key matrix as [[3, 3], [2, 5]]
keymatrix = [[3, 3], [2, 5]]
ciphertext = ""

plaintext = input("please enter string of even length:")
i = 0
while i < (len(plaintext)):
    temp = []
    temp.append((ord(plaintext[i]) - 97) % 26)
    temp.append((ord(plaintext[i + 1]) - 97) % 26)
    a = np.array(keymatrix)
    b = np.array(temp)
    c = a.dot(b)
    for num in c:
        ciphertext += chr(97 + (num % 26))
    i += 2

print(ciphertext)




