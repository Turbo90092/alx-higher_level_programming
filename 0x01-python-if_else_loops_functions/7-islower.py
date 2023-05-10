#!/usr/bin/python3

def islower(c):
    if ord(c) >= 97 and ord(c) <= 122:
        return True
    else:
        return False
if __name__ == "__main__":
    c = input("Enter a character: ")
    if islower(c):
        print("The character {} is lowercase.".format(c))
    else:
        print("The character {} is not lowercase.".format(c))
