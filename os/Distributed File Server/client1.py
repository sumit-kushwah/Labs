from client import Client

mydir = './client1Dir/'
LOCALHOST = '127.0.0.1'
PORT = 8080

client = Client(LOCALHOST, PORT, mydir)
client.run()