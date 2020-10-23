import socket
from caching import cacheData

mydir = 'client1Dir'
LOCALHOST = '127.0.0.1'
PORT = 8080

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((LOCALHOST, PORT))

while True:
    command = input()
    client.sendall((bytes(command, 'UTF-8')))
    
    data = client.recv(1024)

    if command == 'get' and len(data) > 0:
        # manually aseembling of data 
        cacheData()
        
    print("server: ", data.decode())

client.close()