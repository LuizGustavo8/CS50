import csv
import sys


def main():

    # Check for command-line usage

    if len(sys.argv) != 3:
        print("Usage: python dna.py [csv file] [txt file]")

    # Read database file into a variable

    # First the header in to a list
    with open(f"{sys.argv[1]}") as file:
        reader = csv.DictReader(file)
        # print(reader.fieldnames)

    # And then the content into a dictionary
    rows = []
    with open(f"{sys.argv[1]}") as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)
            # print(row)

    # Read DNA sequence file into a variable
    f = []
    with open(f"{sys.argv[2]}") as file:
        f = file.read()
        # print(f)

    # Find longest match of each STR in DNA sequence
    longest_matches = []

    for i in range(1, len(reader.fieldnames)):
        longest_match(f, reader.fieldnames[i])
        longest_matches.append(longest_match(f, reader.fieldnames[i]))
    # print(longest_matches)
    # Check database for matching profiles
    for row in rows:
        counter = 0
        for j in range(int(len(reader.fieldnames)) - 1):
            # print(longest_matches[j])
            # print(row[f"{reader.fieldnames[j+1]}"])
            if (int(longest_matches[j]) == int(row[f"{reader.fieldnames[j+1]}"])):
                counter = counter + 1
                # print(f"counter: {counter}")
                if (counter == int(len(reader.fieldnames)) - 1):
                    print(f"{row['name']}")
                    sys.exit()
    else:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
