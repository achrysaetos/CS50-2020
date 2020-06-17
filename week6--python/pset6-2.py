#mario blocks again, using python
height = 0
while height<1 or height>8:
    try:
        height = int(input("height? "))
    except:
        print("enter a number between 1 and 8!")

for a in range(1,height+1):
    for b in range(height-a):
        print(" ", end="") 
    for c in range(a):
        print("#", end="")
    print("  ", end="") #halfway there!
    for d in range(a):
        print("#", end="")
    for e in range(height-a):
        print(" ", end="")
    print("") #newline