#include<iostream>
using namespace std;
template <typename u>
class calculator{
	public:
		u add(u a,u b){
			return a+b;
		}
		u multiply(u a,u b){
			return a*b;
		}
		u subtract(u a,u b){
			return a-b;
		}
		u divide(u a,u b){
			try{
				if(b!=0){
					cout<<"division = "<<a/b<<endl;
					return a/b;
				}
				else {
					throw b;
				}
	    	}
			catch (u b){
				cout<<"denominator cannot be zero in division"<<endl;
			}
		}
};
int main(){
	char operatorr,choice;
	calculator <float>cal1;
	cout<<"\t\t\t\t\t\tCALCULATOR!!!\t\t\t\t"<<endl<<endl<<endl;
	float num1,num2;
	do{
        cout<<"Do you want to use the Calculator ?\n1. Yes(y)\n2. No(N)\nChoice: ";
        cin>>choice;
        cout<<endl;
        if(choice=='Y' || choice=='y'){
        	cout<<"Enter the operation you want to perform:-\n1. Addition(+)\n2. Subtraction(-)\n3. Multplication(*)\n4. Division(/)\nChoice: ";
			cin>>operatorr;
        	cout<<"\nEnter the fisrt number = ";
        	cin>>num1;
        	cout<<"\nEnter the second number = ";
			cin>>num2;
			switch (operatorr){
				case '+':
				{
					cout<<"\n\n\t\t"<<num1<<"\t"<<operatorr<<"\t"<<num2<<"\t=\t"<<cal1.add(num1,num2)<<endl<<endl;
					break;
			   }
			    case '-':
				{
			    	cout<<"\n\n\t\t"<<num1<<"\t"<<operatorr<<"\t"<<num2<<"\t=\t"<<cal1.subtract(num1,num2)<<endl<<endl;
					break;
				}
				case '/':
				{
					cout<<"\n\n\t\t"<<num1<<"\t"<<operatorr<<"\t"<<num2<<"\t=\t"<<cal1.divide(num1,num2)<<endl<<endl;
					break;
				}
				case '*':
				{
					cout<<"\n\n\t\t"<<num1<<"\t"<<operatorr<<"\t"<<num2<<"\t=\t"<<cal1.multiply(num1,num2)<<endl<<endl;
					break;
				}
				default:
				{
					cout<<"Invalid choice!"<<endl;
					break;
			}         
		}
		}
		else if(choice=='N'||choice=='n'){
	    	cout<<"You have exited Calculator!"<<endl;
	    	return 0;
	    }
        else{
            cout<<"Enter a valid choice!";
        }
    }while (choice!='Y'|| choice!='y');
}
