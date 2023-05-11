#!/usr/bin/python3
for char_code in range(97, 123):
    if chr(char_code) not in 'eq':
        print(chr(char_code), end='')
