import socket

localhost = '127.0.0.1'
port = 8080

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((localhost, port))
server.listen()

print(f"server is listening at { localhost } and port no { port } ")

print("Now client can communicate with server!!")

clientconnection, clientaddress = server.accept()

while True:
    
    # print(f"{ clientaddress } client connected !!")
    data = clientconnection.recv(1024)
    print("client: ", data.decode())

    msg = input()
    clientconnection.sendall(bytes(msg, 'UTF-8'))
    # clientconnection.send(bytes("Hello my name is sumit kushwah!!", 'UTF-8'))
    # clientconnection.close()
