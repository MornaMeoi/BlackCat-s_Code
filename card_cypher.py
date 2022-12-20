#4kyu task: https://www.codewars.com/kata/59b9a92a6236547247000110/
from math import factorial

class PlayingCards:
    # Takes a String containing a message, and returns an array of Strings representing
    # a deck of playing cards ordered to hide the message, or None if the message is invalid.
    def encode(self, message):
        if len(message) < 49: #checking for maximal message length
            #calculating permutation number
            num = 0
            for i in range(1, len(message) + 1):
                num += self.cypher.get(message[-i]) * (27 ** (i - 1))
            
            if num < factorial(52): #checking for maximal permutation number
                #looking for {num} deck permutation
                result = []
                temp = self.initial_deck.copy()
                while len(temp) != 1:
                    a = (num // factorial(len(temp) - 1)) % len(temp)
                    result.append(temp[a])
                    temp = temp[:a] + temp[a + 1:]
                return result + temp
        return None

    # Takes an array of Strings representing a deck of playing cards, and returns
    # the message that is hidden inside, or None if the deck is invalid.
    def decode(self, deck):
        #printDeck(deck, True) preloaded function from task
        if len(deck) == 52:#checking unpropriate deck
            reversed_cypher = {i: j for j, i in self.cypher.items()}#getting reversed cypher dict
            #calculation of {num} deck permutation
            num = 0
            in_d = self.initial_deck.copy()
            for i in deck:
                a = in_d.index(i)
                num += a * factorial(len(in_d) - 1)
                in_d = in_d[:a] + in_d[a + 1:]
            #looking for message from found deck permutation
            result = ''
            while num != 0:
                result = reversed_cypher.get(num % 27) + result
                num //= 27
            return result
        return None
    
    initial_deck = [
        "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC",
        "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "TD", "JD", "QD", "KD",
        "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "JH", "QH", "KH",
        "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS", "QS", "KS"
    ]
    
    cypher = {
        ' ': 0, 'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7, 'H': 8, 'I': 9,
        'J': 10, 'K': 11, 'L': 12, 'M': 13, 'N': 14, 'O': 15, 'P': 16, 'Q': 17, 'R': 18,
        'S': 19, 'T': 20, 'U': 21, 'V': 22, 'W': 23, 'X': 24, 'Y': 25, 'Z': 26
    }
