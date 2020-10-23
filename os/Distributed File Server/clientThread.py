import socket
import threading
from commandHandler import handle

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
            msg = data.decode().split()
            maincommand = msg[0]
            metadata = None
            try :
                metadata = msg[1]
            except IndexError:
                metadata = None

            if maincommand =='bye':
              break
            else:
                self.csocket.send(bytes(handle(maincommand, metadata),'utf-8'))
            
            
        print ("Client at ", self.clientAddress , " disconnected...")
        

