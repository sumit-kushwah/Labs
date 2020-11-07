import numpy as np
from numpy.compat import long
from numpy import matrix
from numpy import linalg

# this code finds inverse of matrix
def modMatInv(A,p):       # Finds the inverse of matrix A mod p
  n=len(A)
  A=matrix(A)
  adj=np.zeros(shape=(n,n))
  for i in range(0,n):
    for j in range(0,n):
      adj[i][j]=((-1)**(i+j)*int(round(linalg.det(minor(A,j,i)))))%p
  return (modInv(int(round(linalg.det(A))),p)*adj)%p

def modInv(a,p):          # Finds the inverse of a mod p, if it exists
  for i in range(1,p):
    if (i*a)%p==1:
      return i
  raise ValueError(str(a)+" has no inverse mod "+str(p))

def minor(A,i,j):    # Return matrix A with the ith row and jth column deleted
  A=np.array(A)
  minor=np.zeros(shape=(len(A)-1,len(A)-1))
  p=0
  for s in range(0,len(minor)):
    if p==i:
      p=p+1
    q=0
    for t in range(0,len(minor)):
      if q==j:
        q=q+1
      minor[s][t]=A[p][q]
      q=q+1
    p=p+1
  return minor
# find inverse code ends here

keymatrix = [[3, 3], [2, 5]]
plaintext = ""

ciphertext = "kgimjkkajuvj"
i = 0
while i < (len(ciphertext)):
    temp = []
    temp.append((ord(ciphertext[i]) - 97) % 26)
    temp.append((ord(ciphertext[i + 1]) - 97) % 26)
    a = modMatInv(keymatrix, 26)
    b = np.array(temp)
    c = a.dot(b)
    for num in c:
        plaintext += chr(97 + (round(num) % 26))
    i += 2

print(plaintext)