import os
import tqdm

SEPARATOR = "<SEPARATOR>"
BUFFER_SIZE = 4096 # send 4096 bytes each time step

def filereciever(filepath, socket):
    received = socket.recv(BUFFER_SIZE).decode()

    if (received == "FILE_NOT_FOUND"):
        print("this file not found")
        return
    else :
        filename, filesize = received.split(SEPARATOR)

    filename = os.path.basename(filename)
    filesize = int(filesize)
    # send the filename and filesize
    socket.send(f"{filepath}{SEPARATOR}{filesize}".encode())

    # progress = tqdm.tqdm(range(filesize), f"Receiving {filename}", unit="B", unit_scale=True, unit_divisor=1024)
    with open(filename, "wb") as f:
        while True:
            # read 1024 bytes from the socket (receive)
            bytes_read = socket.recv(BUFFER_SIZE)
            if not bytes_read:    
                # nothing is received
                print("File recieved successfully!!")
                break
            # write to the file the bytes we just received
            f.write(bytes_read)
            # update the progress bar
            # progress.update(len(bytes_read))
