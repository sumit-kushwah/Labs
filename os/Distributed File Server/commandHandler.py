import os

# return appropiate response
def handle(command, meta = None):
    if command == 'fl':
        if (meta):  
            return getfileLength(meta) + " bytes"
        else:
            return "please enter a filename!!"

    # works with only text files
    if command == 'get':
        if (meta):  
            return getFile(meta)
        else:
            return "Please enter a filename!!"

    if command == 'ls':
        return getFilesList();
    else:
        return "Invalid command"


def getfileLength(filename):
    try:
        return os.stat("./serverDir/" + filename).st_size
    except IOError:
        return "file not found!"

def getFile(filename):
    try:
        f = open("./serverDir/" + filename, 'r')
        file = f.read()
        return file

    except IOError:
        return "file not found!"

def getFilesList():
    files = os.listdir("./serverDir");
    filetext = "\n"
    for file in files:
        filetext += file + "\n"
    
    print(filetext)
    return filetext
