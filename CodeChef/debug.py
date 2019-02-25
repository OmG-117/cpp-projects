from random import randint

string = '''
0 1 2 1 0 1 2 3 2 1 0 1 2 3 3 2 1 0 1 2 3 4 5 6 7 8
'''

def printStrLens():
    line_chars = 0
    for char in string:
        if char == '-' or char == ' ':
            continue
        if char == '\n':
            print(line_chars)
            line_chars = 0
            continue
        line_chars += 1

def generateMagicSeq(len):
    buffer = '{0}'.format(len)
    next_num = randint(1, len/10)
    direction = -1
    for i in range(len):
        #if direction == 1 and len - i < next_num:
        #    for k in range(len - i):
        #        buffer += ' ' + str(next_num)
        #        next_num += direction
        #    break
        if next_num != 0 and direction == -1:
            buffer += ' ' + str(next_num)
            next_num -= 1
            continue
        elif next_num == 0 and direction == -1:
            buffer += ' ' + str(0)
            direction = 1
            next_num = 1
            continue
        else:
            buffer += ' ' + str(next_num)
            d100 = randint(1, 100)
            if d100 < 90:
                next_num += direction
                continue
            elif d100 >= 90 and d100 <= 95: #max rand
                direction = -1
            elif d100 > 95:
                direction = -1
                next_num += direction
    return buffer

def main():
    len = int(input())
    if len < 1:
        print(generateMagicSeq(len))
    else:
        with open('input.txt', 'a') as file:
            file.write(generateMagicSeq(len))
            file.write("\n\n")
        #print("Output generated in input.txt")
    #printStrLens()

main()
