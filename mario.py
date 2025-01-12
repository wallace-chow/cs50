import cs50


while True:
    h = cs50.get_int("Height: ")
    if h > 8:
        print("Height Must Be No Greater Than 8")
    elif h <= 0:
        print("Height Must Be A Positive Integer")
    else:
        break

for x in range(h):
    print(" " * (h - x - 1), end="")
    print("#" * (x + 1), end="")
    print("  ", end="")
    print("#" * (x + 1))
