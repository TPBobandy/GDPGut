#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <cmath>


class Vorratskammer {
    public:
    std::vector < std::string > dinge;
    std::vector < std::string > abldaten;
    std::vector < int >         mengen;
    std::vector < std::tm >     dates;
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
    int i = 0;
    for (const auto& date_string : abldaten) {          
    std::istringstream ss(date_string);
    int year, day, month;
    ss >> year >> month >> day;

    std::tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    dates.push_back(date);

    }

    std::time_t now = std::time(nullptr);
    std::tm now_tm = *std::localtime(&now);
     
        for (std::tm date : dates) {
        
       
        
        std::time_t date_time = std::mktime(&date);
        double diff = std::difftime(date_time, now);
        int diff_days = std::floor(diff / (60 * 60 * 24));
        i++;

        if (diff_days < 7) {
        std::cout << dinge[i-1] << " wird bald Ablaufen bitte verbrauchen sie diese bald\n";
            }
        
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


    void menu() {
        
        
        
    int choice;
        
            std::cout << "Willkommen bei ihrer Vorratskammer\n\n";
        do
        {
            std::cout << "0. Verlassen\n1.Gegenstand hinzufügen\n2.Dinge verbrauchen oder entfernen\n3.Lassen sie sich Gespeicherte gegenstände anzeigen\n4.Lassen sie sich ausgeben welche Gegenstände bald auslaufen";
            std::cin >> choice;


            switch(choice)
        {
            case 0:
                std::cout << "Auf wiedersehen\n";
                
            case 1:            
            hinzufügen();
            break;
            case 2:
            entfernen();
                break;
            case 3:
            anzeigen();
                break;
            case 4:
            zeit();
            break;
        }
    }
      while (choice != 0);

      
    }  
};

int main(){
    Vorratskammer vk;
    vk.einlesen();
    vk.menu();

    
   
}
   
