#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Game{
    static int highscore[10];
    static string highscorers[10];
    string username;
    int score;
public:
    Game(){}
    Game(string n="player1"):username(n),score(0){}
    void displayHighscore(){
        for(int i=0;i<10;i++){
            cout<<"Name: "<<highscorers[i]<<"  Score: "<<highscore[i]<<endl;
        }
    }
    void play(){ int index;
         score = rand() % 100 + 1;
         for(int i=0;i<10;i++){
            if(highscore[i]<score){index=i;break;}
         }
         for(int i=9;i>=index;i--){
            highscore[i]=highscore[i-1];
            highscorers[i]=highscorers[i-1];
         }// Insert new score
                highscore[index] = score;
                highscorers[index] = username;
    }
};int Game::highscore[10]={0};
string Game::highscorers[10]={""};
int main(){
   Game p1("abeeha");
   Game p2("XYZ");
   Game p3("bakhtawar");
   p1.play();
   p2.play();
   p3.play();
   p3.displayHighscore();
//    Game p1("abeeha");
//    Game p1("abeeha");
}