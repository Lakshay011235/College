import random 
def choose_word(): 
    words = ["apple", "banana", "orange", "grape", "strawberry", "pineapple"] 
    return random.choice(words) 

def display_word(word, guessed_letters): 
    displayed_word = "" 
    for letter in word: 
        if letter in guessed_letters: 
            displayed_word += letter 
        else: 
            displayed_word += "_ " 
    return displayed_word 

def hangman(): 
    word = choose_word() 
    guessed_letters = [] 
    attempts = 6 
    print("Welcome to Hangman!") 
    print("Guess the word:", display_word(word, guessed_letters)) 
    while True: 
        guess = input("Guess a letter: ").lower() 
        if guess in guessed_letters: 
            print("You've already guessed that letter!") 
        elif guess in word: 
            guessed_letters.append(guess) 
            print("Correct guess!") 
        else: 
            attempts -= 1 
            print("Wrong guess! You have", attempts, "attempts left.") 
        if attempts == 0: 
            print("Game over! The word was:", word) 
            break 
        print("Word:", display_word(word, guessed_letters)) 
        if "_ " not in display_word(word, guessed_letters): 
            print("Congratulations! You've guessed the word:", word) 
            break 
hangman() 
