#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>


class Vorratskammer {
    public:
    std::vector < std::string > dinge;
    std::vector < std::string > abldaten;
    std::vector < int >         mengen;
    std::vector<std::tm>        dates;
    std::vector < std::time_t > uhrzeit;
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
            abldaten.push_back(datum);
            getline(linestream, menge, '|');
            mengen.push_back(std::stoi(menge));
        
        
    }

        
        file.close();

        
        

      

       
    
}
    void zeit()
    {
        
    for (const auto& date_string : abldaten) {
    std::istringstream ss(date_string);
    int year, day, month;
    ss >> year >> day >> month;

    std::tm date = {0};
    date.tm_year = year - 1900;  // tm_year is years since 1900
    date.tm_mon = month - 1;     // tm_mon is 0-based
    date.tm_mday = day;
    
    dates.push_back(date);
  }

  std::cout << "The dates are:\n";
  for (const auto& date : dates) {
    std::cout << std::asctime(&date) << '\n';
  }

    }

    int hinzufügen()
    {
        
        int d, m ,y;
        unsigned int z;
        
        

                std::cout << "Bitte geben sie einen Gegenstand ein\n";
                std::cin >> ding;
                std::cout << "Bitte geben sie das Ablaufdatum ein (Format YYYY MM DD)\n";
                std::cin >> y >> m >> d;             
                std::cout << "Bitte geben sie die Menge des Gegenstands an\n";
                std::cin >> z;
                    

                std::ofstream out;
                    out.open("Vorratskammer.txt", std::ofstream::app);
                    out << ding << "|" << y << " " << d << " " << m <<  "|" << z << "\n"; 
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
    vk.anzeigen();
    
   
}
   
