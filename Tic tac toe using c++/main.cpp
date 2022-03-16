
//              Tic tae toe game

// This is the self made making of tic tae toe game by Ghurrahu singh

// Headers

#include<bits/stdc++.h>
using namespace std;

//                                         Taking the input from the user

void takeinput(string board[3],int player){
    int ch;
    char val;
    if(player==1)
        val='0';
    else
        val='*';
    while(true){
    cout<<"Enter the position for the value for player "<<player<<" : ";
    cin>>ch;
    ch--;
    if(board[ch/3][ch%3]!='-'){
        cout<<"Initially There is a value Enter Again : "<<endl<<endl;
    }
    else if(ch>8 || ch<0)
        cout<<"Wrong entered! Enter Again "<<endl<<endl;
    else
        break;
    }
    if(ch<3)
        board[0][ch]=val;
    else if(ch<6)
        board[1][ch-=3]=val;
    else
        board[2][ch-=6]=val;

}

//                                                 Printing the board

void print_the_board(string board[3]){
    for(int i=0;i<3;i++)
        cout<<board[i][0]<<" | "<<board[i][1]<<" | "<<board[i][2]<<endl;
}




//                                                  Checking block for the winners
//
//checking if someone is won
//

//checking the colums
bool check_col(string board[3]){
    char ch='*';
    for(int i=0;i<3;i++){
        if(board[0][i]==ch && board[1][i]==ch && board[2][i]==ch)
            return true;
    }
    ch='0';
    for(int i=0;i<3;i++){
        if(board[0][i]==ch && board[1][i]==ch && board[2][i]==ch)
            return true;
    }
    return false;
}

//Checking the rows
bool check_row(string board[3]){
    char ch='*';
    for(int i=0;i<3;i++){
        if(board[i][0]==ch && board[i][1]==ch && board[i][2]==ch)
            return true;
    }
    ch='0';
    for(int i=0;i<3;i++){
        if(board[i][0]==ch && board[i][1]==ch && board[i][2]==ch)
            return true;
    }
    return false;

}

//Checking the diagonals
bool check_dia(string board[3]){
    char ch='*';
    if(board[0][0]==ch && board[1][1]==ch && board[2][2]==ch)
        return true;
    if(board[0][2]==ch && board[1][1]==ch && board[2][0]==ch)
        return true;

    ch='0';
    if(board[0][0]==ch && board[1][1]==ch && board[2][2]==ch)
        return true;
    if(board[0][2]==ch && board[1][1]==ch && board[2][0]==ch)
        return true;
    return false;
}

//Check function
bool check_if_won(string board[3]){
    bool col,row,dia;
    col=false;
    row=false;
    dia=false;
    col=check_col(board);
    row=check_row(board);
    dia=check_dia(board);
    if(row==true || col==true || dia==true){
        cout<<"Game won : "<<endl;
        return true;
    }
    return false;
}

//                              If Tied block
bool iftied(string board[3]){
    static int number_of_times=0;
    number_of_times++;
    if(number_of_times==10)
        return true;
    else
        return false;
}

//                              Play the game block


int playthegame(string board[3]){
    int player=1;
    // While game going means or nobody won
    while(true){
        //Taking the input
        takeinput(board,player);

        //printing the board
        print_the_board(board);

        //Checking is anyone won
        bool won;
        won=check_if_won(board);

        //Checking if tied
        bool check;
        check=iftied(board);
        if(check==true)
            break;
        if(won==true)
            break;
        if(player==1)
            player=2;
        else
            player=1;

    }
    cout<<"Game end "<<endl;
    cout<<"Function play the game ends : "<<endl;
    return 1;
}

//                                               Main Function
int main(){
    string board[3];
    cout<<"Welcome to the Ghurrahu singh Gaming : "<<endl<<endl;

    //string initialization
    for(int i=0;i<3;i++)
        board[i]="---";

    //Printing the board
    print_the_board(board);

    //Playing the game
    int res;
    res=playthegame(board);
    if(res==1)
        cout<<"Function returned to main function : "<<endl;
    cout<<"End of the main function";

    return 0;
}
