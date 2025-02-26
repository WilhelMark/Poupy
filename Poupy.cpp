#include <iostream>
#include <vector>

// Константы для размеров пупырки
const int ROWS = 12;
const int COLS = 12;

// Функция для инициализации пупырки в целом состоянии
void initializeBubbleWrap(std::vector<std::vector<bool>>& bubbleWrap) {
    // Инициализируем все пузыри как целые
    for (int i = 0; i < ROWS; ++i) {
        bubbleWrap[i].resize(COLS, true);
    }
}

// Функция для отображения текущего состояния пупырки
void displayBubbleWrap(const std::vector<std::vector<bool>>& bubbleWrap) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << (bubbleWrap[i][j] ? "o" : "x") << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для лопания пузырей в заданном регионе
void popBubbles(std::vector<std::vector<bool>>& bubbleWrap, int startRow, int startCol, int endRow, int endCol) {
    // Проверка на валидность координат
    if (startRow < 0 || startRow > endRow || endRow >= ROWS || startCol < 0 || startCol > endCol || endCol >= COLS) {
        std::cerr << "Invalid region coordinates." << std::endl;
        return;
    }

    // Лопание пузырей в регионе
    for (int i = startRow; i <= endRow; ++i) {
        for (int j = startCol; j <= endCol; ++j) {
            if (bubbleWrap[i][j]) {
                bubbleWrap[i][j] = false; // Лопаем пузырь
                std::cout << "Pop!" << std::endl;
            }
        }
    }
}

// Основная функция программы
int main() {
    std::vector<std::vector<bool>> bubbleWrap(ROWS);

    // Инициализация пупырки
    initializeBubbleWrap(bubbleWrap);

    while (true) {
        // Отображение текущего состояния пупырки
        std::cout << "Current state of bubble wrap:" << std::endl;
        displayBubbleWrap(bubbleWrap);

        // Ввод координат региона для лопания
        int startRow, startCol, endRow, endCol;
        std::cout << "Enter start row, start column, end row, end column: ";
        std::cin >> startRow >> startCol >> endRow >> endCol;

        // Лопание пузырей в регионе
        popBubbles(bubbleWrap, startRow, startCol, endRow, endCol);

        // Проверка на окончание программы
        bool allPopped = true;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (bubbleWrap[i][j]) {
                    allPopped = false;
                    break;
                }
            }
            if (!allPopped) break;
        }

        if (allPopped) {
            std::cout << "All bubbles popped. Program finished." << std::endl;
            break;
        }
    }

    return 0;
}
