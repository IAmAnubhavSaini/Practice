//This plays a game of rock, paper scissors. It creates a pseudo random order by asking the user to enter 20 random numbers.
#include "std_lib_facilities.h"

void Instructions(void);
void MoveInstructions (void);
string determineMove (int Input);
char determineWinner(string computer, string player);
void closingWords (int win, int loss, int tie);


main()
{
      int Win = 0, Loss = 0, Tie = 0, type, temp, i = 0;
      
      string pmove = " ";
      vector<int> moves;
      char pinput[20];
      Instructions();
      while (cin>>pmove && pmove!= "|")
      {
            temp = atoi(pmove.c_str());
            moves.push_back(temp%3);
      }
      for (i=0; i<moves.size(); ++i)
      {
          MoveInstructions();
          scanf("%s", pinput);
          pmove = pinput;
          if (pmove== "end") {break;}
          // works up until here.
          cout<<"You chose " <<pmove<<".\n The computer chose " <<determineMove(moves[i])<<".\n";
          
          if ( determineWinner(determineMove(moves[i]), pmove ) =='W')
          {
             cout<<"You won! Let's play again.\n\n";
             Win++;
          }
          else if (determineWinner ( determineMove(moves[i]), pmove )=='L')
          {
             cout<<"You lost. Let's play again.\n\n";
             Loss++;
          }
          else if (determineWinner ( determineMove(moves[i]), pmove )=='T')
          {
             cout<<"We tied. Let's play again.\n\n";
             Tie++;
          }
          else
          {
             cout<<"I'm sorry. There was an error in your input. Let's play again.\n";
          }
      }
      closingWords(Win, Loss, Tie);
      system ("pause");
      
      
}

void Instructions (void)
{
     cout << "I will play at least 5 games of rock paper scissors.\n First, enter at least 5 real numbers. Mark the end of the sequence with the '|' character. \n";
}

void MoveInstructions (void)
{
     cout << "Enter your move, by typing exactly 'rock', 'paper', or 'scissors'.\nEnter an 'end' to end the game. \n";
}

string determineMove (int Input)
{
     switch (Input){
     case 0:
          return "rock";
          break;
     case 1:
          return "paper";
          break;
     case 2:
          return "scissors";
          break;
     }
}

char determineWinner(string computer, string player)
{
     if (computer=="rock" && player=="rock") return 'T';
     if (computer=="paper" && player=="paper") return 'T';
     if (computer=="scissors" && player=="scissors") return 'T';
     
     if (computer=="rock" && player=="paper") return 'W';
     if (computer=="paper" && player=="scissors") return 'W';
     if (computer=="scissors" && player=="rock") return 'W';

     if (computer=="rock" && player=="scissors") return 'L';
     if (computer=="paper" && player=="rock") return 'L';
     if (computer=="scissors" && player=="paper") return 'L';
     else return 'E';

}

void closingWords (int win, int loss, int tie)
{
     cout<< "Thanks for playing " <<win+loss+tie<< " games with me!\n";
     cout<< "You won "<<win<<" times, lost "<<loss<<" times, and tied "<<tie<<" times.\nSee you later!\n";
}
