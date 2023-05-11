#!/usr/bin/python3
for ch in range(97, 123):
    if chr(ch) is not 'q' and chr(ch) is not 'e':
        print("{}".format(chr(ch)), end="")
