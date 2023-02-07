#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <chrono>

class Vorratskammer {
    public:
    std::vector < std::string > dinge;
    std::vector < std::string > daten;
    std::vector < int > mengen;
    std::string ding;

    void einlesen(){
        
        std::ifstream file("Vorratskammer.txt");
        std::string line;

        while (std::getline(file, line)){
                std::stringstream linestream(line);
            std::string ding, datum, menge;
            getline(linestream, ding, '|');
            dinge.push_back(ding);
            getline(linestream, datum, '|');
            daten.push_back(datum);
            getline(linestream, menge, '|');
            mengen.push_back(std::stoi(menge));
        
        
    }

        
        file.close();
        
        for (size_t i = 0; i < mengen.size(); i++){

        std::cout << mengen[i] << std::endl;
    }
}
    void zeit()
    {
       auto start = std::chrono::system_clock::now();
    // Some computation here
    auto end = std::chrono::system_clock::now();
 
    std::chrono::duration<double> elapsed_seconds = end;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;

    }
    int hinzufügen()
    {
        
        int d, m ,y;
        unsigned int z;
        
        

                std::cout << "Bitte geben sie einen Gegenstand ein\n";
                std::cin >> ding;
                std::cout << "Bitte geben sie das Jahr des Ablaufdatums ein\n";
                std::cin >> y;
                std::cout << "Bitte geben sie den Monat des Ablaufdatums ein\n";
                std::cin >> m;
                std::cout << "Bite geben sie den Tag des Ablaufdatums ein\n";
                std::cin >> d;
                std::cout << "Bitte geben sie die Menge des Gegenstands an\n";
                std::cin >> z;

                    std::ofstream out;
                    out.open("Vorratskammer.txt", std::ofstream::app);
                    out << ding << "|" << d << "/" << m << "/" << y <<  "|" << z << "\n"; 
                    out.close(); 
                    

        return 0;
    
    }
            
    int entfernen()
    {
        
            return 0;
    }

    int anzeigen()
    {
        std::string ding;
                std::cout << "Bitte geben sie einen Gegenstand ein\n" << std::endl;
                std::cin >> ding;

                    std::ifstream in("Vorratskammer.txt");
                    std::string zeile;

        while(getline(in, zeile))
            {
                if (zeile.find(ding, 0) == 0)
                {
                    std::cout << zeile << "\n";


                }

            }
        
    return 0; 
    }


    int bearbeiten(std::string anzahl, std::string name){

        
        


    return 0;
    }
};

// int menu() {
   
//    int choice;

//         std::cout << "Willkommen bei ihrer Vorratskammer\n\n";
//     do
//     {
//         std::cout << "0. Verlassen\n1.Gegenstand hinzufügen\n2.Dinge verbrauchen oder entfernen\n3.Gegenstand entfernen\n4.Lassen sie sich alle gespeicherten gegenstände anzeigen\n";
//         std::cin >> choice;


//         switch(choice)
//     {
//         case 0:
//             std::cout << "Auf wiedersehen\n";
//             return 0;
//         case 1:            
//           vk.hinzufügen();
//            break;
//         case 2:
//           vk.verbrauchen();
//             break;
//         case 3:
//           vk.entfernen();
//             break;
//         case 4:
//            vk.anzeigen();
//             break;
//     }
// }
//      while (choice != 0);

//      return 0;
// }  
 
int main(){
Vorratskammer vk;
   vk.zeit();
   
}
   
