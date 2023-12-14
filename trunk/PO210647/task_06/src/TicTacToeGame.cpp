#include <iostream>
#include <vector>
#include <random>

void drawBoard(const std::vector<std::vector<char>>& board, const std::vector<std::vector<bool>>& winLines) {//1
    std::cout << " ";//1
    for (int i = 0; i < board.size(); ++i) {//1
        std::cout << " " << i + 1;//1
    }
    std::cout << std::endl;//1

    for (int i = 0; i < board.size(); ++i) {//1
        std::cout << i + 1 << " ";//1
        for (int j = 0; j < board[i].size(); ++j) {//1
            if (winLines[i][j]) {//1
                std::cout << "\x1B[32m" << board[i][j] << "\x1B[0m ";//1
            }//1
            else {//1
                std::cout << board[i][j] << " ";//1
            }//1
        }//1
        std::cout << std::endl;//1
    }//1
}//1

bool checkRowWin(const std::vector<std::vector<char>>& board, char symbol, int row, std::vector<std::vector<bool>>& winLines) {//1
    for (char cell : board[row]) {//1
        if (cell != symbol) {//1
            return false;//1
        }//1
    }//1
    for (auto&& winLineCell : winLines[row]) {//1
        winLineCell = true;//1
    }//1
    return true;//1
}//1

bool checkColWin(const std::vector<std::vector<char>>& board, char symbol, int col, std::vector<std::vector<bool>>& winLines) {//1
    for (const auto& row : board) {//1
        if (row[col] != symbol) {//1
            return false;//1
        }//1
    }//1

    for (auto& winLineRow : winLines) {//1
        winLineRow[col] = true;//1
    }//1
    return true;//1
}

bool checkMainDiagonalWin(const std::vector<std::vector<char>>& board, char symbol, std::vector<std::vector<bool>>& winLines) {//1
    for (int i = 0; i < board.size(); ++i) {//1
        if (board[i][i] != symbol) {//1
            return false;//1
        }//1
    }//1

    for (int i = 0; i < board.size(); ++i) {//1
        winLines[i][i] = true;//1
    }//1
    return true;//1
}

bool checkAntiDiagonalWin(const std::vector<std::vector<char>>& board, char symbol, std::vector<std::vector<bool>>& winLines) {//1
    for (int i = 0; i < board.size(); ++i) {//1
        if (board[i][board.size() - 1 - i] != symbol) {//1
            return false;//1
        }//1
    }//1

    for (int i = 0; i < board.size(); ++i) {//1
        winLines[i][board.size() - 1 - i] = true;//1
    }//1
    return true;//1
}//1

bool checkWin(const std::vector<std::vector<char>>& board, char symbol, std::vector<std::vector<bool>>& winLines) {//1

    for (int i = 0; i < board.size(); ++i) {//1
        if (checkRowWin(board, symbol, i, winLines) || checkColWin(board, symbol, i, winLines)) {//1
            return true;//1
        }//1
    }//1

    if (checkMainDiagonalWin(board, symbol, winLines) || checkAntiDiagonalWin(board, symbol, winLines)) {//1
        return true;//1
    }//1

    return false;//1
}

bool checkTie(const std::vector<std::vector<char>>& board) {//1
    for (const auto& row : board) {//1
        for (char cell : row) {//1
            if (cell == ' ') {//1
                return false;//1
            }//1
        }//1
    }//1
    return true;//1
}

void computerMove(std::vector<std::vector<char>>& board) {//1
    std::random_device rd;//1
    std::uniform_int_distribution<std::vector<char>::size_type> distribution(0, board.size() - 1);//1
    std::vector<char>::size_type row;//1
    std::vector<char>::size_type col;//1
    do {//1
        row = distribution(rd);//1
        col = distribution(rd);//1
    } while (board[row][col] != ' ');//1

    board[row][col] = 'O';//1
}

void playerTurn(std::vector<std::vector<char>>& board, int size, char playerSymbol, std::vector<std::vector<bool>>& winLines, int& currentPlayer, bool& gameIsOver) {//1
    std::cout << "Player's turn. Enter row and column (1-" << size << "): ";//1
    int row;//1
    int col;//1
    std::cin >> row >> col;//1
    --row;//1
    --col;//1

    if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != ' ') {//1
        std::cout << "Invalid move. Try again." << std::endl;//1
    }//1
    else {//1
        board[row][col] = playerSymbol;//1

        if (checkWin(board, playerSymbol, winLines)) {//1
            drawBoard(board, winLines);//1
            std::cout << "Congratulations! You win!" << std::endl;//1
            gameIsOver = true;//1
        }
        else {//1
            currentPlayer = 3 - currentPlayer;//1
        }//1
    }//1
}//1

void computerTurn(std::vector<std::vector<char>>& board, char computerSymbol, std::vector<std::vector<bool>>& winLines, int& currentPlayer, bool& gameIsOver) {//1
    std::cout << "Computer's turn..." << std::endl;//1
    computerMove(board);//1

    if (checkWin(board, computerSymbol, winLines)) {//1
        drawBoard(board, winLines);//1
        std::cout << "Computer wins! Better luck next time." << std::endl;//1
        gameIsOver = true;//1
    }//1
    else {//1
        currentPlayer = 3 - currentPlayer;//1
    }//1
}

int main() {//1
    int size;//1
    std::cout << "Enter the size of the board (e.g., 3 for a 3x3 board): ";//1
    std::cin >> size;//1

    std::vector<std::vector<char>> board(size, std::vector<char>(size, ' '));//1
    std::vector<std::vector<bool>> winLines(size, std::vector<bool>(size, false));//1

    int currentPlayer = 1;//1
    char playerSymbol;//1
    char computerSymbol;//1

    std::cout << "Enter X or O to choose your symbol: ";//1
    std::cin >> playerSymbol;//1

    if (playerSymbol == 'X' || playerSymbol == 'x') {//1
        computerSymbol = 'O';//1
    }//1
    else {//1
        playerSymbol = 'O';//1
        computerSymbol = 'X';//1
    }

    std::cout << "You are playing as " << playerSymbol << ". Let's start the game!" << std::endl;//1

    bool gameIsOver = false;//1

    while (!gameIsOver) {//1
        drawBoard(board, winLines);//1

        if (currentPlayer == 1) {//1
            playerTurn(board, size, playerSymbol, winLines, currentPlayer, gameIsOver);//1
        }//1
        else {//1
            computerTurn(board, computerSymbol, winLines, currentPlayer, gameIsOver);//1
        }//1

        if (checkTie(board)) {//1
            drawBoard(board, winLines);//1
            std::cout << "It's a tie! The game is over." << std::endl;//1
            gameIsOver = true;//1
        }//1
    }//1

    return 0;
}