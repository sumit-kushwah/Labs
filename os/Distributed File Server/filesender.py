import os
import tqdm

SEPARATOR = "<SEPARATOR>"
BUFFER_SIZE = 4096 # send 4096 bytes each time step

def filesender(filepath, socket):
    try:
        filesize = os.path.getsize(filepath)
    except FileNotFoundError:
        return socket.send("FILE_NOT_FOUND".encode())

    # send the filename and filesize
    socket.send(f"{filepath}{SEPARATOR}{filesize}".encode())
    progress = tqdm.tqdm(range(filesize), f"Sending {filepath}", unit="B", unit_scale=True, unit_divisor=1024)
    with open(filepath, "rb") as f:
        for _ in progress:
            # read the bytes from the file
            bytes_read = f.read(BUFFER_SIZE)
            print(len(bytes_read))
            if not bytes_read:
                print("File sent successfully!!")
                break
            # we use sendall to assure transimission in 
            # busy networks
            print("sumit kushwah")
            socket.sendall(bytes_read)
            # update the progress bar
            progress.update(len(bytes_read))
