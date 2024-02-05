import cs50


def main():
    change = 0

    # Prompt for geting the change owned value
    while True:
        change = (cs50.get_float("Change owed:") * 100)
        if (change > 0):
            break

    # Remove as much 25 as possible from the start value
    c25 = calculate_25(change)
    change = change - (c25 * 25)

    # Remove as much 10 as possible from the current value
    c10 = calculate_10(change)
    change = change - (c10 * 10)

    # Remove as much 5 as possible from the current value
    c05 = calculate_05(change)
    change = change - (c05 * 5)

    # Remove as much 1 as possible from the current value
    c01 = calculate_01(change)
    change = change - (c01 * 1)

    # print the total coins
    print(f"{c25 + c10 + c05 + c01}")


# Calculate how many 25 to use
def calculate_25(change):
    count_25 = 0

    while (change >= 25):
        count_25 = count_25 + 1
        change = change - 25

    return count_25


# Calculate how many 10 to use
def calculate_10(change):
    count_10 = 0

    while (change >= 10):
        count_10 = count_10 + 1
        change = change - 10

    return count_10


# Calculate how many 05 to use
def calculate_05(change):
    count_05 = 0

    while (change >= 5):
        count_05 = count_05 + 1
        change = change - 5

    return count_05


# Calculate how many 01 to use
def calculate_01(change):
    count_01 = 0

    while (change >= 1):
        count_01 = count_01 + 1
        change = change - 1

    return count_01


main()
