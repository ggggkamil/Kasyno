#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
#include <locale.h>


using namespace std;

char wybor;
void opcja1()
{

    int liczba;
    char cyfry[4];
    cout << "Witaj w losowaniu! Podaj swoje 6 cyfr." << endl;
    //6 cyfr nie jedna
    cin>> cyfry;
    cout <<" Za 3 sek nastapi zwolnienie blokady" << endl;
    Sleep(3000);
    cout<<endl;
    srand(time(NULL));
    for (int i=1; i<=6; i++)
    {
    liczba = rand()%49+1;
    Sleep(1000);
    cout<<liczba<<endl;
    }
    //Dodaj porównanie cyfr z losowania z tymi z tabeli cyfry
    //if(cyfry==liczba)
    cout<<cyfry;
}
void opcja2()
{

     cout << "\n\n";
      cout<<"\n========================================================================================\n";
    cout << "\t\tZasady gry\n";
       cout<<"\n========================================================================================\n";
    cout << "\t1. Wybierz liczbe pomiedzy 1 i 10\n";
    cout << "\t2. Zaklad mnozony razy dzeisiec\n";
    cout << "\t3. Przegrywasz zaklad jesli nie trafisz\n\n";
   cout<<"\n========================================================================================\n";

}
void opcja3()
{

}
void opcja4()
{
    srand(time(NULL));

 bool smierc = false;
 int runda = 1;
 while(runda <= 6 && smierc != true){
        int random = rand()%6 + 1;
        cout << "Runda " << runda;
        usleep(300000);
        cout << ".";
        usleep(300000);
        cout << ".";
        usleep(300000);
        cout << ".";
     if(random == 5){
       smierc = true;
       cout << "Jeb!"<< endl << "Przegrales, nie zyjesz i nikt nie placze. " << runda << " rund." << endl;
       exit(0);
     }
     else{
       cout << "Klik." << endl;
       smierc = false;
     }
     runda++;
 }

    if(smierc==false){
        cout << "Gratulacje, przezyles. Bierz kase ze stolu i spadaj." << endl;
    }
        }

int main(){
    for(;;)
    {
    setlocale(LC_ALL, "");
    cout << "Witaj w krainie gdzie kazdy obcy ginie";
    cout << "Masz 2000 cebulionow na start";
    cout<<endl;
    cout<< "W co chcesz zagrac?"<<endl;
    cout<< "--------------"<<endl;
    cout<< "1. Totolotek"<<endl;
    cout<< "2. Ruletka"<<endl;
    cout<< "3. Jednoreki bandyta"<<endl;
    cout<< "4. Rosyjska ruletka"<<endl;
    cout<< "5. Koniec programy"<<endl;
    cout<< "Wybierz: "<<endl;
  wybor=getch();
    switch(wybor)
    {
    case '1':opcja1();
    break;
    case '2':opcja2();
        break;
    case '3':opcja3();
        break;
    case '4':opcja4();
    break;
     case '5':
        exit(0);
        break;
    default: cout<<"Nie ma takiej opcji!";
    }
    getchar();getchar();
    system("cls");
    }
    return 0;
    }

