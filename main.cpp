#include <iostream>
#include <string>
#include <chrono>

int main() {
    std::string CharCount;
    bool NewInput = true;
    bool InputCorrect = false;
    std::string NewRound;

    while(NewInput) {
        unsigned int UserInput = 0;
        unsigned int x = 1;
        unsigned int WriteChar = 0;

        std::cout << "Bis wieviel soll gezählt werden?\nDeine Eingabe: ";
        std::cin >> UserInput;
        if(std::cin.fail()) {
            InputCorrect = false;
        }
        else {
            InputCorrect = true;
        }

        auto iTimestampStart = std::chrono::system_clock::now();

        while (x <= UserInput && InputCorrect)  {
            std::cout << "Ich bin bei " << x << std::endl;
            CharCount = std::to_string(x);
            WriteChar += CharCount.size();
            x++;
        }

        if(x >= UserInput && InputCorrect) {
            auto iTimestampStop = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = iTimestampStop - iTimestampStart;

            std::cout << "Es wurde bis " << UserInput << " gezählt.\nDabei wurden " << WriteChar << " Ziffern geschrieben!" << std::endl;
            std::cout << "Der Vorgang hat insgesamt: " << elapsed_seconds.count() << " Sekunden benötigt!" << std::endl;
            std::cout << "Neue Eingabe? j/n:";
            std::cin >> NewRound;

            if (NewRound == "y" || NewRound == "j") {
                NewInput = true;
            } else {
                NewInput = false;
            }
        }
        else {
            std::cout << "Ungültige Eingabe. Beende das Programm" << std::endl;
            return(EXIT_SUCCESS);
        }
    }
    return 0;
}
