import os
import math

SEPARATOR = "<SEPARATOR>"
BUFFER_SIZE = 1024 

def filesender(fileDir, filename, socket):

    filepath = fileDir + filename
    try:
        filesize = os.path.getsize(filepath)
    except FileNotFoundError:
        socket.send("FILE_NOT_FOUND".encode())

    socket.send(f"{filepath}{SEPARATOR}{filesize}".encode())

    times = math.ceil(int(filesize) / BUFFER_SIZE)

    print("File sending...")
    with open(filepath, "rb") as f:
        for _ in range(times):
            b = f.read(BUFFER_SIZE)
            socket.sendall(b)

    print("File sent successfully!!")



def filereciever(fileDir, socket):

    received = socket.recv(1024).decode()

    if (received == "FILE_NOT_FOUND"):
        print("No such file")
        return
    else :
        filename, filesize = received.split(SEPARATOR)

    filename = os.path.basename(filename)
    filesize = int(filesize)

    times = math.ceil(int(filesize) / BUFFER_SIZE)
    print("File receiving...")
    with open(fileDir + filename, "wb") as f:
        for _ in range(times):
            b = socket.recv(BUFFER_SIZE)
            f.write(b)

    print("File received Successfully!!")

def getfileLength(fileDir, filename):
    try:
        return os.path.getsize(fileDir + filename)
    except FileNotFoundError:
        return "FILE_NOT_FOUND"

def getFilesList(dir):
    files = os.listdir(dir);
    filetext = ""
    ll = len(files)
    for i in range(ll):
        if (i == ll - 1):
            filetext += files[i]
        else:
            filetext += files[i] + "\n"

    return filetext