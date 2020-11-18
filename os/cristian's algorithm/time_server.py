import socket
import datetime

HOST = '127.0.0.1'
PORT = 8080

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen()

while True:
    conn, address = s.accept() 
    print("server connected to: ", address)

    conn.send(str(datetime.datetime.now()).encode())

    conn.close()
