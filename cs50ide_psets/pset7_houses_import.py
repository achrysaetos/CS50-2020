from cs50 import SQL
from csv import reader
from sys import argv

db = SQL("sqlite:///students.db")

if len(argv) < 2:
    print("Incorrect number of arguments.")
    exit()

with open(argv[1], newline="") as file:
    characters = reader(file)
    for character in characters:
        db.execute("INSERT INTO students(name, house, birth) VALUES(?, ?, ?)", 
                    character[0], character[1], character[2])