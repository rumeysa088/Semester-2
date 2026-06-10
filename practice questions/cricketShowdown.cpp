// #include<iostream>
// #include<string>
// using namespace std;
// class Player{
// public:
//  int ballScores[12];
//     string playerName;
//     int totalScore;
//     Player(){}
    
// };
// class Game{
// public:
//       void playGame(Player& p){
//         cout<<"Enter 12 balls scores!"<<endl;
//            for(int i=0;i<12;i++){
//                cout<<"Ball "<<i+1;
//                cin>>p.ballScores[i];
//            }
//       }
//       void validateScore(Player& p){
//          for(int i=0;i<12;i++){
//             if(p.ballScores[i]<0 ||p.ballScores[i]>6 ){ p.ballScores[i]=0;}
//          }
//       }
//       void findWinner(Player& player1, Player& player2){
//             if(player1.totalScore>player2.totalScore){cout<<"PLayer 1 is the winner!"<<endl;}
//             else if(player2.totalScore>player1.totalScore)cout<<"PLayer 2 is the winner!"<<endl;
//             else{cout<<"match DRAWN!"<<endl;}
//       }
//       void displayMatchScoreboard(Player& p1, Player& p2){
//          for(int j=0;j<12;j++){
//             for(int i=0;i<12-1;i++){
//                 if(p1.ballScores[i]>p1.ballScores[i+1])swap(p1.ballScores[i],p1.ballScores[i+1]);
//                 if(p2.ballScores[i]>p2.ballScores[i+1])swap(p2.ballScores[i],p2.ballScores[i+1]);
//             }
//          }
//          cout<<"PLAYER : "<<p2.playerName<<endl;
//          for(int i=0;i<12;i++){
//             cout<<"ball "<<i+1<<" "<<p1.ballScores[i]<<endl;
//          }
//          cout<<"Total : "<<p1.totalScore<<endl;
//          cout<<"PLAYER : "<<p2.playerName<<endl;
//          for(int i=0;i<12;i++){
//             cout<<"ball "<<i+1<<" "<<p2.ballScores[i]<<endl;
//          }cout<<"Total : "<<p2.totalScore<<endl;
//       }
// };
// int main(){

// }
class Game {
public:

    void playGame(Player& p) {

        cout << "\n" << p.playerName
             << ", enter scores for 12 balls (0–6):\n";

        for (int i = 0; i < 12; i++) {

            int score;
            cout << "Ball " << i + 1 << ": ";
            cin >> score;

            // Validate immediately
            if (score < 0 || score > 6)
                score = 0;

            p.ballScores[i] = score;
            p.totalScore += score;
        }
    }

    void findWinner(Player& p1, Player& p2) {

        if (p1.totalScore > p2.totalScore)
            cout << "\nWinner: " << p1.playerName << endl;
        else if (p2.totalScore > p1.totalScore)
            cout << "\nWinner: " << p2.playerName << endl;
        else
            cout << "\nMatch Drawn!\n";
    }

    void displayMatchScoreboard(Player& p1, Player& p2) {

        // Sort copies (ascending)
        int s1[12], s2[12];

        for (int i = 0; i < 12; i++) {
            s1[i] = p1.ballScores[i];
            s2[i] = p2.ballScores[i];
        }

        // Bubble sort
        for (int j = 0; j < 12; j++) {
            for (int i = 0; i < 11; i++) {
                if (s1[i] > s1[i + 1]) swap(s1[i], s1[i + 1]);
                if (s2[i] > s2[i + 1]) swap(s2[i], s2[i + 1]);
            }
        }

        // Display Player 1
        cout << "\n=== Scoreboard ===\n";
        cout << "\nPLAYER: " << p1.playerName << endl;

        for (int i = 0; i < 12; i++)
            cout << "Ball " << i + 1 << ": " << s1[i] << endl;

        cout << "Total: " << p1.totalScore << endl;

        // Display Player 2
        cout << "\nPLAYER: " << p2.playerName << endl;

        for (int i = 0; i < 12; i++)
            cout << "Ball " << i + 1 << ": " << s2[i] << endl;

        cout << "Total: " << p2.totalScore << endl;
    }
};
class Game {
public:

    void playGame(Player& p) {

        cout << "\n" << p.playerName
             << ", enter scores for 12 balls (0–6):\n";

        for (int i = 0; i < 12; i++) {

            int score;
            cout << "Ball " << i + 1 << ": ";
            cin >> score;

            // Validate immediately
            if (score < 0 || score > 6)
                score = 0;

            p.ballScores[i] = score;
            p.totalScore += score;
        }
    }

    void findWinner(Player& p1, Player& p2) {

        if (p1.totalScore > p2.totalScore)
            cout << "\nWinner: " << p1.playerName << endl;
        else if (p2.totalScore > p1.totalScore)
            cout << "\nWinner: " << p2.playerName << endl;
        else
            cout << "\nMatch Drawn!\n";
    }

    void displayMatchScoreboard(Player& p1, Player& p2) {

        // Sort copies (ascending)
        int s1[12], s2[12];

        for (int i = 0; i < 12; i++) {
            s1[i] = p1.ballScores[i];
            s2[i] = p2.ballScores[i];
        }

        // Bubble sort
        for (int j = 0; j < 12; j++) {
            for (int i = 0; i < 11; i++) {
                if (s1[i] > s1[i + 1]) swap(s1[i], s1[i + 1]);
                if (s2[i] > s2[i + 1]) swap(s2[i], s2[i + 1]);
            }
        }

        // Display Player 1
        cout << "\n=== Scoreboard ===\n";
        cout << "\nPLAYER: " << p1.playerName << endl;

        for (int i = 0; i < 12; i++)
            cout << "Ball " << i + 1 << ": " << s1[i] << endl;

        cout << "Total: " << p1.totalScore << endl;

        // Display Player 2
        cout << "\nPLAYER: " << p2.playerName << endl;

        for (int i = 0; i < 12; i++)
            cout << "Ball " << i + 1 << ": " << s2[i] << endl;

        cout << "Total: " << p2.totalScore << endl;
    }
};