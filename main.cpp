#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
#include <locale.h>


using namespace std;

char wybor;
void opcja1() //Do dodania tablica z porównaniami cyfr podanych i losowanych;  kasa;
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
void opcja2() //logika gry;kasa
{

     cout << "\n\n";
      cout<<"\n\n";
    cout << "\t\tZasady gry\n";
       cout<<"\n\n";
    cout << "\t1. Wybierz liczbe pomiedzy 1 i 10\n";
    cout << "\t2. Zaklad mnozony razy dzeisiec\n";
    cout << "\t3. Przegrywasz zaklad jesli nie trafisz\n\n";
   cout<<"\n\n";


}
void opcja3() //kasa
{
    char wajcha;
    cout << "\n\n";
    cout << "\t\tZasady gry\n";
    cout<<"\n\n";
    cout << "\t1. Kazda runda kosztuje 5 PLN.\n";
    cout << "\t2. Wylosuj trzy takie same symbole aby wygrac \n";
    cout << "\t3. Wcisnij t aby pociagnac za spust maszyny \n";
    cin>>wajcha;

usleep(300000);
int poczatekgry();
int liczba=0;

while(wajcha== 't'){
    int liczba=0;
    cout << "Ciagniesz za wajche... " << endl;
    usleep(50000);
    while (liczba < 3)
    {
    int  runda=rand()% 9 + 1;
    if (runda == 1)
        cout << "\t\t * ";
    else if (runda == 2)
        cout << "\t\t & ";
    else if (runda == 3)
        cout << "\t\t ^ ";
    else if (runda == 4)
        cout << "\t\t % ";
    else if (runda == 5)
        cout << "\t\t $ ";
    else if (runda == 6)
        cout << "\t\t # ";
    else if (runda == 7)
        cout << "\t\t ~ ";
    else if (runda == 8)
        cout << "\t\t @ ";
    else
        cout << "\t\t ! ";
    liczba++;
    }

    cout << "\n\nChcesz pograc jeszcze raz? (t/n)" << endl;
    cin>>wajcha;
 }
return;
}
void opcja4() //kasa
{
    cout << "\n\n";
    cout << "\t\tZasady gry\n";
    cout<<"\n\n";
    cout << "\t1. Kasa na stol. 20PLN.\n";
    cout << "\t2. Bierzesz rewolwer do reki.. \n";
    cout << "\t3. Przykladasz do skroni..\n\n";
    usleep(6000000);
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
                if(random == 4){
                    smierc = true;
                    cout<<"Nie zyjesz i nikt nie placze. " << runda << " rund." << endl;
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
    int kasa;
    int const minimalnyzaklad= 20;
    int const maskymalnyzaklad=200;

    srand(time(NULL));
    kasa = rand()%(maskymalnyzaklad-minimalnyzaklad)+minimalnyzaklad;
    for(;;)
    {
    setlocale(LC_ALL, "");
    cout << "Witaj w krainie gdzie kazdy obcy ginie\n";

    cout << "\t\nMasz "<< kasa <<"PLN\n\t";
    cout<<endl;
    cout<< "W co chcesz zagrac?"<<endl;
    cout<< "======================"<<endl;
    cout<< "1. Totolotek"<<endl;
    cout<< "2. Ruletka"<<endl;
    cout<< "3. Jednoreki bandyta"<<endl;
    cout<< "4. Rosyjska ruletka"<<endl;
    cout<< "5. Koniec programu"<<endl;
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

