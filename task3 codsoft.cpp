#include<iostream>


using namespace std;
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int choice;
int row;
int coloum;
char turn = 'x';
bool tie = false;
void gameboard()
{
	cout << "\t\t   |   |   " << endl;
	cout <<"\t\t" << board[0][0] << "  |" << board[0][1] << "  |" << board[0][2] << endl;
	cout << "\t\t___|___|___" << endl;
	cout << "\t\t   |   |   " << endl;
	cout << "\t\t" << board[1][0] << "  |" << board[1][1] << "  |" << board[1][2] << endl;
	cout << "\t\t___|___|___" << endl;
	cout << "\t\t   |   |   " << endl;
	cout <<"\t\t" << board[2][0] << "  |" << board[2][1] << "  |" << board[2][2] << endl;
	cout << "\t\t   |   |   " << endl;
}
void turn_function(){
	if (turn == 'x') {
		cout << "\nPlayer-1 [x]:\nchoice:- ";
	}
	else if (turn == 'o') {
		cout << "\nPlayer-2 [o]:\nchoice:- ";
	}
	cin >> choice;

	switch (choice) {
	case 1:
		row = 0; 
		coloum = 0;
		break;
	case 2:
		row = 0;
		coloum = 1;
		break;
	case 3:
		row = 0;
		coloum = 2;
		break;
	case 4:
		row = 1;
		coloum = 0;
		break;
	case 5:
		row = 1;
		coloum = 1;
		break;
	case 6:
		row = 1;
		coloum = 2;
		break;
	case 7:
		row = 2;
		coloum = 0;
		break;
	case 8:
		row = 2;
		coloum = 1;
		break;
	case 9:
		row = 2;
		coloum = 2;
		break;
	default:
		cout << "\nInvalid choice!!!\n";
	}

	if (turn == 'x' && board[row][coloum] != 'x' && board[row][coloum] != 'o') {
		board[row][coloum] = 'x';
		turn = 'o';
	}
	else if (turn == 'o' && board[row][coloum] != 'x' && board[row][coloum] != 'o') {
		board[row][coloum] = 'o';
		turn = 'x';
	}
	else {
		cout << "box is already filled! Please choose again." << endl;
		turn_function();
	}
	gameboard();
}
bool result() {
	//checking the win for Simple Rows and Simple Column
	for (int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return false;

	//checking the win for  diagonals

	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return false;

	//Checking the game is in continue mode or not
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return true;

	//Checking the if game already draw
	tie = true;
	return false;
}

int main() {
	while (result()) {
		cout << "\t\t\t\t\tWELCOME TO THE TICK--TAC--TOE GAME!!!\t\t\t\t\t\nPlayer - 1:-'X'\nPlayer - 2:-'O'\n ";
		gameboard();
		turn_function();
		result();
		system("cls");
	}
	if (turn == 'x' && tie == false) {
		cout << "\n\nCongratulations!Player - 2 with 'O' has won the game" << endl<<endl;
	}
	else if (turn == 'o' && tie == false) {
		cout << "\n\nCongratulations!Player - 1 with 'X' has won the game"<<endl<<endl;
	}
	else
		cout << "\n\nGAME DRAW!!!" << endl <<endl;
}
