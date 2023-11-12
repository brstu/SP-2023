#include <iostream>
#include <vector>
#include <random>

void drawBoard(const std::vector<std::vector<char>>& board, const std::vector<std::vector<bool>>& winLines) {
    std::cout << " ";
    for (int i = 0; i < board.size(); ++i) {
        std::cout << " " << i + 1;
    }
    std::cout << std::endl;

    for (int i = 0; i < board.size(); ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < board[i].size(); ++j) {
            if (winLines[i][j]) {
                std::cout << "\x1B[32m" << board[i][j] << "\x1B[0m ";
            }
            else {
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool checkRowWin(const std::vector<std::vector<char>>& board, char symbol, int row, std::vector<std::vector<bool>>& winLines) {
    for (char cell : board[row]) {
        if (cell != symbol) {
            return false;
        }
    }
    for (auto&& winLineCell : winLines[row]) {
        winLineCell = true;
    }
    return true;
}

bool checkColWin(const std::vector<std::vector<char>>& board, char symbol, int col, std::vector<std::vector<bool>>& winLines) {
    for (const auto& row : board) {
        if (row[col] != symbol) {
            return false;
        }
    }

    for (auto& winLineRow : winLines) {
        winLineRow[col] = true;
    }
    return true;
}

bool checkMainDiagonalWin(const std::vector<std::vector<char>>& board, char symbol, std::vector<std::vector<bool>>& winLines) {
    for (int i = 0; i < board.size(); ++i) {
        if (board[i][i] != symbol) {
            return false;
        }
    }

    for (int i = 0; i < board.size(); ++i) {
        winLines[i][i] = true;
    }
    return true;
}

bool checkAntiDiagonalWin(const std::vector<std::vector<char>>& board, char symbol, std::vector<std::vector<bool>>& winLines) {
    for (int i = 0; i < board.size(); ++i) {
        if (board[i][board.size() - 1 - i] != symbol) {
            return false;
        }
    }

    for (int i = 0; i < board.size(); ++i) {
        winLines[i][board.size() - 1 - i] = true;
    }
    return true;
}

bool checkWin(const std::vector<std::vector<char>>& board, char symbol, std::vector<std::vector<bool>>& winLines) {
    for (int i = 0; i < board.size(); ++i) {
        if (checkRowWin(board, symbol, i, winLines) || checkColWin(board, symbol, i, winLines)) {
            return true;
        }
    }

    if (checkMainDiagonalWin(board, symbol, winLines) || checkAntiDiagonalWin(board, symbol, winLines)) {
        return true;
    }

    return false;
}

bool checkTie(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

void computerMove(std::vector<std::vector<char>>& board, std::mt19937& gen) {
    std::uniform_int_distribution<std::vector<char>::size_type> distribution(0, board.size() - 1);
    std::vector<char>::size_type row;
    std::vector<char>::size_type col;
    do {
        row = distribution(gen);
        col = distribution(gen);
    } while (board[row][col] != ' ');

    board[row][col] = 'O';
}

void playerTurn(std::vector<std::vector<char>>& board, int size, char playerSymbol, std::vector<std::vector<bool>>& winLines, int& currentPlayer, bool& gameIsOver) {
    std::cout << "Player's turn. Enter row and column (1-" << size << "): ";
    int row;
    int col;
    std::cin >> row >> col;
    --row;
    --col;

    if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != ' ') {
        std::cout << "Invalid move. Try again." << std::endl;
    }
    else {
        board[row][col] = playerSymbol;

        if (checkWin(board, playerSymbol, winLines)) {
            drawBoard(board, winLines);
            std::cout << "Congratulations! You win!" << std::endl;
            gameIsOver = true;
        }
        else {
            currentPlayer = 3 - currentPlayer;
        }
    }
}

void computerTurn(std::vector<std::vector<char>>& board, char computerSymbol, std::vector<std::vector<bool>>& winLines, int& currentPlayer, bool& gameIsOver, std::mt19937& gen) {
    std::cout << "Computer's turn..." << std::endl;
    computerMove(board, gen);

    if (checkWin(board, computerSymbol, winLines)) {
        drawBoard(board, winLines);
        std::cout << "Computer wins! Better luck next time." << std::endl;
        gameIsOver = true;
    }
    else {
        currentPlayer = 3 - currentPlayer;
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    int size;
    std::cout << "Enter the size of the board (e.g., 3 for a 3x3 board): ";
    std::cin >> size;

    std::vector<std::vector<char>> board(size, std::vector<char>(size, ' '));
    std::vector<std::vector<bool>> winLines(size, std::vector<bool>(size, false));

    int currentPlayer = 1;
    char playerSymbol;
    char computerSymbol;

    std::cout << "Enter X or O to choose your symbol: ";
    std::cin >> playerSymbol;

    if (playerSymbol == 'X' || playerSymbol == 'x') {
        computerSymbol = 'O';
    }
    else {
        playerSymbol = 'O';
        computerSymbol = 'X';
    }

    std::cout << "You are playing as " << playerSymbol << ". Let's start the game!" << std::endl;

    bool gameIsOver = false;

    while (!gameIsOver) {
        drawBoard(board, winLines);

        if (currentPlayer == 1) {
            playerTurn(board, size, playerSymbol, winLines, currentPlayer, gameIsOver);
        }
        else {
            computerTurn(board, computerSymbol, winLines, currentPlayer, gameIsOver, gen);
        }

        if (checkTie(board)) {
            drawBoard(board, winLines);
            std::cout << "It's a tie! The game is over." << std::endl;
            gameIsOver = true;
        }
    }

    return 0;
}