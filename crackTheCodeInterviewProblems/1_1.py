import string

"""
Implement an algorithm to determine if a string has all unique characters.
What if you can not use additional data structures?
"""

def check(word):
    unique = True
    lastLetter = []
    word = word.lower()

    for s in range(0, len(word)):
        if word[s] in lastLetter:
            unique = False

        lastLetter.append(word[s])

    if unique == False:
        print(word + " is not made of unique characters")
    else:
        print(word + " is made of only unique characters")


temp = raw_input("enter word: ")
#print(temp)
check(temp)
