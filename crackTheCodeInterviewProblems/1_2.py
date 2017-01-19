import string

"""
Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters,
including the null character.)
"""

def rev(word):
    dummy = ""
    for x in range (len(word), 0, -1):
        dummy = dummy + word[x-1]

    print(word + " reversed is " + dummy)

word = raw_input("enter word: ")
word = word.lower()
rev(word)