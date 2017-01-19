import string

"""
Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method
"""

def remDupes(word):
    """
    removes duplicate characters from a string
    :return:
    """
    dummy = ""
    for s in range(0,len(word)):
        if word[s] not in dummy:
            dummy += word[s]

    print(word + " without repeating characters is " + dummy)

word = raw_input("enter word: ")
word = word.lower()
remDupes(word)
