#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
class Player {
    public:
    char const* name ;
    int position;
    Player(char const* name1,int position1){
        name = name1;
        position = position1;
    }
};

class Game {
    public :
    int board_size;
    Game() {
        board_size=100;
    }
    bool check_valid_move (int str) {
        if (str<=100 ) {return true;}
        else {return false;}

    }
    int roll_dice() {
        int turn = rand()%6 + 1;
        int turn2 = turn+rand()%6 +1;
        int turn3 = turn2 + rand()%6 + 1;
        if (turn !=6){return (turn);}
        else if ( turn2 != 12){ return turn2;
        }
        else if(turn3 != 18){return turn3;} 
        else return 0;
        //if u get 6 then u get to roll dice again and if again you got 6 then one last time you get to roll dice but this time if u get 6 it counts total to 0 XD

    }
    void snake_ladders (int &num){
     if (num == 5){ num = 83;}
     else if (num == 6) {num = 34;}
     else if (num == 21) {num = 42;}
     else if (num == 28) {num = 10;}
     else if (num == 43) {num = 16;}
     else if (num == 50) {num = 10;}
     else if (num == 53) {num = 72;}
     else if (num == 61) {num = 81;}
     else if (num == 79) {num = 3;}
     else if (num == 84) {num = 56;}
     else if (num == 88) {num = 92;}
     else if (num == 89) {num = 68;}
     else if (num == 93) {num = 71;}
     else if (num == 98) {num = 7;}
    }
    bool win (int score){
        if (score==100){return true ;}
        else {return false;}
    }
    void next_move (Player &p1){
        int score1 = p1.position + roll_dice();
            snake_ladders(score1);
            if (check_valid_move(score1)) {p1.position=score1;}
            cout<<p1.name<<"'s new position is "<< score1 << endl;
    }

};
    int main (){
        Player p1("james",0);
        Player p2("harry",0);
        Game new_game ;
        while (!new_game.win(p1.position) || !new_game.win(p2.position)) {
          
                new_game.next_move(p1);
                if (new_game.win(p1.position)){
                cout<< p1.name<<" won";
                break;
                }
                new_game.next_move(p2);
                if (new_game.win(p2.position)) {
                cout<< p2.name<<" won";
                break;
                }


        }  
     
        
return 0;
}