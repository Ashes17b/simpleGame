/** Game - find Red color. Default: {"Red", "Green", "Blue"} -> 
 *  Red: position 1.
 *  Green: position 2.
 *  Blue: position 3.
 *  Default you have 100$.
 */
#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::swap;

class Game {
private:
    long long cash;
    char data[3]; // Red, Green, Blue

    //Blocked copy
    Game(Game&) {}
    void operator=(const Game&) {}
public:
    Game() {
        cash = 100;
        data[0] = 'R'; 
        data[1] = 'G';
        data[2] = 'B';
    }
    ~Game() {}

    virtual long long getCash() { return cash; }
    virtual void printCash() { cout << "Your cash: " << cash << "$" << endl; }

    void shuffles(char *data) {
        srand(time(NULL));
        for (int i = 0; i < 5; i++) { 
            int x = rand() % 3;
            int y = rand() % 3;
            swap(data[x], data[y]);
        }
    }

    virtual void play(int bet) {
        cout << "Shuffling colors..." << endl;
        shuffles(data);

        cout << "What's the position of Red color?" << endl;
        int playerVariant = 0;
        cin >> playerVariant;
        if (data[playerVariant - 1] == 'R') {
            cout << "You Win! Congratuletions!" << endl;
            cash += bet * 3;
        }
        else if (playerVariant > 3) {
            cout << "Please, read the rules carefully." << endl;
            cash -= bet;
        }
        else 
            cash -= bet;
        
        if (cash < 0) { 
            cout << "You Lose. Sorry." << endl;
            exit(0);
        }
        printCash();
    }
};

int main() {
    Game game;

    game.printCash();
    int bet = 0;
    cout << "Your bet?" << endl;
    cin >> bet;
    if (bet <= game.getCash())
        game.play(bet);
    else
        cout << "Your bet is greater cash." << endl;
    
    std::string temp = "Yes";
    while (temp == "Yes") {
        cout << "You want try again?" << endl;
        cin >> temp;
        if (temp != "Yes" || game.getCash() <= 0) break;

        cout << "Your bet?" << endl;
        cin >> bet;
        if (bet <= game.getCash())
            game.play(bet);
        else 
            cout << "Your bet is greater cash." << endl;
    }

    return 0;
}