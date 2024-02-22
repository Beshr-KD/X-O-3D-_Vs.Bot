#include <iostream>
#include <map>
#include <queue>
using namespace std;
char player = 'O'; 
void print(char board[3][3][3]);
void play(char board[3][3][3]);
bool checkWin(char board[3][3][3]);
void print_winners(queue<string> q);
void O(char board[3][3][3]);
int main()
{
    map<string,int> ps;
    queue<string> q;
    cout << "\t\t\t ~~~ Welcome to the [ X & O ] 3D game ~~~ \n\n\n   ~ Enter number of players (*_*) : ";
	int num_player;
	cin >> num_player;
	for (int i = 0 ; i < num_player ; i++)
    {
        system("cls");
        cout << "~ player [" << i+1 << "] :\n  ~ Enter your name : ";
        string name;
        cin >> name;
        ps[name] = 0;
        for(int j = 0 ; j < 3 ; j++)
        {
            system("cls");
            char board [3][3][3] = { {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}, {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}, {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}};
            cout << "\t\t ~~~   ROUND [" << j+1 << "]  ~~~ \n\n Press any key to start the game : ";
            char a;
            cin >> a;
            print(board);
            for (int k = 0 ; k < 27 ; k++)
            {
                play(board);
                if (checkWin(board))
                {
                    if(player == 'X')
                        ps[name]++;
                    cout << player << " is the winner :) . \n ~ Press any key to move to next. :) . ";
                    break;
                }
                else if(k == 26)
                    cout << "\n\t ): ~~ tie ~~ :( . \n ~ Press any key to move to next. :) . ";
            }
            cin >> a;
        }
        if(ps[name] >= 2)
            q.push(name);
    }
    print_winners(q);
    return 0;
}
void print(char board[3][3][3])
{
    system("cls");
    for (int i = 0 ; i < 3 ; i++)
    {
        cout << "\n\t  |~~  Board [ " << i+1 << " ]  ~~| \n\t  _____________________\n\n\t    || C:1 || C:2 || C:3 | " << "\n\t__________________________\n\n";
        for (int j = 0 ; j < 3 ; j++)
        {
            cout << " \tR:" << j+1 << " |";
            for (int k = 0 ; k < 3 ; k++)
                cout << "|  " << board[i][j][k] << "  |";
            cout << "\n\t__________________________\n\n";
        }
    }
}
void play(char board[3][3][3])
{
    if(player == 'O')
    {
        player = 'X';
        cout << "Player [X] : \n\t Enter the (Board number & Row number & Column number) : ";
        int b,r,c;
        cin >> b >> r >> c;
        while(b > 3 || r > 3 || c > 3 || b < 1 || r < 1 || c < 1 || board[b-1][r-1][c-1] != ' ')
        {
            cout << " ~ Sorry, The wrong board,row,or column number (must be between 1 and 3) :(\n Enter the (Board number & Row number & Column number) : ";
            cin >> b >> r >> c;
        }
        board[b-1][r-1][c-1] = 'X';
    }
    else if(player == 'X')
        O(board);
    print(board);
}
bool checkWin(char board[3][3][3])
{
    //أقطار المكعب
    if ( (board[0][0][0] == player && board[1][1][1] == player && board[2][2][2] == player)
        || (board[0][0][2] == player && board[1][1][1] == player && board[2][2][0] == player)
        || (board[0][2][0] == player && board[1][1][1] == player && board[2][0][2] == player)
        || (board[0][2][2] == player && board[1][1][1] == player && board[2][0][0] == player) )
            return true;
    // أقطار الوجوه و الطبقات
    for (int i = 0 ; i < 3 ; i++)
        if ( (board[i][0][0] == player && board[i][1][1] == player && board[i][2][2] == player)
            || (board[i][0][2] == player && board[i][1][1] == player && board[i][2][0] == player)
            || (board[0][i][0] == player && board[1][i][1] == player && board[2][i][2] == player)
            || (board[0][i][2] == player && board[1][i][1] == player && board[2][i][0] == player)
            || (board[0][0][i] == player && board[1][1][i] == player && board[2][2][i] == player)
            || (board[0][2][i] == player && board[1][1][i] == player && board[2][0][i] == player) )
                return true;
    // أسطر و أعمدة
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if ( (board[i][j][0] == player && board[i][j][1] == player && board[i][j][2] == player)
                ||(board[i][0][j] == player && board[i][1][j] == player && board[i][2][j] == player)
                ||(board[0][i][j] == player && board[1][i][j] == player && board[2][i][j] == player) )
                    return true;
    return false;
}
void print_winners(queue<string> q) // طباعةالفائزين
{
    system("cls");
    cout << "\n ~ The Winners : \n";
    while(!q.empty())
    {
        cout << "\t- " << q.front() << endl;
        q.pop();
    }
}
void O(char board[3][3][3])
{
    player = 'O';
    for(int i = 0 ; i < 3 ; i++) // فوز O
        for(int j = 0 ; j < 3 ; j++)
            for(int k = 0 ; k < 3 ; k++)
                if(board[i][j][k] == ' ')
                {
                    board[i][j][k] = 'O';
                    if(checkWin(board))
                        return;
                    board[i][j][k] = ' ';
                }
    for(int i = 0 ; i < 3 ; i++) // منع فوز X
        for(int j = 0 ; j < 3 ; j++)
            for(int k = 0 ; k < 3 ; k++)
                if(board[i][j][k] == ' ')
                {
                    player = 'X';
                    board[i][j][k] = 'X';
                    if(checkWin(board))
                    {
                        player = 'O';
                        board[i][j][k] = 'O';
                        return;
                    }
                    board[i][j][k] = ' ';
                    player = 'O';
                }
    if(board[1][1][1] == ' ') // مركزالمكعب
        {
            board[1][1][1] = 'O';
            return;
        }
    for (int i = 0 ; i < 3 ; i++) // مراكزالوجوه
        if(board[i][1][1] == ' ' && i != 1) // Front & Back
        {
            board[i][1][1] = 'O';
            return;
        }
        else if(board[1][1][i] == ' ' && i!=1) // Left & Right
        {
            board[1][1][i] = 'O';
            return;
        }
        else if(board[1][i][1] == ' ' && i!=1) // Up & Down
        {
            board[1][i][1] = 'O';
            return;
        }
    for(int i = 0 ; i < 3 ; i++) // الزوايا
        for(int j = 0 ; j < 3 ; j++)
            for(int k = 0 ; k < 3 ; k++)
                if(k != 1 && j != 1 && board[i][j][k] == ' ')
                {
                    board[i][j][k] = 'O';
                    return;
                }
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < 3 ; j++)
            for(int k = 0 ; k < 3 ; k++)
                if(board[i][j][k] == ' ')
                {
                    board[i][j][k] = 'O';
                    return;
                }
}
