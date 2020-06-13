from cs50 import SQL
from sys import argv

if len(argv) < 2:
    print("Incorrect number of arguments.")
    exit()

db = SQL("sqlite:///students.db")
students = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY name", argv[1])

for student in students:
    print(f"{student['name']}, born {student['birth']}")