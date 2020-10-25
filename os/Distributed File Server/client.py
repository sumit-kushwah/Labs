import socket

class Client:
    def __init__(self, host, port):
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client.connect((host, port))
    
    def get(self):
        return self.client
    
    
