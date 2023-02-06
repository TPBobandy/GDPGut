#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string x;
string y;
string z;

int hinzufügen()
{
    
    string x, z;
    int d, m ,y;
    
    

            std::cout << "Bitte geben sie einen Gegenstand ein\n";
            std::cin >> x;
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
                out << x << "|" << y <<  "|" << z << "\n"; 
                out.close();
                

    return 0;
   
}
        
int verbrauchen()
{
            std::cout << "Bitte geben sie einen Gegenstand ein\n" << std::endl;
            std::cin >> x;

                std::ifstream in("Vorratskammer.txt");
            
    

    
    
        return 0;
}

int entfernen()
{
return 0; 
}


int menge(){

    string text;
//std::string menge;
    string ding;
    string ausgabe;
    int found;
    
    

        std::cout << "Bitte nennen sie den Gegenstand von welchem sie die Menge erfahren wollen\n";
        std::cin >> ding;

    std::ifstream in("Vorratskammer.txt");
                             
                    while (std::getline(in, text)){
                        std::cout << text << " \n";
                            found= text.find(ding);
                            
                   }
           std::getline(in, text);
           std::cout << text << " \n";
                        std::cout << found << "\n";
                       if (found == -1)
                            std::cout << "Diesen Gegenstand gibt es nicht in ihrer Vorratskammer\n";


                    
                    ausgabe=text.find(ding);

std::cout << ausgabe << std::endl;



 return 0;
}


int main() {
   
   int choice;

        std::cout << "Willkommen bei ihrer Vorratskammer\n\n";
    do
    {
        std::cout << "0. Verlassen\n1.Gegenstand hinzufügen\n2.Gegenstand verbrauchen\n3.Gegenstand entfernen\n4.Lassen sie sich alle gespeicherten gegenstände anzeigen\n";
        std::cin >> choice;


        switch(choice)
    {
        case 0:
            std::cout << "Auf wiedersehen\n";
            return 0;
        case 1:            
            hinzufügen();
            break;
        case 2:
            verbrauchen();
            break;
        case 3:
            entfernen();
            break;
        case 4:
            menge();
            break;
    }
}
     while (choice != 0);
    
 

   
}