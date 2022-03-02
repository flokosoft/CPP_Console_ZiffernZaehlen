#include <iostream>
#include <string>
#include <chrono>
using namespace std;

int main() {
    string CharCount;
    bool NewInput = true;
    bool InputCorrect = false;
    string NewRound;

    while(NewInput) {
        unsigned int UserInput = 0;
        unsigned int x = 1;
        unsigned int WriteChar = 0;

        cout << "Bis wieviel soll gezählt werden?\nDeine Eingabe: ";
        cin >> UserInput;
        if(cin.fail()) {
            InputCorrect = false;
        }
        else {
            InputCorrect = true;
        }

        auto iTimestampStart = chrono::system_clock::now();

        while (x <= UserInput && InputCorrect)  {
            cout << "Ich bin bei " << x << endl;
            CharCount = to_string(x);
            WriteChar += CharCount.size();
            x++;
        }

        if(x >= UserInput && InputCorrect) {
            auto iTimestampStop = chrono::system_clock::now();
            chrono::duration<double> elapsed_seconds = iTimestampStop - iTimestampStart;

            cout << "Es wurde bis " << UserInput << " gezählt.\nDabei wurden " << WriteChar << " Ziffern geschrieben!" << endl;
            cout << "Der Vorgang hat insgesamt: " << elapsed_seconds.count() << " Sekunden benötigt!" << endl;
            cout << "Neue Eingabe? j/n:";
            cin >> NewRound;

            if (NewRound == "y" || NewRound == "j") {
                NewInput = true;
            } else {
                NewInput = false;
            }
        }
        else {
            cout << "Ungültige Eingabe. Beende das Programm" << endl;
            return(EXIT_SUCCESS);
        }
    }
    return 0;
}
