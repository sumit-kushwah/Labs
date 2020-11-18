import socket
import datetime
from dateutil import parser
from timeit import default_timer as timer

HOST = '127.0.0.1'
PORT = 8080

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect((HOST, PORT))

request_time = timer()

server_time = parser.parse(s.recv(1024).decode())
response_time = timer()

actual_time = datetime.datetime.now()

print("Clock server time: ", str(server_time))

delay = response_time - request_time

print("Process delay latency: ", str(delay))

print("Actual client time: ", str(actual_time))

# synchronizing client time with clock server

client_time = server_time + datetime.timedelta(seconds=(delay / 2))

print("After synchronizing new client time: ", str(client_time))

error = actual_time - client_time

print("Synchronization error: ", str(error.total_seconds()), " seconds")

s.close()

