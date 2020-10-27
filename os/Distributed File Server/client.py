import socket
from commandHandler import *
#use this class to make client easily
class Client:
    def __init__(self, host, port, dir):
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client.connect((host, port))
        self.dir = dir
    
    def run(self):
        data = self.client.recv(2048)
        print(data.decode())
        while True:
            command = input("$ ")
            args = command.split()
            if (args[0] == "quit"):
                self.client.close()
                break
            else:
                clienthandler(args, self)




