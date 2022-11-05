import random

# Generate a 3 Digit number
def numGenerator():
    digits = list(range(10))
    random.shuffle(digits)
    return digits[:3]

# Game Rules
print("""
The Computer will give you clues, the possible clues are:

    CLOSE : You've Guessed a correct number but in the wrong position
    MATCH: You've Guessed a correct number in the Correct Position
    NOPE: You've haven't guessed any of the numbers correctly 

""")

guess=[]

special = numGenerator()
# print(special);
while (True):
    guess = list(map(int, input("\nWhat is your Guess ? " ).strip().split()))

    if(guess[0] not in special and guess[1] not in special and guess[2] not in special ):
        print("---NOPE---")
    else:
        # Match : Correct Number And Correct Position
        if( guess == special):
            print(">>> MATCH <<<")
            break;
        # Close : Correct Number but Wrong Position
        else:
            print("... CLOSE ...")
        
    
    


