f = open("120solutions.txt",'r')

results = []

for line in f:
    print(line.replace(' ','').split(','))
    cover = [0 for i in range(600)]
    for item in line.replace(' ','').split(','):
        cover[int(item)] = 1
    results.append(cover)

with open("chromosomes.txt",'w') as out:
    for result in results:
        for item in result:
            out.write(str(item).replace('\n',''))
        out.write('\n')
