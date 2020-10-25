import os

# return appropiate response
def handle(command, meta = None):
    if command == 'fl':
        if (meta):  
            return str(getfileLength(meta)) + " bytes"
        else:
            return "INVALID_USAGE_OF_COMMAND"

    elif command == 'ls':
        return getFilesList();
    else:
        return "INVALID_COMMAND"



def getfileLength(filename):
    try:
        return os.stat("./serverDir/" + filename).st_size
    except IOError:
        return "FILE_NOT_FOUND"

def getFile(filename, csocket):
    if (filename):  
        try:
            f = open("./serverDir/" + filename, 'r')
            file = f.read()
            with open(filename, "rb") as f:
            # read the bytes from the file
                while True:
                    bytes_read = f.read(4096)
                    if not bytes_read:
                        print("File transfered successfully!!")
                        break
                    # we use sendall to assure transimission in 
                    # busy networks
                    csocket.sendall(bytes_read)
                
        except IOError:
            return "FILE_NOT_FOUND"
    else:
        return "INVALID_USAGE_OF_COMMAND"

    

def getFilesList():
    files = os.listdir("./serverDir");
    filetext = "\n"
    for file in files:
        filetext += file + "\n"
    return filetext

