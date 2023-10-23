#include<iostream>
#include<dos.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x,int y)
{
    CursorPosition.X=x;
    CursorPosition.Y=y;
    SetConsoleCursorPosition(console, CursorPosition);
}
void drawBorder(int x=0,int y=0){
    char v = 186;
    char h = 205;
    char tr = 187;
    char br = 188;
    char tl = 201;
    char bl = 200;
    int width = 30;
    int height = 3;

    for(int i=1;i<=height;i++)
    {
        for(int j=1;j<=width;j++)
        {
            gotoxy(j+x,i+y);
            if(i==1 && j==1) cout<<tl;
            else if(i==height && j==1) cout<<bl;
            else if(i==1 && j==width) cout<<tr;
            else if(i==height && j==width) cout<<br;
            else if(i==height || i==1) cout<<h;
            else if(j==width || j==1) cout<<v;
        }
    }
}

int main()
{
    srand((unsigned) time(NULL));

    system("cls");

    char password[21];
    int length;

    char op;
    do{
        system("cls");

        cout<<"???????????????????????????"<<endl;
        cout<<endl;
        cout<<"\t\t   ???"<<endl;
        cout<<"\t\t   ?  ?"<<endl;
        cout<<"\t\t?????"<<endl;
        cout<<"\t\t?? ??"<<endl;
        cout<<"\t\t?????"<<endl;
        cout<<endl;
        cout<<"        PASSWORD STRENGTH CHECKER    "<<endl;
        cout<<"?????????????????????"<<endl;

        cout<<endl<<"\tEnter Password: ";
        cin>>password;

        char pass[21]= "";
        int excess = strlen(password)-6;
        int baseScore=50;

        int numUpper=0;
        int numSymbol=0;
        int numLower=0;
        int numDigit=0;

        int bonusExcess=3;
        int bonusUpper=4;
        int bonusNumbers=5;
        int bonusSymbols=5;
        int bonusCombo=0;
        int bonusFlatLower=0;
        int bonusFlatNumber=0;

        int i;
        for(i=0;i<strlen(password);i++){
            if(password[i]>=48 && password[i]<=57)
            {
                numDigit++;
            }
            if(password[i]>=97 && password[i]<=125)
            {
                numLower++;
            }
            if(password[i]>=65 && password[i]<=90)
            {
                numUpper++;
            }
            if(password[i]>=33 && password[i]<=47)
            {
                numSymbol++;
            }
        }
        if(numUpper>0 && numDigit>0 && numSymbol>0)
        {
            bonusCombo=25;
        }
        else if((numUpper>0 && numDigit>0) || (numUpper>0 && numSymbol>0) || (numDigit>0 && numSymbol>0))
        {
            bonusCombo=15;
        }
        int score=baseScore+(excess*bonusExcess)+(numUpper*bonusUpper)+(numDigit*bonusNumbers)+(numSymbol*bonusSymbols)+bonusCombo+bonusFlatLower+bonusFlatNumber;
        gotoxy(8,14);
        cout<<"Checking password strength....";
        gotoxy(8,15);
        for(int i=0;i<27;i++)
        {
            cout<<(char)176;
            Sleep(100);
        }

        drawBorder(7,17);

        gotoxy(10,19);
        if(score<50)
        {
            cout<<"Password status: Weak";
        }
        else if(score>=50 && score<75)
        {
            cout<<"Password statsu:AVERAGE";

        }
        else if(score>=100)
        {
            cout<<"Password status secure";
        }

        gotoxy(9,23);  
        cout<<"Do you want to generate the password again\n";
        op=getch();

    }while(op=='y' || op=='Y');

    return 0;

}
