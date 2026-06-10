#include<iostream>
using namespace std;
class Player{
    
    int ballScores[12];
   
    public:
    string playerName;
     int totalScore=0;
    void setter(int ballScores){
        this->ballScores=ballScores;
    }
};
class Game{
    public:
     void playGame(Player *p){
         for(int i=0;i<12;i++){
            cout<<"Enter score for ball no. "<<i<<endl;
            cin>>p->ballScores[i];
         }
     }
     void validateScore(Player *p){
        for(int i=0;i<12;i++){
            if(p->ballScores[i]<0 || p->ballScores[i]>6){p->ballScores[i]=0;}
        }
        for(int i=0;i<12;i++){
            p->totalScore+=p->ballScores[i];
        }
     }
     void findWinner(Player *p1,Player* p2){
        if(p1->totalScore>p2->totalScore){cout<<"Player 1 is the winner!"<<endl;}
        else if(p2->totalScore>p1->totalScore){cout<<"Player 2 is the winner!"<<endl;}
        else{cout<<"Game Drawn..";}
     }
};
int main(){

}