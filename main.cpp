#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

int main() {
    int x = 1;
    std::string CharCount;
    unsigned int WriteChar = 0;
    bool NewInput = true;
    bool InputCorrect = false;
    std::string NewRound;

    while(NewInput) {
        int UserInput;
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
            std::time_t end_time = std::chrono::system_clock::to_time_t(iTimestampStop);

            std::cout << "Es wurde bis " << UserInput << " gezählt.\nDabei wurden " << WriteChar
                      << " Ziffern geschrieben!" << std::endl;
            std::cout << "Der Vorgang hat insgesamt: " << elapsed_seconds.count() << " Sekunden benötigt!" << std::endl;
            std::cout << "Neue Eingabe? y/n:";
            std::cin >> NewRound;
            if (NewRound == "y") {
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
