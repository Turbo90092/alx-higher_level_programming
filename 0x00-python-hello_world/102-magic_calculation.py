#!/usr/bin/python3

def magic_calculation(a, b):
    result = 1
    for i in range(b):
        try:
            if i > a:
                raise Exception('Too far')
            else:
                result += (a * i) + i
        except:
            result = b + a
            break
    return result
