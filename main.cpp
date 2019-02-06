#define sizes 15

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <ctype.h>
#include <map>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <fstream>


using namespace std;

/*
const int size = 15;
unsigned int moverow = 0, movecol = 0;
char the_word[size];
char direction ;
char board[size][size];
int status = 0;


static int tourner = 0;
static int player1, player2 = 0; //rohit's point system

int points = 0;
*/

char newg, saveg;
const int mz = 30;
char animation[mz][mz];

//int player1 = 0, player2 = 0;

class scr_board
{
    // ##### class members ####
protected:

    unsigned int moverow = 0, movecol = 0;
    char the_word[sizes];
    char direction ;
    char board[sizes][sizes];
    int status = 0;
    int tourner = 0;
    int points = 0;
    int player1 = 0, player2 = 0;


    // ##### class methods ####
private:
    void status_print();
    void display();
    int enter_right(char word[]);
    int enter_down(char word[]);
    int enter_word();
    void board_copy(scr_board a);
    void save_game_write();
    int save_game_read();

public:
        void turn();

        void giveword(char str[])
        {
            strcpy(str, the_word);
        }

        int givemoverow()
        {
            return moverow;
        }

        int givemovecol()
        {
            return movecol;
        }

        scr_board()
        {
            int i, j;
            for (i=0 ; i<sizes ; i++)
            {
                for (j=0 ; j<sizes ; j++)
                {
                    board[i][j] = ' ';

                    //doubles letters and words
                    if ((i==j) || (i+j == (sizes-1)))
                    {
                        board[i][j] = 'l';
                    }

                    if ((i%7==0) && (j%7==0))
                    {
                        board[i][j] = 'w';
                    }
                }
            }
            board[7][7] = 'l';
        }



};

void scr_board::board_copy(scr_board a)
        {
            moverow = a.moverow;
            movecol = a.movecol;
            strcpy(the_word, a.the_word);
            direction = a.direction ;


            for (int i = 0; i < sizes; i++)
            {
                for (int j = 0; j < sizes; j++)
                {
                    board[i][j] = a.board[i][j];
                }
            }


            status = a.status;
            tourner = a.tourner;
            points = a.points;
            player1 = a.player1;
            player2 = a.player2;
        }


scr_board game;


map<char, int> point;

class Users: public scr_board
 {
                                                                                    // letter map
public:

	int score(char direction) {
		point['A'] = 1;
		point['B'] = 3;
		point['C'] = 3;
		point['D'] = 2;
		point['E'] = 1;
		point['F'] = 4;
		point['G'] = 2;
		point['H'] = 4;
		point['I'] = 1;
		point['J'] = 8;
		point['K'] = 5;
		point['L'] = 4;
		point['M'] = 3;
		point['N'] = 1;
		point['O'] = 1;
		point['P'] = 3;
		point['Q'] = 10;
		point['R'] = 1;
		point['S'] = 1;
		point['T'] = 1;
		point['U'] = 1;
		point['V'] = 4;
		point['W'] = 4;
		point['X'] = 8;
		point['Y'] = 4;
		point['Z'] = 10;

		points = 0;

		game.giveword(the_word);
		moverow = game.givemoverow();
		movecol = game.givemovecol();

		for (int j = 0; j < strlen(the_word); ++j) {
			points += point[the_word[j]];
		}


		if(direction == 'd') {											// moverow scoring
			for(int j = moverow; j < moverow + strlen(the_word); j++) {
				if(board[movecol][j] == 'w')
					points *= 2;
				if(board[movecol][j] == 'l') {
					points += point[the_word[j - moverow]];
				}
			}
		}


		if(direction == 's') {											// movecol scoring
			for(int j = movecol; j < movecol + strlen(the_word); j++) {
				if(board[j][moverow] == 'w')
					points *= 2;
				if(board[j][moverow] == 'l') {
					points += point[the_word[j - movecol]];
				}
			}
		}


	return points;
	}
};

Users p1;
Users p2;

// #############################  STARTING SEQUENCE CODE ###############################

void delay (int seconds)
{
	for (double i = 0; i<= (185000000 * seconds); i++);
}

void show()
{
    int i, j;
    for (i = 0; i < mz ; i++)
    {
        for(j = 0; j < mz ; j++)
        {
            cout << animation[i][j] << ' ';
        }
    cout <<endl;
    }

}

void devs()
{
    getch();
    system("cls");

    cout << endl << endl
    << "\t\t Scrabble v2.0.1 and its user interface are\n"
    << "\t\t not protected by trademark or any other\n"
    << "\t\t pending or existing intellectual property\n"
    << "\t\t rights in India and other countries.\n"
    << endl
    << "\t\t All users are free to modify and distribute\n"
    << "\t\t this product under the guidelines of the fair\n"
    << "\t\t use policy. This product cannot be sold, rented,\n"
    << "\t\t mortgaged, loaned, auctioned or used in any other\n"
    << "\t\t manner to generate a revenue.\n"
    << endl;
    getch();
    cout << "\t\t All users, be warned.\n"
    << "\t\t This must not fall into the wrong hands."
    << endl;
    getch();
    cout << "\n\t[\t Developed by:\n"
    << "\t \t China, Gam, RK That's Right.\n"
    << "\t \t Also known as, respectively:\n"
    << "\t \t Chinmay S I\n\t\t Siddharth Gautam\n\t\t Rohit Kaushik\n"
    << "\t \t Contact: npskhack@gmail.com \t\t]";
}

void instructions()
{
    devs();

    getch();
    system("cls");

    cout << endl << '\t';
    cout << "Welcome to Scrabble v2.0.1!";
    cout << endl;
    getch();
    cout << "\t \t ...with a twist ! ! !" << endl;
    getch();
    cout << "Two players can play this game. If you do \n"
        << "not have someone to play with, we apologize. \n"
        << "We initially planned on making an AI but it \n"
        << "turned out to be unbeatable, so we scrapped it." << endl
        << endl << "In this version, you are not limited to a deck of characters, \n"
        << "so let your linguistic prowess run wild.";
    getch();
    cout << endl << "In the next update, perhaps we will make our game more faithful \n"
    << "to the original, but for now, you will have to deal with \n our inadequacies." << endl;
    getch();
    cout << "Stay tuned!";
    getch();
    system("cls");
    cout << endl << "Rules: \n Each letter has a corresponding point value. \nFill in words into the board and"
            << "rack up a high score! \n\n 'l' denotes double letter - points for these letters are doubled."
            << "\n 'w' denotes double word - points for these words are doubled.";
    getch();
    cout << endl << "Good luck!";
}

void menu()                                                             //starting screen
{
    cout << endl << endl << endl
    << "\t L \t O \t A \t D \t I \t N \t G  .  .  ." << endl;
    delay(2);


    int i, j, k = 0;
    char to_print;
    for (k = 65 ; k <= 85 ; k++)
    {
        if (k%2==0) cout << '\a';

      for(i = 0; i < mz ; i++)
        {
            for(j = 0; j < mz ; j++)
            {
                    animation[i][j] = (k+j-i);                          //random pattern generator
            }
        }
    show();
    system("cls");
    }
    cout << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl
    <<"\t S \t C \t R \t A \t B \t B \t L \t E \t 2.0.1" << endl << " \t \t \t \t \t \t \t \t ...with a twist.";

    instructions();

}


int check(char w[])                                                    // returns 1 if word is allowed
{
    ifstream ifile("WORDS.txt", ios::in);

    char c[20];

    while(ifile)
    {
        ifile >> c;
        if (strcmp(c,w) == 0)
        {
            return 1;
        }
    }
    return 0;
    ifile.close();
}

void repeat_list(char entered[])
{
    ofstream ofile("REPEATLIST.txt", ios::app | ios::out);
    if (!ofile)
    {
        cout << "System Error 001 ABORT ABORT ABORT ABORT ABORT";
        exit(0);
    }

    ofile << entered;
    ofile << ' ';

    ofile.close();

}

int check_repeat(char entered[])                                        // returns 1 if word is allowed
{
    ifstream ifile("REPEATLIST.txt", ios::in);

    char c[20];

    while(ifile)
    {
        ifile >> c;
        if (strcmp(c,entered) == 0)
        {
            return 0;
        }
    }
    return 1;

    ifile.close();
}


// ################################## GAME CODE ####################################

/*
	If word doesn't fit
	status = 1

	If there is a different letter in the area entered
	status = 2

	if the entered character would replace an already existing character
    status = 3

    word does not exist in the dictionary
    status = 4

*/


void scr_board :: display() //used after every input to show board
{
	system("cls");

	cout << "Use W A S D to move cursor. You can enter E whenever you wish to exit the game." << endl;

	cout << "----------------------------------------------" << endl;
	int i = 0 , j = 0;
	for (i=0 ; i<sizes ; i++)
	{
		cout << '|';
		for (j=0 ; j<sizes ; j++)
		{
			if (i != movecol || j != moverow)
			{
				cout << board[i][j]<< " |"; //
			}
			else
			{
				cout << board[i][j] << "<|"; //
			}
		}

		cout << "\t\t\t";

		switch(i)
		{
        case 3:
            cout << "Letter Point Values";
            break;
        case 5:
            cout << "A=1 B=3 C=3 D=2 E=1";
            break;
        case 6:
            cout << "F=4 G=2 H=4 I=1 J=8";
            break;
        case 7:
            cout << "K=5 L=4 M=3 N=1 O=1";
            break;
        case 8:
            cout << "P=3 Q=10 R=1 S=1 T=1";
            break;
        case 9:
            cout << "U=1 V=4 W=4 X=8 Y=4";
            break;
        case 10:
            cout << "Z=10";
            break;

		}

		cout << endl;
	}
	cout << "----------------------------------------------" << endl;

	status_print();

}

void scr_board :: status_print()
{
	cout << "User 1 =====> Score : " << player1 << endl;
	cout << "User 2 =====> Score : " << player2 << endl;
	if (status == 1)
	{
		cout << "Sorry, the word will not fit.";
		status = 0;
	}

	if (status == 2)
	{
		cout << "Sorry, there is already another letter here."<< endl;
		status = 0;
	}

	if (status == 3)
	{
		cout << "Your word does not overlap with a previously existing word!" << endl;
		status = 0;
	}

	if (status == 4)
    {
        cout << "Word does not exist in the dictionary..." << endl;
    }

    if (status == 5)
    {
        cout << "This word has already been used!" << endl;
    }


	//cout <<"The word entered is "<<the_word;
	//cout <<"The word scored is " <<p1.the_word;
	cout << "Enter e to exit. \n";
}


int scr_board :: enter_right(char word[]) //words entered to the right
{
    //checking if word is too big
	if (strlen(word) > (sizes - (moverow)))
	{
		status = 1;
		return 0;
	}

	//checking if word is inconsistent
    int c;
	for (c=0 ; c<strlen(word) ; c++)
	{
		if ((board[movecol][moverow + c] != word[c]) && (board[movecol][moverow + c] != ' ')
      && (board[movecol][moverow + c] != 'w') && (board[movecol][moverow + c] != 'l'))
		{
			status = 2;
			return 0;
		}
	}

	//checking for the word overlapping...

	int flag;
	flag = 0;

    if (tourner != 0)
    {
        for (c=0 ; c<strlen(word) ; c++)
        {
            if (board[movecol][moverow + c] == word[c])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            status = 3;
            return 0;
        }
    }

    if(tourner % 2 == 0)
        player1 += p1.score(direction);
    else
        player2 += p2.score(direction);
    ++tourner;



	for (int i = 0; i < strlen(word); i++)
	{
			board[movecol][moverow++] = toupper(word[i]);
	}
	moverow = 0;
	movecol = 0;
	return 0;
}

int scr_board :: enter_down(char word[]) //words entered downwards
{
    //checking if word is too big

	int i = 0;
	if (strlen(word) > (sizes - (movecol)))
	{
		status = 1;
		return 0;
	}

	//checking if word is inconsistent
    int c;
	for (c=0 ; c<strlen(word) ; c++)
	{
		if ((board[movecol + c][moverow] != word[c]) && (board[movecol + c][moverow] != ' ')
      && (board[movecol + c][moverow] != 'w') && (board[movecol + c][moverow] != 'l'))
		{
			status = 2;
			return 0;
		}
	}

	//checking for the word overlapping...
	int flag;
	flag = 0;

    if (tourner != 0)
    {
        for (c=0 ; c<strlen(word) ; c++)
        {
            if (board[movecol + c][moverow] == word[c])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            status = 3;
            return 0;
        }
    }

    if(tourner % 2 == 0)
        player1 += p1.score(direction);
    else
        player2 += p2.score(direction);
    ++tourner;



	for (i = 0; i < strlen(word); i++)
		board[movecol++][moverow] = toupper(word[i]);

	moverow = 0;
	movecol = 0;
	return 0;
}

int scr_board :: enter_word()                                       //takes in word
{
	cout <<"Enter the word: ";
	cin >> the_word;

	for (int x=0 ; x<strlen(the_word) ; x++)                        // converts to lowercase
    {
        the_word[x] = tolower(the_word[x]);
    }

    //checks if the word is a valid English word
	if (check(the_word) == 0)
    {
        status = 4;
        return 0;
    }


    if (check_repeat(the_word))
            repeat_list(the_word);

    else
        {
            status = 5;
            return 0;
        }

	int i;
	for (i=0 ; i< strlen(the_word) ; i++)
	{
		the_word[i] = toupper(the_word[i]);
	}

	switch (direction)
	{
		case 'd':
			enter_right(the_word);
			break;

		case 's':
			enter_down(the_word);
			break;
	}

	moverow = 0;
	movecol = 0;
}

void scr_board :: turn() //played after every word
{
	system("cls");

    cout <<" Do you wish to load saved game? [Y/N]"<<endl;
    cin >> newg;

    if (newg == 'y' || newg == 'Y')
    {
        game.save_game_read();
    }
    else
    {
        remove("REPEATLIST.txt");
        remove("SAVEDGAME.dat");
    }

    display();


	char inp_loop = 'd';

	while (inp_loop != 'e')
	{

	    status = 0;

		inp_loop = getch();

		switch(inp_loop)
		{
		case 'w':
			if (movecol > 0)
				--movecol;
				cout << "Use W A S D to move cursor." << endl;
				display();
			break;

		case 'a':
			if (moverow > 0)
				--moverow;
				cout << "Use W A S D to move cursor." << endl;
				display();
			break;

		case 's':
			if (movecol < (sizes-1))
				++movecol;
				cout << "Use W A S D to move cursor." << endl;
				display();
			break;

		case 'd':
			if (moverow < (sizes-1))
				++moverow;
				cout << "Use W A S D to move cursor." << endl;
				display();
			break;

		case '\n':
			break;

		case '\r':
		    // start from center
		    if (tourner == 0)
            {
                moverow = 7;
                movecol = 7;
                display();
            }
			cout << "Enter direction: D for right, S for down: ";

			do{
			direction = getch();
			} while (direction != 'd' && direction != 's');

			cout << endl;
			enter_word();

			display();
			break;

		case 'e':
		    system("cls");
			cout << "Do you wish to save the game? [Y/N]"<<endl;
			cin >> saveg;
			if (saveg == 'Y' || saveg == 'y')
            {
                save_game_write();
                cout <<"Game saved!"<<endl;
            }
            else
            {
                remove("REPEATLIST.txt");
            }

            exit(0);

			break;

		default:
			display();
		}

	}
}


void scr_board :: save_game_write()
{
    ofstream ofile("SAVEDGAME", ios::out|ios::binary);

    ofile.write((char*)this, sizeof(scr_board));

    ofile.close();
}

int scr_board :: save_game_read()
{
    ifstream ifile("SAVEDGAME", ios::in | ios::binary);

    if (!ifile)
    {
        cout <<"No saved game found..."<<endl;
        getch();
        return 0;
    }

    scr_board buffer;

    ifile.read((char*)&buffer, sizeof(scr_board));

    board_copy(buffer);

    ifile.close();
}




int main()
{
	// function for menu screen goes here
    menu();
	game.turn();
	getch();

	return 0;
}



