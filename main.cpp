#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

int main() {
    int x = 1;
    int iEingabe = 1;
    char EnterEingabe;
    std::string Puffer;
    unsigned int iGeschriebeneZiffern = 0;
    int iProcess = 1;
    std::string strNeueEingabe;

    while(iProcess == 1) {

        std::cout << "Bis wieviel soll gez\204hlt werden?\nDeine Eingabe: ";
        std::cin >> iEingabe;
        std::cout << "Danke für die Eingabe. Ich z\204hle bis" << iEingabe << std::endl;
        auto iTimestampStart = std::chrono::system_clock::now();

        while (x <= iEingabe) {
            std::cout << "Ich bin bei " << x << std::endl;
            Puffer = std::to_string(x);
            iGeschriebeneZiffern += Puffer.size();
            x++;
        }

        auto iTimestampStop = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = iTimestampStop - iTimestampStart;
        std::time_t end_time = std::chrono::system_clock::to_time_t(iTimestampStop);

        std::cout << "Es wurde bis " << iEingabe << " gez\204hlt.\nDabei wurden " << iGeschriebeneZiffern
                  << " Ziffern geschrieben!" << std::endl;
        std::cout << "Der Vorgang hat insgesamt: " << elapsed_seconds.count() << " Sekunden ben\224tigt!" << std::endl;
        std::cout << "Neue Eingabe? y/n:";
        std::cin >> strNeueEingabe;
        if(strNeueEingabe == "y")
        {
            iProcess = 1;
        }
        else {
            iProcess = 0;
        }
    }
    return 0;
}
