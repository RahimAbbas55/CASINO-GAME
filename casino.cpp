#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
void rules();

int main()
{
    string name;
    int dice,guess;
    double amount,betting;
    char choice;
    srand(time(0));
    cout<<"-----------------WELCOME TO CASINO GAME-----------------"<<'\n';
    cout<<"---------------------ENTER YOUR NAME-----------------"<<'\n';
    getline(cin,name);
    cout<<"PLAYER "<<name<<"!"<<'\n';
    cout<<"ENTER YOUR BALANCE: "<<'\n';
    cin>>amount;
  
    do
    {
        rules();cout<<'\n';
        cout<<"YOUR CURRENT BALANCE IS $"<<amount<<'\n';
        
        do
        {
            cout<<"ENTER THE AMOUNT OF MONEY YOU WANT TO BET: "<<'\n';
            cin>>betting;cout<<'\n';
            if(betting>amount)
            {
                cout<<"THE AMOUNT YOU ARE TRYING TO BET IS GREATER THAN YOUR JAIB KA PAISA."<<"\n";
                cout<<"RE-ENTER KAR BEGAIRAT."<<'\n';
            }
        }while(betting>amount);

        do
        {
            cout<<"ENTER YOUR GUESS BETWEEN 1 AND 10: ";
            cin>>guess;cout<<'\n';
            if(guess<=0 || guess>10)
            {
                cout<<"INVALID GUESS."<<'\n';
                cout<<"PLEASE RE-ENTER."<<'\n';
            }
        } while (guess<=0 || guess>10);

        dice=rand()%10+1;
        if(dice == guess)
        {
            cout<<"CONGRATULATIONS!!! YOU GUESSED RIGHT. YOU WON."<<'\n';
            amount+=betting*10;
        }
        if(dice!=guess)
        {
            cout<<"HAHAHAHAHAH HAARRR GAYA GANDU."<<'\n';
            amount-=betting;
        }
        cout<<"THE GUESSED NUMBER WAS: "<<dice<<'\n';
        cout<<name<<" YOUR CURRENT BALANCE IS: "<<amount<<'\n';
        if(amount==0)
        {
            cout<<"YOU LOST.SORRY."<<'\n';
            break;
        }
        cout<<"PRESS 'Y' OR 'y' IF YOU WANT TO PLAY AGAIN "<<'\n';
        cin>>choice;
    }while(choice=='Y' || choice=='y');

    return 0;
}
void rules()
{
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

