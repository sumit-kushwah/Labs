from functions import *

def clienthandler(args, client):
    maincommand = args[0]

    if maincommand == "!ls":
        print(getFilesList(client.dir))
        return
    elif maincommand == "ls":
        client.client.sendall(bytes(maincommand, 'utf-8'))
        bs = client.client.recv(12000)
        print(bs.decode())
        return
    elif maincommand == "!fl":
        try: 
            res = getfileLength(client.dir, args[1])
            if (res == "FILE_NOT_FOUND"):
                print("No such file")
            else:
                print(str(res) + " bytes")
        except IndexError:
            print("too few arguments")
        return
    elif maincommand == "fl":
        try: 
            client.client.sendall(bytes(args[0] + " " + args[1], 'utf-8'))
            bs = client.client.recv(12000)
            print(bs.decode())
        except IndexError:
            print("too few arguments")
        return

    elif maincommand == "get":
        try: 
            client.client.sendall(bytes(args[0] + " " + args[1], 'utf-8'))
            filereciever(client.dir, client.client)
        except IndexError:
            print("too few arguments")
        return
    
    elif maincommand == "send":
        try: 
            try:
                filesize = os.path.getsize(client.dir + args[1])
                client.client.send(bytes(args[0] + " " + args[1], 'utf-8'))
                data = client.client.recv(1024).decode()
                filesender(client.dir, args[1], client.client)
            except FileNotFoundError:
                print("No such file")
        except IndexError:
            print("too few arguments")
        return
    
    else:
        print("Invalid command")
    

def serverHandler(args, csocket):  
    maincommand = args[0]

    if maincommand == "ls":
        csocket.sendall(bytes(getFilesList('./serverDir/'), 'utf-8'))
        return
    elif maincommand == "fl":
        res = getfileLength('./serverDir/', args[1])
        if (res == "FILE_NOT_FOUND"):
            csocket.sendall(bytes("No Such File", 'utf-8'))
        else:
            csocket.sendall(bytes(str(res) + " bytes", 'utf-8'))
        return

    elif maincommand == "get":
        filesender('./serverDir/', args[1], csocket)
        return
    
    elif maincommand == "send":
        csocket.send(bytes("ok", 'utf-8'))
        filereciever('./serverDir/', csocket)
        return


    



