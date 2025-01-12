# sentences per 100 words, letters per 100 words, words
import cs50


def words(text):
    return len(text.split())


def sentences(text):
    x = text.count("!") + text.count("?") + text.count(".")
    return x


def letters(text):
    x = 0
    for i in text:
        if i.isalpha():
            x += 1
    return x


def main():
    text = cs50.get_string("Text: ")
    S = float(100 * sentences(text) / words(text))
    L = float(100 * letters(text) / words(text))
    index = 0.0588 * L - 0.296 * S - 15.8
    rounded = round(index)


    if index < 1:
        print("Before Grade 1")

    elif index > 16:
        print("Grade 16+")

    else:
        print("Grade", rounded)
    return

main()
