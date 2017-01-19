"""
Write a method to decide if two strings are anagrams or not.
"""

def check(word1, word2):
    """
    checks if 2 words are anagrams
    :param word1:
    :param word2:
    :return:
    """
    bank = []

    for s in range(0, len(word1)):
        bank.append(word1[s])

