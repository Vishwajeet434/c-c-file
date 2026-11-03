//BASIC TIC TAC TOE PLAYING BETWEEN PLAYER A AND PLAYER B

#include <iostream>                                  //Used for input and output.
#include <cstdlib>                                  //Used for random number generation.
#include <ctime>                                    //Used to get the current time

using namespace std;                      //It allows us to write cout, cin, and string without writing std:: before them.

char board[3][3] = {                     //Creating the game board
    {'1','2','3',},
    {'4','5','6',},
    {'7','8','9'}
};
void displayBoard()

 {
    cout<<"\n";                       // next line
    for(int i=0; i<3; i++)
    {
        cout<<"["<<board[i][0]<<"|"                //This displays all three columns of the current row
            <<"" <<board[i][1]<<"|"
            << ""<<board[i][2]<<"]"<<"]"<<endl;
        if(i<2)
            cout<<"-*-*-*-"<<endl;
        
    }
    
 }
bool winner( char player)
  {
  for(int i= 0; i<3 ;i++)
  {
   if(board[i][0]== player &&                   //Check horizontal rows
      board[i][1]== player &&
      board[i][2]== player)
       return true;

    if(board[0][i]== player &&
      board[1][i]== player &&                // check vertical
      board[2][i]== player)
       return true;  
    }
    if(board[0][0]== player &&
      board[1][1]== player &&                 //check diagonal
      board[2][2]== player)
       return true;

     if(board[0][2]== player &&                 // check diagonal
      board[1][1]== player &&
      board[2][0]== player)
       return true;  

     return false;  
  }
 bool Draw()
 {
    for(int i=0; i<3; i++){
        for(int j=0; j<3;j++)
        {
        if(board[i][j] != 'X' &&
           board[i][j] != 'O')
             return false;
    }
 } 
return true;
}
void playerAmove()
{
    int position;
    while(true)
    {
        cout<<"Enter the number (1-9):" ;
        cin>>position;
        if(position<1 || position>9)
        {
            cout<<"Invalid the Input Number . Enter the Input Number again";
            continue;
        }
        int row = (position-1)/3;                                       //Convert position into row and column
        int col= (position-1)%3;
        
        if(board[row][col]=='X' ||                                     //Check whether the position is occupied
           board[row][col]=='O'){
            cout<<"Positon is already occupied\n";
           }
        else
        {
            board[row][col] ='X';
            break;
        }

    }
}
void PlayerBmove()
{
    int position, row, col;
  cout<<"Enter the number (1-9):" ;
  cin>>position;
  
  if(position<1 || position>9)
     {
            cout<<"Invalid the Input Number . Enter the Input Number again";
            
        }
do
{
                                 //Generate a random position
    row = (position-1)/3;
    col=(position-1)%3;                                           
} while (board[row][col] == 'X' ||                             //Check whether the position is occupied
             board[row][col] == 'O');

    board[row][col] = 'O';

    cout << "PlayerB selected position: "
         << position << endl;
}
int main()
{
    srand(time(0));                                            //Random number initialization
    cout<<"<<-----TIC TOC TOE------->>>";                      //Display the welcome message
    cout<<"PlayerA<<--'X'| PlayerB<<--0";

    displayBoard();                                          //Calls the displayBoard() function.

    while(true)
    {
        playerAmove();                                      //Human plays first
        displayBoard();
        if(winner('X'))
        {
            cout<<"congratulation You win!";
            break;
        }
        if(Draw())
        {
            cout<<"Draw the game!";
            break;
        }
        PlayerBmove();                                   //Computer plays
        displayBoard();                                   //The computer selects a random available position and places O.
        if(winner('O'))
        {
            cout<<"PlayerB Win!\n";
            cout<<"You loss!";
            break;

        }
        if(Draw())
        {
            cout<<"Game the draw and play again";
            break;
        }
        }
    return 0;
}


    

