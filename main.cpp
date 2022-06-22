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
    cout << "Witaj w losowaniu! Podaj swoje 6 liczb." << endl;
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
void opcja2(int &kasa) //wyłącznik (t/n) nie dziala,
{
    cout<<kasa;
     cout << "\n\n";
      cout<<"\n\n";
    cout << "\t\tZasady gry\n";
       cout<<"\n\n";
    cout << "\t1. Wybierz liczbe pomiedzy 1 i 36\n";
    cout << "\t2. Zaklad mnozony razy dziesiec\n";
    cout << "\t3. Przegrywasz zaklad jesli nie trafisz\n\n";
    char czydalej;
   do
    {
   cout << "Za ile chcesz grac? Masz:"<<kasa<<endl;
    int ileZaklad;

    int Budget=kasa;
    cin >> ileZaklad;
    while(ileZaklad <1 || ileZaklad > Budget )
    {
        if(kasa==0)
        {
            cout<<"To koniec. Nie masz juz pieniedzy.";
            exit(0);
        }
        cout << endl << "Masz tylko "<< Budget <<" na swoim koncie ";
        cout << endl << "Wpisz kwote, ktora mozesz postawic:";
        cin>> ileZaklad;
    }

    int wybranaliczba;


    cout<<"Witaj, podaj numer ktory obstawiasz"<<endl;
    cin>>wybranaliczba;

      srand( time( NULL));
    int ruletka=rand()%36+1;
    if(ruletka==wybranaliczba)
    {
        cout << "Gratulacje! Wygrałeś "<<ileZaklad*10<<" !!"<<endl;
        kasa+=ileZaklad*10;
    }
    else if(ruletka!=wybranaliczba)
    {
        cout<<"Wylosowana liczba to "<<ruletka<<". Tym razem pudlo."<<endl;
        kasa-=ileZaklad;
    }
    cout<<"Chcesz grac dalej?Nacisnij (t/n)"<<endl;
    cin>>czydalej;
    }while (czydalej=='t' || czydalej=='T' && kasa!=0);
}

void opcja3(int &kasa) //WYGRANA,porównanie trzech symboli
{
    char wajcha;
    cout << "\n\n";
    cout << "\t\tZasady gry\n";
    cout<<"\n\n";
    cout << "\t1. Kazda runda kosztuje 5 PLN.\n";
    cout << "\t2. Wylosuj trzy takie same symbole aby wygrac \n";
    cout << "\t3. Wcisnij t aby pociagnac za spust maszyny \n";
    cout << "Masz:"<<kasa<<endl;
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
    kasa-=5;

    cout << "\n\nChcesz pograc jeszcze raz? (t/n) Masz:"<<kasa<<endl;
    cin>>wajcha;
 }
return;
}
void opcja4(int &kasa)
{
    cout << "\n\n";
    cout << "\t\tZasady gry\n";
    cout<<"\n\n";
    cout << "\t1. Kasa na stol. 20PLN.\n";
    cout << "\t2. Bierzesz rewolwer do reki.. \n";
    cout << "\t3. Przykladasz do skroni..\n\n";
  //usleep(6000000);
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
                    cout<<"Nie zyjesz i nikt nie placze. " << runda << " rund." << endl;
                    exit(0);
                    }
            else{
                    cout << "Klik." << endl;
                    smierc = false;
                }
            runda++;
        }
        kasa-=20;
    if(smierc==false){
        cout << "Gratulacje, przezyles. Bierz kase ze stolu i spadaj." << endl;
        kasa+=120;
    }
}
void opcja5(int &kasa)
{
  int talia[4][14],IleZaklad, ktoraKarta,loskolor,losfigura,wagaKarty,sumaWagiKart=0,wagaKarty_pc,sumaWagiKart_pc;
  cout << "\t\nMasz "<< kasa <<"PLN\n\t";
  cout << "Ile stawiasz : ";
  cin >>IleZaklad;
  char czydalej;
char const * const kolor[4]={"kier","piik","trefl","karo"};
char const * const figura[13]={"Dwojka", "Trojka", "Czworka", "Piatka", "Szostka", "Siodemka", "Osemka", "Dziewiatka", "Dziesiatka", "Walet", "Dama", "Krol","As"};
int const punktacja[14]={2,3,4,5,6,7,8,9,10,11};
do{

do
  {
    loskolor=rand()%4;
    losfigura=rand()%14;
  }while (talia[loskolor][losfigura]==0);

    if(losfigura>=0 && losfigura<=8)
   wagaKarty=losfigura+2;
  else if(losfigura=9) //walet
    wagaKarty=2;
  else if(losfigura=10) //dama
    wagaKarty=3;
  else if(losfigura=11) //król
    wagaKarty=4;
  else if(losfigura=13) //as
    wagaKarty=11;
  cout<<"Twoje karta : ";
  cout<<figura[losfigura];
  cout<<" "<<kolor[loskolor]<<" waga: "<<wagaKarty<<endl;
  sumaWagiKart+=wagaKarty;
  cout<<"Masz w kartach: "<<sumaWagiKart<<endl;
  cout<<"Ciagniesz kolejna karte? (t/n): ";
  cin>>czydalej;
  }while (czydalej=='t' || czydalej=='T' && sumaWagiKart>21 && kasa!=0);
  do{
    do
  {
    loskolor=rand()%4;
    losfigura=rand()%14;
  }while (talia[loskolor][losfigura]==0);

    if(losfigura>=0 && losfigura<=9)
   wagaKarty_pc=losfigura+2;
  else if(losfigura=9) //walet
    wagaKarty_pc=2;
  else if(losfigura=10) //dama
    wagaKarty_pc=3;
  else if(losfigura=11) //król
    wagaKarty_pc=4;
  else if(losfigura=12) //as
    wagaKarty_pc=11;
    sumaWagiKart_pc+=wagaKarty_pc;
  }while (sumaWagiKart_pc<=17 && sumaWagiKart_pc<21 );
  cout<<"Suma kart krupiera: "<<sumaWagiKart_pc<<endl;

  if(sumaWagiKart>sumaWagiKart_pc)
    cout<<"Wygrales! Gratulacje.";
  else if(sumaWagiKart==sumaWagiKart_pc)
    cout<<"Remis.";
  else if(sumaWagiKart<sumaWagiKart_pc)
    cout<<"Krupier wygral.";

}




int main(){
    int kasa;
    int const minimalnyzaklad= 20;
    int const maskymalnyzaklad=200;

    srand(time(NULL));
    kasa = rand()%(maskymalnyzaklad-minimalnyzaklad)+minimalnyzaklad;

 	cout<<"Witaj w krainie gdzie kazdy obcy ginie\n";



    cout << "\t\nMasz "<< kasa <<"PLN\n\t";
    cout<<endl;
    cout<< "W co chcesz zagrac?"<<endl;
    cout<< "======================"<<endl;
    cout<< "1. Totolotek"<<endl;
    cout<< "2. Ruletka"<<endl;
    cout<< "3. Jednoreki bandyta"<<endl;
    cout<< "4. Rosyjska ruletka"<<endl;
    cout<< "5. Karty"<<endl;
    cout<< "6. Koniec programu"<<endl;
    cout<< "Wybierz: "<<endl;
  wybor=getch();
    switch(wybor)
    {
    case '1':opcja1();
        break;
    case '2':opcja2(kasa);
        break;
    case '3':opcja3(kasa);
        break;
    case '4':opcja4(kasa);
        break;
     case '5':opcja5(kasa);
        break;
    case '6':
        exit(0);
        break;
    default: cout<<"Nie ma takiej opcji!";
    }
    getchar();getchar();
    system("cls");

    return 0;
    }

