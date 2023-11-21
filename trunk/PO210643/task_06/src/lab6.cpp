#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Windows.h"
#include <map>

using namespace std;

const int ROWS = 12;
const int COLS = 12;
const char SHIP = 'S';
const char MISSED = '*';
const char KILLED = 'X';


int iCoordArray[10] = { 0 };
int jCoordArray[10] = { 0 };

int fourDecked;
int threeDeckeed;

int twoDecked;

int oneDecked;


char** grid1 = new char* [12];
int player1Score=0;
char** grid1ShotBoard = new char* [12];


std::map<char, char> ships = {
    { 1, 4 },
    { 2, 3 },
    { 3, 2 },
    {4,1},
};

char** grid2 = new char* [12];
int player2Score=0;
char** grid2ShotBoard = new char* [12];

void fillCoordArray() {
    for (int i = 0; i < 10; i++) {
        iCoordArray[i] = i + 1;
        jCoordArray[i] = i + 1;
    }


}


int checkPosition(int i, int j, int sizeOfShip, int orientation, char** grid)
{

    if (orientation != 120)
    {
        if (i + sizeOfShip-1 > ROWS - 2) {
            return false;
        }
        else {

            for (int k = 0; k < sizeOfShip; k++)
            {
                if (grid[i + k][j] == 'S' || grid[i + k - 1][j] == 'S' || grid[i + k + 1][j] == 'S' ||
                    grid[i + k - 1][j - 1] == 'S' || grid[i + k][j - 1] == 'S' || grid[i + k + 1][j - 1] == 'S' ||
                    grid[i + k - 1][j + 1] == 'S' || grid[i + k][j + 1] == 'S' || grid[i + k + 1][j + 1] == 'S')

                {
                    return false;
                }
            }
        }

    }


    else
    {
        if (j + sizeOfShip-1 > COLS - 2) {
            return false;
        }
        else {
            for (int k = 0; k < sizeOfShip; k++)
            {
                if (grid[i][j + k] == 'S' || grid[i - 1][j + k] == 'S' || grid[i + 1][j + k] == 'S' ||
                    grid[i - 1][j + k - 1] == 'S' || grid[i][j + k - 1] == 'S' || grid[i + 1][j + k - 1] == 'S' ||
                    grid[i - 1][j + k + 1] == 'S' || grid[i][j + k + 1] == 'S' || grid[i + 1][j + k + 1] == 'S')
                {
                    return false;
                }
            }
        }



        }







    return true;

}

    bool checkAvailableShip(int deck) {

        bool all = false;
        switch (deck)
        {
        case 1:
            if (oneDecked != 0) {
                all = true;
            }
            else {
                cout << "Used up";
                Sleep(3000);
            }
            break;
        case 2:
            if (twoDecked != 0) {
                all = true;
            }
            else {
                cout << "Used up";
                Sleep(3000);

            }
            break;
        case 3:
            if (threeDeckeed != 0) {
                all = true;
            }
            else {
                cout << "Used up";
                Sleep(3000);

            }
            break;
        case 4:
            if (fourDecked != 0) {
                all = true;
            }
            else {
                cout << "Used up";
                Sleep(3000);

            }
            break;
        default:
            break;
        }

    return all;

}
void initializeGrid(char **newGrid) {
    for (int i = 0; i < ROWS; i++)
    {
        newGrid[i] = new char[12];

    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            newGrid[i][j] = '~';
        }
    }
}
bool checkNumberShips() {
    bool all = false;
    if (fourDecked == 0 && threeDeckeed == 0 && twoDecked == 0 && oneDecked == 0) {
        return true;
    }

    return all;
}

void displayMove(int oldcol,int oldrow,int newcol,int newrow, char **board,bool first=false) {
    if (board[newrow][newcol] != 'S' && board[newrow][newcol] != 'X'&& board[newrow][newcol] != '*') {
        board[newrow][newcol] = '+';
        if (!first && board[oldrow][oldcol] != 'S' && board[oldrow][oldcol] != 'X' && board[oldrow][oldcol] != '*') {
            board[oldrow][oldcol] = '~';

        }
    }
    else if ((board[newrow][newcol] == 'X' || board[newrow][newcol] == '*' || board[newrow][newcol] == 'S')&&(board[oldrow][oldcol] == '+')){
        board[oldrow][oldcol] = '~';

    }




}

void displayGrid(char **grid){
    system("cls");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    cout << endl;
}

void setShip(int row, int col,char** grid,int deck,int orientation=120) {
    if (orientation == 120) {
        for (int i = 0; i < deck; i++)
        {
            grid[row][col+i] = SHIP;

        }
    }
    else {
        for (int i = 0; i < deck; i++)
        {
            grid[row+i][col] = SHIP;

        }
    }
}


void placeShips(char **grid, bool player1Ships) {
    if (!player1Ships) {
        fourDecked = 1;
        threeDeckeed = 2;
        twoDecked = 3;
        oneDecked = 4;
    }
    char key;
    int c;
    int orientation;
    int oldRow = 1;
    int oldCol = 1;
    int newRow=1;
    int newCol=1;

    do
    {

        c = 0;
        displayMove(oldCol, oldRow, newCol, newRow, grid,true);
        displayGrid(grid);
        switch ((c = _getch())) {
        case 49:
            if (checkNumberShips()) {
                cout << "Your ships are set!" << endl;
                Sleep(2000);
                return;
           }
           if (checkAvailableShip(1)) {
               if (checkPosition(newRow, newCol, 2, 120, grid)) {
                   oneDecked--;
                   setShip(newRow, newCol, grid, 1,120);
                   displayGrid(grid);
               }

            }

            break;
        case 50:
            if (checkNumberShips()) {
                cout << "Your ships are set!" << endl;
                Sleep(2000);
                return;
            }

            if (checkAvailableShip(2)) {

                orientation = _getch();
                if (checkPosition(newRow, newCol, 2, orientation, grid)) {
                    twoDecked--;
                    setShip(newRow, newCol, grid, 2, orientation);
                    displayGrid(grid);
                }



            }


            break;
        case 51:
            if (checkNumberShips()){
                cout << "Your ships are set!" << endl;
                Sleep(2000);
                return;
            }

            if (checkAvailableShip(3)) {
                orientation = _getch();
                if (checkPosition(newRow, newCol, 3, orientation, grid)) {
                    threeDeckeed--;
                    setShip(newRow, newCol, grid, 3, orientation);
                    displayGrid(grid);
                }
            }



            break;
        case 52:
            if (checkNumberShips()) {
                cout << "Your ships are set!" << endl;
                Sleep(2000);
                return;
            }
            if (checkAvailableShip(4)) {
                orientation = _getch();
                if (checkPosition(newRow, newCol, 4, orientation, grid)) {
                    fourDecked--;
                    setShip(newRow, newCol, grid, 4, orientation);
                    displayGrid(grid);
                }

            }


            break;


        case 72:
            if (oldRow > 1) {
                oldCol = newCol;
                oldRow = newRow;
                newRow = oldRow-1;
                displayMove(oldCol, oldRow, newCol, newRow,grid);
                displayGrid(grid);

            }

            break;
        case 80:
            if (oldRow < ROWS - 2) {
                oldCol = newCol;
                oldRow = newRow;
                newRow = oldRow +1;
                displayMove(oldCol, oldRow, newCol, newRow,grid);
                displayGrid(grid);

            }
            break;
        case 75:
            if (oldCol > 1) {
                oldCol = newCol;
                oldRow = newRow;
                newCol = oldCol - 1;


                displayMove(oldCol,oldRow, newCol,newRow, grid);
                displayGrid(grid);

            }
            break;
        case 77:
            if (oldCol < COLS - 2) {
                oldCol = newCol;
                oldRow = newRow;
                newCol = oldCol + 1;
                displayMove(oldCol, oldRow, newCol, newRow, grid);
                displayGrid(grid);


            }
            break;

        default:
            break;
        }


    } while (c != 27);
}
bool makeShot(int row, int col, char **gridHidden, char **gridEnemy, int& playerScore) {
    if (gridEnemy[row][col] == SHIP) {
        gridHidden[row][col] = KILLED;
        playerScore += 10;
        return true;


    }
    else {
        gridHidden[row][col] = MISSED;
        return false;
    }
}

bool makeShotComputer(int row, int col, char** gridEnemy, int& playerScore) {
    cout << gridEnemy[row][col] << endl;
    if (gridEnemy[row][col] == SHIP) {
        gridEnemy[row][col] = KILLED;
        playerScore += 10;
        return true;


    }
    else {
        gridEnemy[row][col] = MISSED;
        return false;
    }
}
void shootComputer(char** gridEnemy, int& playerScore) {
    bool yes = true;
    int x;
    int y;

    do {
            int x, y;

            x = rand() % 10+1;
            y = rand() % 10+1;

        yes = makeShotComputer(x, y, gridEnemy, playerScore);
        displayGrid(gridEnemy);
        Sleep(3000);

    } while (yes);
}
bool checkEndofGame(int score) {
    if (score == 200) {
        cout << "End of game"<<endl;
        Sleep(3000);

        if (player1Score == 200) {
            cout << "Player 1 has won!" << endl;
            Sleep(3000);

        }
        else {
            cout << "Player 2 has won!" << endl;
            Sleep(3000);



        }
        return true;
    }
    return false;
}


void shoot(char **gridHidden,char **gridEnemy,int& playerScore) {
    char key;
    int c;
    int orientation;
    int oldRow = 1;
    int oldCol = 1;
    int newRow = 1;
    int newCol = 1;
    bool yes = true;
    do
    {
        c = 0;
        displayMove(oldCol, oldRow, newCol, newRow, gridHidden, true);
        displayGrid(gridHidden);
        switch ((c = _getch())) {
        case 72:
            if (oldRow > 1) {
                oldCol = newCol;
                oldRow = newRow;
                newRow = oldRow - 1;
                displayMove(oldCol, oldRow, newCol, newRow, gridHidden);
                displayGrid(gridHidden);

            }

            break;
        case 80:
            if (oldRow < ROWS - 2) {
                oldCol = newCol;
                oldRow = newRow;
                newRow = oldRow + 1;
                displayMove(oldCol, oldRow, newCol, newRow, gridHidden);
                displayGrid(gridHidden);

            }
            break;
        case 75:
            if (oldCol > 1) {
                oldCol = newCol;
                oldRow = newRow;
                newCol = oldCol - 1;


                displayMove(oldCol, oldRow, newCol, newRow, gridHidden);
                displayGrid(gridHidden);

            }
            break;
        case 77:
            if (oldCol < COLS - 2) {
                oldCol = newCol;
                oldRow = newRow;
                newCol = oldCol + 1;
                displayMove(oldCol, oldRow, newCol, newRow, gridHidden);
                displayGrid(gridHidden);


            }
            break;

        case 13:
            yes = makeShot(newRow, newCol, gridHidden,gridEnemy,playerScore);
            displayGrid(gridHidden);
            break;
        default:
            break;
        }

    } while (yes);
}
int deleteElement(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            break;
    if (i < n)
    {
        n = n - 1;
        for (int j = i; j < n; j++)
            arr[j] = arr[j + 1];
    }

    return n;
}
bool placeShipsAI(char** grid) {

    while (fourDecked != 0) {
        int r = rand() % 1;
        int orientation = 119;
        if (r == 0) {
            orientation = 120;
        }
        int iRandom = rand() % size(iCoordArray);
        int jRandom = rand() % size(jCoordArray);

        int nx = sizeof(iCoordArray)/sizeof(iCoordArray[0]);
        int ny = sizeof(jCoordArray) / sizeof(jCoordArray[0]);

       int i = iCoordArray[iRandom];
        int j = jCoordArray[jRandom];

        if (checkPosition(i, j, 4, orientation, grid)) {
            setShip(i, j, grid, 4, orientation);
            nx = deleteElement(iCoordArray, nx, iCoordArray[iRandom]);
            ny = deleteElement(jCoordArray, ny, jCoordArray[jRandom]);
            fourDecked--;
            displayGrid(grid);
        }

    }
    while (threeDeckeed != 0) {
        int r = rand() % 1;
        int orientation = 119;
        if (r == 0) {
            orientation = 120;
        }
        int iRandom = rand() % size(iCoordArray);
        int jRandom = rand() % size(jCoordArray);


        int nx = sizeof(iCoordArray) / sizeof(iCoordArray[0]);
        int ny = sizeof(jCoordArray) / sizeof(jCoordArray[0]);


        int i = iCoordArray[iRandom];
        int j = jCoordArray[jRandom];
        if (checkPosition(i, j, 3, orientation, grid)) {
            setShip(i, j, grid, 3, orientation);
            nx = deleteElement(iCoordArray, nx, iCoordArray[iRandom]);
            ny = deleteElement(jCoordArray, ny, jCoordArray[jRandom]);
            threeDeckeed--;
            displayGrid(grid);

        }
    }
    while (twoDecked != 0) {
        int r = rand() % 1;
        int orientation = 119;
        if (r == 0) {
            orientation = 120;
        }
        int iRandom = rand() % size(iCoordArray);
        int jRandom = rand() % size(jCoordArray);

        int nx = sizeof(iCoordArray) / sizeof(iCoordArray[0]);
        int ny = sizeof(jCoordArray) / sizeof(jCoordArray[0]);

        int i = iCoordArray[iRandom];
        int j = jCoordArray[jRandom];
        if (checkPosition(i, j, 2, orientation, grid)) {
            setShip(i, j, grid, 2, orientation);
            nx = deleteElement(iCoordArray, nx, iCoordArray[iRandom]);
            ny = deleteElement(jCoordArray, ny, jCoordArray[jRandom]);
            twoDecked--;
            displayGrid(grid);

        }
    }
    while (oneDecked != 0) {
        int r = rand() % 1;
        int orientation = 119;
        if (r == 0) {
            orientation = 120;
        }
        int iRandom = rand() % size(iCoordArray);
        int jRandom = rand() % size(jCoordArray);

        int nx = sizeof(iCoordArray) / sizeof(iCoordArray[0]);
        int ny = sizeof(jCoordArray) / sizeof(jCoordArray[0]);
        int i = iCoordArray[iRandom];
        int j = jCoordArray[jRandom];
        if (checkPosition(i, j, 1, orientation, grid)) {
            setShip(i, j, grid, 1, orientation);
            nx = deleteElement(iCoordArray, nx, iCoordArray[iRandom]);
            ny = deleteElement(jCoordArray, ny, jCoordArray[jRandom]);
            oneDecked--;
            displayGrid(grid);

        }
    }
    if (fourDecked == 0 && threeDeckeed == 0 && twoDecked == 0 && oneDecked == 0) {
        return true;
    }
    else {
        return false;
    }




}

int main() {
    bool end = false;
    bool player1Turn = true;
    bool player1Ships = true;

    while (1) {
        cout << "1)Play against computer\n2)Play against opponent\n";

        player1Ships = true;
        fourDecked = 1;
        threeDeckeed = 2;
        twoDecked = 3;
        oneDecked = 4;

        int option;
        cin >> option;
        switch (option)
        {
        case 1:

            cout << "Set Yoor Ships! Player 1 Turn!" << endl;
            Sleep(3000);

            initializeGrid(grid1);
            initializeGrid(grid1ShotBoard);

            displayGrid(grid1);

            placeShips(grid1, player1Ships);

            cout << "Computer Turn!" << endl;
            Sleep(3000);
            fillCoordArray();

            initializeGrid(grid2);
            initializeGrid(grid2ShotBoard);
            fourDecked = 1;
            threeDeckeed = 2;
            twoDecked = 3;
            oneDecked = 4;
            while (fourDecked != 0 && threeDeckeed != 0 && twoDecked != 0 && oneDecked != 0) {
                placeShipsAI(grid2);
            }
            if (placeShipsAI) {
                displayGrid(grid2);
                Sleep(3000);


            }
            cout << "Game is starting!" << endl;

            while (!end) {
                if (player1Turn) {

                    cout << "Player 1 Turn!" << endl;

                    shoot(grid2ShotBoard, grid2, player1Score);
                    Sleep(3000);
                    end = checkEndofGame(player1Score);
                    if (end) {
                        break;
                    }

                    player1Turn = false;
                }


                else {
                    cout << "Computer Turn!" << endl;

                    shootComputer(grid1, player2Score);

                    end = checkEndofGame(player2Score);
                    if (end) {
                        break;
                    }
                    player1Turn = true;
                }
            }
        case 2:
            cout << "Set Yoor Ships! Player 1 Turn!" << endl;
            Sleep(3000);

                initializeGrid(grid1);
                initializeGrid(grid1ShotBoard);

                displayGrid(grid1);
                placeShips(grid1, player1Ships);

                cout << "Player 2 Turn!" << endl;
                Sleep(3000);

                player1Ships = false;
                initializeGrid(grid2);
                initializeGrid(grid2ShotBoard);
                displayGrid(grid2);
                placeShips(grid2,player1Ships);

            cout << "Game is starting!" << endl;
            Sleep(3000);


            while (!end) {
                if (player1Turn) {

                    cout << "Player 1 Turn!" << endl;
                    Sleep(3000);


                    displayGrid(grid2ShotBoard );
                    shoot(grid2ShotBoard,grid2,player1Score);
                    end = checkEndofGame(player1Score);
                    if (end) {
                        break;
                    }

                    player1Turn = false;
                }


                else {

                    cout << "Player 2 Turn!" << endl;
                    Sleep(3000);


                    displayGrid(grid1ShotBoard);
                    shoot(grid1ShotBoard,grid1,player2Score);
                    end = checkEndofGame(player2Score);
                    if (end) {
                        break;
                    }
                    player1Turn  =true;
                }

            }




        default:
            break;
        }


    }

    return 0;
}
