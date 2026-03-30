#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Game {
public:
    int player;
    int computer;

    void play() {
        cout << "Doan mot so tu 0 den 9:\n";

        while (true) {
            cout << "Nhap so cua ban: ";
            cin >> player;

            if (player < 0 || player > 9) {
                cout << "Vui long nhap so tu 0 den 9.\n";
                continue;
            }

            computer = rand() % 10;
            cout << "Computer: " << computer << endl;

            if (computer == player) {
                cout << "Ban doan dung!\n";
                break;
            } else {
                cout << "Doan sai, tiep tuc.\n";
            }
        }
    }
};

int main() {
    srand(time(0));
    Game p;
    p.play();
    return 0;
}