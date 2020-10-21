import socket

serverIp = '127.0.0.1'
port = 8080

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((serverIp, port))

while True:
    msg = input()
    client.sendall((bytes(msg, 'UTF-8')))
    
    data = client.recv(1024)

    print("server: ", data.decode())

client.close()