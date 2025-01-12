import csv
from sys import argv


def main():

    # TODO: Check for command-line usage argc == 3 ,error msg csv, txt
    if len(argv) != 3:
        print("Usage: python dna.py FILE.CSV FILE.TXT")
        exit(1)

    # TODO: Read database file csv into a variable
    with open(argv[1], 'r') as csvfile:
        reader = csv.DictReader(csvfile)
        keys = reader.fieldnames
        keys = keys[1:]

        # TODO: Read DNA sequence file into a variable
        with open(argv[2], 'r') as txtfile:
            reading = txtfile.read()
            x = {}
            shortlisted = []
            # TODO: Find longest match of each STR in DNA sequence
            for subseq in keys:
                x[subseq] = longest_match(reading, subseq)

                with open(argv[1], 'r') as csvfile:
                    reader = csv.DictReader(csvfile)

                    for person in reader:
                        if int(person[subseq]) == int(x[subseq]):
                            if person["name"] not in shortlisted and subseq == 'AGATC':
                                shortlisted.append(person["name"])

                        elif int(person[subseq]) != int(x[subseq]) and person["name"] in shortlisted:
                            shortlisted.remove(person["name"])

                    if len(shortlisted) == 0:
                        print("No Match")
                        exit(2)
            if len(shortlisted) == 1:
                print(shortlisted[0])
                exit(0)
        # TODO: Check database for matching profiles

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

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
