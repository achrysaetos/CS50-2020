from csv import reader, DictReader
from sys import argv

if len(argv) < 3:
    print("Error in number of arguments.")
    exit()

# read txt file and store it as a string
with open(argv[2]) as dnafile:
    dnareader = reader(dnafile)
    for row in dnareader:
        dna = row[0]

# read csv file and store the header row of patterns in a list
with open(argv[1]) as peoplefile:
    people = reader(peoplefile)
    for row in people:
        dnaSequences = row
        dnaSequences.pop(0)
        break
    
# copy the list into a dictionary where the genes are the keys
sequences = {}
for item in dnaSequences:
    sequences[item] = 1

# count the number of repetitions of each value from the sequence dictionary
for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(dna)):
        # avoid counting sequences more than once
        while temp > 0:
            temp -= 1
            continue

        # start counting if the segment of dna corresponds to the key
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                temp += 1
                i += l

            if temp > tempMax:
                tempMax = temp

    sequences[key] += tempMax

# get the number of repetitions of each value for each person and see which one matches
with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0

        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")