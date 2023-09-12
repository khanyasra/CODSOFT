#include<iostream>
#include<cstdlib>
using namespace std;
class game{
	int number;
	int guessed_num;
	int points;
	int turns;
	public:
		game(){
			points=0;
			turns=1;
		}
		void getNum(int a,int b){
			number=a;
			guessed_num=b;
		}
		void turn(){
			turns++;
		}
		void point(){
			if(turns==1){
				points=points+30;
			}
			else if(turns<=3&&turns>1){
				points=points+10;
			}
			points=points+10;
		}
		void totalpoints(){
			cout<<"your total points = "<<points<<endl;
		}
		void number_game(int a,int b){
			int num;
			while(a!=b){
				if(a>b){
					cout<<"Guess a higher number"<<endl;
					if(a-b>=5){
						cout<<"Number is too low! "<<endl;
					}
				}
				else if(b>a){
					cout<<"Guess a lower number"<<endl;
					if(b-a>=5){
						cout<<"Number is too high!"<<endl;
					}
				}
				cout<<"Guess another number = ";
				cin>>num;
				turn();
				b=num;
			}
			cout<<"\t\t\t\tHURRAY!!\n\t\tYou have guessed the correct number "<<endl<<endl<<endl;
			point();
		}
};
int main(){
	int num,guess_num;
	char choice;
	cout<<"\t\t\t\tWELCOME TO THE NUMBER GUESSING GAME!!!\t\t\t\t"<<endl<<endl<<endl;
	cout<<"Rules:-\n1.if you have guessed the number correctly you will get 10 points.\n2.If you have guessed within the first try you will get additional 30 points.\n3.If you have guessed within first 3 tries you will get additional 10 points.\n\n\n";
	do{
        cout<<"Do you want to play ?\n1. Yes(y)\n2. No(N)\nChoice: ";
        cin>>choice;
        if(choice=='Y' || choice=='y'){
            num=(rand()%30)-1;
			cout<<"Guess a number between 1 - 30 = ";
			cin>>guess_num;
			cout<<endl;
			game g1;
			g1.number_game(num,guess_num);
			g1.totalpoints();
		}
		else if(choice=='N'||choice=='n'){
	    	cout<<"You have exited the game!"<<endl;
	    	return 0;
	    }
        else{
            cout<<"Enter a valid choice!";
        }
    }while (choice!='Y'|| choice!='y');
}
