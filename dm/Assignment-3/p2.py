import time, csv
begin = time.time()
csvfile = open('output.csv', 'w')
fieldnames = ['no_of_files', 'time_taken_sec']
writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
writer.writeheader()
for filenum in range(1, 501):
    with open("./files/" + str(filenum) + ".txt", 'r+') as f:
        out = f.read()
        f.seek(0)
        f.write(out.upper())
        f.close()
    if (filenum % 100 == 0):
        print(time.time() - begin)
        writer.writerow({
            "no_of_files": filenum,
            "time_taken_sec": time.time() - begin
        })