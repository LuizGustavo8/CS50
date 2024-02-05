import cs50

# Define Variables
line = 0
diff = 0
height = 0

# Prompt user for positive integer
while True:
    height = cs50.get_int("Height: ")
    if (height >= 1 and height < 9):
        break

# Print the lines until it gets to the Height
while (line < height):
    # Keeps the value of the current line and the current diference between Height and line
    line = line + 1
    diff = height - line

    # Print line by line
    for i in range(line):
        # Print
        for j in range(diff):
            print(" ", end="")
        # Resets the diference so it doesnt interfire in the next line and then prints the symbol
        diff = 0
        print("#", end="")

    print()
