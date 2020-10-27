import socket
import threading
from commandHandler import serverHandler

class ClientThread(threading.Thread):
    def __init__(self, clientAddress, clientsocket):
        threading.Thread.__init__(self)
        self.csocket = clientsocket
        self.clientAddress = clientAddress
        print("New connection added:", clientAddress)

    def run(self):
        print ("Connection from : ", self.clientAddress)
        self.csocket.send(bytes("Successfully connected with server.",'utf-8'))
        while True:
            data = self.csocket.recv(1024)
            args = data.decode().split()
            try:
                maincommand = args[0]
                if (maincommand == "quit"):
                    self.csocket.close()
                    break
                else:
                    serverHandler(args, self.csocket)   
            except:
                self.csocket.close()
                break
            
        print ("Client at ", self.clientAddress , " disconnected...")
        

