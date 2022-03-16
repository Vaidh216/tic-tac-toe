#     Tic tae toe game in python

# This is the self made making of tic tae toe game by ghurrahu singh
from os import system

def takeinput(board,player):
    val='0'
    if player==1:
        val='0'
    else:
        val='*'

    while 1:
        print("Enter the position for the value for player ",player," : ")
        ch=int(input())
        ch=ch-1
        if(board[ch]!='-'):
            print("Initially there is a value enter again :")
        elif (ch>8 | ch<0):
            print("Wrong entered! Enter Again ")
        else:
            break

    board[ch]=val;

def print_the_board(board):
    system('cls')
    print()
    print()
    print(board[0]," ",board[1]," ",board[2])
    print(board[3]," ",board[4]," ",board[5])
    print(board[6]," ",board[7]," ",board[8])

#
#       Checking if someone won
#
#       Checking the columns
def check_col(board):
    ch='*'
    for i in range(3):
        if (board[i]==ch):
            if(board[i+3]==ch):
                if(board[i+6]==ch):
                    return 1
    ch='0'
    for i in range (3):
        if (board[i]==ch):
            if(board[i+3]==ch):
                if(board[i+6]==ch):
                    return 1
    return 0

#       Checking rows
def check_row(board):
    ch='*'
    for i in range(0,6,3):
        if (board[i]==ch):
            if(board[i+1]==ch):
                if(board[i+2]==ch):
                    return 1
    ch='0'
    for i in range(0,6,3):
        if (board[i]==ch):
            if(board[i+1]==ch):
                if(board[i+2]==ch):
                    return 1
    return 0

#       Checking the diagonals
def check_dia(board):
    ch='*'
    if(board[0]==ch):
        if(board[4]==ch):
            if(board[8]==ch):
                return 1
    if(board[2]==ch):
        if(board[4]==ch):
            if(board[6]==ch):
                return 1
    ch='0'
    if(board[0]==ch):
        if(board[4]==ch):
            if(board[8]==ch):
                return 1
    if(board[2]==ch):
        if(board[4]==ch):
            if(board[6]==ch):
                return 1


#   Cheking if anyone won or not
def check_if_won(board):
    col=0
    row=0
    dia=0
    col=check_col(board)
    row=check_row(board)
    dia=check_dia(board)
    if (col==1):
        print("Game Won")
        return 1
    elif(row==1):
        print("Game won")
        return 1
    elif(dia==1):
        print("Game won")

        return 1
    else:
        return 0


#   Checking if the game tied or not
def iftied(board):
    global countnumberofmoves
    countnumberofmoves=countnumberofmoves+1
    if countnumberofmoves==9:
        print("The game is Tied")
        return 1

    else:
        return 0

# Default play the game logic
def playthegame(board):
    player=1
    while 1:
        takeinput(board,player)

        print_the_board(board)

        
        won=check_if_won(board)

        
        check=iftied(board)
        if check==1:
            break
        if won==1:
            print("The game is won")
            break
        if player==1:
            player=2
        else:
            player=1


board = ['-','-','-',
         '-','-','-',
         '-','-','-']

print_the_board(board)

countnumberofmoves=0

res=playthegame(board)
if res==1:
    print("Funtion returned to main function : ")

print("The game over")