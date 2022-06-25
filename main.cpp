#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
#include <locale.h>
#include <fstream>

using namespace std;

int wybor;

void opcja1(int &kasa)
{

    int liczba[6],cyfry[6],trafionych;
    char czydalej;
     cout << "\n\n";
      cout<<"\n\n";
    cout << "\t\tZasady gry\n";
       cout<<"\n\n";
    cout << "\t1. Podaj swoje 6 liczb z przedzialu od 1 do 50.\n";
    cout << "\t2. Przegrywasz losowanie jesli nie trafisz\n";
    cout << "\t3. Kupon kosztuje 5PLN.\n\n";
    do
    {
    for(int i=0;i<6;i++)
    {


        cout<<"Podaj swoja "<<i+1<<" liczbe:";
        cin>>cyfry[i];
    }

    cout <<" Za 3 sek nastapi zwolnienie blokady" << endl;
    Sleep(3000);
    srand(time(NULL));
    for (int j=0; j<=5; j++)
    {

        liczba[j]= rand()%49+1;
            Sleep(1000);
        cout<<liczba[j]<<endl;
    }
    for (int b=0; b<=5; b++)
    {
            if(cyfry[b]==liczba[b])
            {
                trafionych++;
            }
    }
    if(trafionych==6)
    {
        cout<<"Wygrales glowną nagrode! 1 000 000 000 PLN"<<endl;
        kasa+=1000000000;
    }
    else
    cout<<"Trafiles "<<trafionych<<" liczb!"<<endl;
    kasa-=5;

    cout<<"Chcesz grac dalej?Nacisnij (t/n)"<<endl;
    cout << "Masz "<< kasa <<"PLN\n";
    cin>>czydalej;
    }while (czydalej=='t' && kasa>0);
}
void opcja2(int &kasa)
{

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


    cout<<"Podaj numer ktory obstawiasz"<<endl;
    cin>>wybranaliczba;

      srand( time( NULL));
    int ruletka=rand()%36+1;
    if(ruletka==wybranaliczba)
    {
        cout << "Gratulacje! Wygrales "<<ileZaklad*10<<" !!"<<endl;
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
    int los[3],bank=0;
    cout << "\n\n";
    cout << "\t\tZasady gry\n";
    cout<<"\n\n";
    cout << "\t1. Kazda runda kosztuje 5 PLN.\n";
    cout << "\t2. Wylosuj trzy takie same symbole aby wygrac \n";
    cout << "\t3. Wcisnij t aby pociagnac za spust maszyny \n";
    cout << "Masz:"<<kasa<<endl;
    cin>>wajcha;

usleep(300000);

while(wajcha== 't' && kasa>0 && bank!=1){
    int  runda=0;
    cout << "Ciagniesz za wajche... " << endl;
    usleep(50000);
    while(runda<3)
    {
    los[runda]=rand()% 9 + 1;
    if (los[runda] == 1)
        cout << "\t\t * ";
    else if (los[runda] == 2)
        cout << "\t\t & ";
    else if (los[runda] == 3)
        cout << "\t\t ^ ";
    else if (los[runda] == 4)
        cout << "\t\t % ";
    else if (los[runda] == 5)
        cout << "\t\t $ ";
    else if (los[runda] == 6)
        cout << "\t\t # ";
    else if (los[runda] == 7)
        cout << "\t\t ~ ";
    else if (los[runda] == 8)
        cout << "\t\t @ ";
    else if (los[runda] == 9)
        cout << "\t\t ! ";
     else if (los[runda] == 0)
        cout << "\t\t + ";
        runda++;
    }

    if((los[0]==5)&&(los[1]==5)&&(los[2]==5))
    {
        cout<<"\nROZBILES BANK!! Bierzesz wysztkie pieniadze z automatu."<<endl;
        kasa+=rand()% 9000 + 10000;
        bank=1;
    }

        kasa-=5;
    cout << "\n\nChcesz pograc jeszcze raz? (t/n) Masz:"<<kasa<<endl;
    cin>>wajcha;
 }
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
        cout << "Gratulacje, przezyles. Bierz kase od wszystkich i spadaj." << endl;
        kasa+=120;
    }
}
void opcja5(int &kasa)
{
  int talia[4][14],IleZaklad, ktoraKarta,loskolor,losfigura,wagaKarty,sumaWagiKart,wagaKarty_pc,sumaWagiKart_pc;
    cout << "\n\n";
    cout << "\t\tZasady gry\n";
    cout<<"\n\n";
    cout << "\t1. Losujesz karte z talii. \n";
    cout << "\t2. Kazda karta ma swoja wage. Jezeli suma wag kart przekroczy 21 przegrywasz. \n";
    cout << "\t3. Wygrywasz dwukrotnosc stawki jesli masz wiecej punktow niz krupier. \n";
  cout << "\nMasz "<< kasa <<"PLN\n";
  cout << "Ile stawiasz : ";
  cin >>IleZaklad;
  char czydalej;
char const * const kolor[4]={"kier","pik","trefl","karo"};
char const * const figura[13]={"Dwojka", "Trojka", "Czworka", "Piatka", "Szostka", "Siodemka", "Osemka", "Dziewiatka", "Dziesiatka", "Walet", "Dama", "Krol","As"};
int const punktacja[14]={2,3,4,5,6,7,8,9,10,11};
do{
do{
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
  cout<<"Masz w kartach: "<<sumaWagiKart<<" punkty."<<endl;
  if(sumaWagiKart>21)
  {
      cout<<"Przelicytowales. Wygral krupier."<<endl;
      czydalej=='n';
      kasa-=IleZaklad;
  }
  else
  {
  cout<<"Ciagniesz kolejna karte? (t/n): ";
  cin>>czydalej;
  }
  }while(sumaWagiKart<21 && czydalej=='t');
do{
  do{
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
}while (sumaWagiKart_pc<16);
  cout<<"Suma kart krupiera: "<<sumaWagiKart_pc<<endl;

  if(sumaWagiKart>sumaWagiKart_pc && sumaWagiKart<=21)
  {
    cout<<"Wygrales! Gratulacje.";
  kasa+=IleZaklad*2;
  }
  else if(sumaWagiKart==sumaWagiKart_pc)
    cout<<"Remis.";
  else if(sumaWagiKart<sumaWagiKart_pc)
  {
      cout<<"Krupier wygral.";
      kasa-=IleZaklad;
  }

}
int main(){
    int kasa,koniec=0;
    int const minimalnyzaklad= 20;
    int const maskymalnyzaklad=200;
    string imie;


    srand(time(NULL));
    kasa = rand()%(maskymalnyzaklad-minimalnyzaklad)+minimalnyzaklad;

 	cout<<"\tWitaj w kasynie!\n";

    cout<<"Jak masz na imie?"<<endl;
    cin>>imie;
    while(koniec!=1 && kasa>0)
    {
    cout << "\t\nMasz "<< kasa <<"PLN\n\t";
    cout<<endl;
    cout<< "W co chcesz zagrac?"<<endl;
    cout<< "======================"<<endl;
    cout<< "1. Totolotek"<<endl;
    cout<< "2. Ruletka"<<endl;
    cout<< "3. Jednoreki bandyta"<<endl;
    cout<< "4. Rosyjska ruletka"<<endl;
    cout<< "5. Gra w oczko"<<endl;
    cout<< "6. Koniec programu"<<endl;
    cout<< "Wybierz: "<<endl;




  wybor=getch();
    switch(wybor)
    {
    case '1':opcja1(kasa);
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
        koniec=1;
        break;
    default: cout<<"Nie ma takiej opcji!";
    }
    getchar();getchar();
    system("cls");

    }
    if(kasa==0)
    cout<<"Koniec gry. Nie masz juz pieniedzy.";
    else
        cout<<"Dziekuje za gre.Do widzenia.";
    fstream plik;
    plik.open("scores.txt",ios::out);
    plik<<imie<<endl;
    plik<<kasa<<endl;
    plik.close();
    return 0;
    }

