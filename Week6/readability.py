import cs50

# Read text input
text = cs50.get_string("Text: ")

# Instanciate variables
letters = 0
words = 1
sentences = 0

# Count the number of letters, words, and sentences in the text
for i in range(len(text)):

    if (text[i] == ' '):
        words = words + 1

    if ((text[i] == '.') or (text[i] == '!') or (text[i] == '?')):
        sentences = sentences + 1

    if (text[i].isalpha()):
        letters = letters + 1

# L is the average number of letters per 100 words in the text
L = (letters / words) * 100

# S is the average number of sentences per 100 words in the text.
S = (sentences / words) * 100

# Calculate Coleman-Liau index
index = 0.0588 * L - 0.296 * S - 15.8

# Print Grade
if (index >= 16):
    print("Grade 16+")

elif (index < 1):
    print("Before Grade 1")

else:
    print(f"Grade {round(index)}")
