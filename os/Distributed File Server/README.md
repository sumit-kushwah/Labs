### Distributed File Server (Handles muliple clients)

To start server, type
```
$ python3 server.py
```

To create client use this simple script
 ```python
from client import Client

dir = './client1Dir/'
LOCALHOST = '127.0.0.1'
PORT = 8080

client = Client(LOCALHOST, PORT, dir)
client.run()
 ```
After that, run client script
```
$ python3 client1.py
```

- you can create as many clients using above code, 
- Each client should have their own directory

#### Client commands 
```
ls                  list out server dir
!ls                 list out local dir
fl [--filename]     filelength in bytes of server file
!fl [--filename]    filelength in bytes of local file
get [--filename]    get file from server
send [--filename]   send file to server

```
