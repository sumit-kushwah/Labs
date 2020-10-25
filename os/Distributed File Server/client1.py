import socket
from filereciever import *
# from caching import cacheFileInDir

mydir = 'client1Dir'
LOCALHOST = '127.0.0.1'
PORT = 8080

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((LOCALHOST, PORT))

data = client.recv(2048)

print(data.decode())

while True:
    command = input("$ ")
    client.sendall((bytes(command, 'UTF-8')))
    args = command.split();

    if args[0] == 'get' :
       filereciever("ram.txt", client)
       continue;

    data = client.recv(1024)
    print("server: ", data.decode())

client.close()

