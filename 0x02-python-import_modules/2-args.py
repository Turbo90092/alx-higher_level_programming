#!/usr/bin/python3
if __name__ == "__main__":
    import sys
    j = len(sys.argv) - 1

    if j == 0:
        print("{} arguments.".format(j))
    elif j == 1:
        print("{} argument:".format(j))
    else:
        print("{} arguments:".format(j))

    if j >= 1:
        j = 0
        for arg in sys.argv:
            if j != 0:
                print("{}: {}".format(j, arg))
            j += 1
