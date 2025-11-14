#include <UnitTest++/UnitTest++.h>
#include "game.h"
#include <vector>
#include <stdexcept>
#include <set>
#include <iostream>

std::string capture_print(const Game& g) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    g.display();
    std::cout.rdbuf(old);
    return buffer.str();
}

// Тест конструктора по умолчанию
TEST(Default_Constructor) {
    Game g;
    CHECK_EQUAL(4, g.get_size());
    CHECK_EQUAL(0, g[16]); // Последний элемент — 0
    CHECK(g.is_solved());  // Игровое поле в решённом состоянии
}

// Тест кастомного конструктора — корректная доска
TEST(Custom_Constructor_Valid) {
    std::vector<std::vector<int>> board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,0}
    };
    Game g(board);
    CHECK(g.is_solved());
    CHECK_EQUAL(3, g.get_empty_x());
    CHECK_EQUAL(3, g.get_empty_y());
}

// Тест кастомного конструктора — неверный размер
TEST(Custom_Constructor_Invalid_Size) {
    std::vector<std::vector<int>> board = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    CHECK_THROW(Game g(board), std::invalid_argument);
}

// Тест кастомного конструктора — нет пустой клетки
TEST(Custom_Constructor_No_Empty_Cell) {
    std::vector<std::vector<int>> board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16} // Нет 0
    };
    CHECK_THROW(Game g(board), std::invalid_argument);
}

// Тест is_solved — решено
TEST(Is_Solved_True) {
    std::vector<std::vector<int>> board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,0}
    };
    Game g(board);
    CHECK(g.is_solved());
}

// Тест is_solved — не решено
TEST(Is_Solved_False) {
    std::vector<std::vector<int>> board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,15,14,0}
    };
    Game g(board);
    CHECK(!g.is_solved());
}

// Тест count_inversions
TEST(Count_Inversions) {
    std::vector<std::vector<int>> board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,15,14,0}
    };
    Game g(board);
    CHECK_EQUAL(1, g.count_inversions());
}

// Тест is_solvable — решаемая доска (решённое состояние)
TEST(Is_Solvable_True) {
    std::vector<std::vector<int>> board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,0}
    };
    Game g(board);
    CHECK(g.is_solvable());
}

// Тест is_solvable — нерешаемая доска
TEST(Is_Solvable_False) {
    // Этот пример заведомо нерешаем: одна инверсия, пустая клетка в последней строке
    // inversions = 1, empty_row_from_bottom = 1, сумма = 2 (чётная) → не решаема
    std::vector<std::vector<int>> unsolvable = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,15,14,0}
    };
    Game g(unsolvable);
    CHECK(!g.is_solvable());
}

// Тест is_valid_move — корректный ход
TEST(Is_Valid_Move_True) {
    Game g;
    // Пустая клетка в (3,3). Допустимые соседи: (2,3) и (3,2)
    CHECK(g.is_valid_move(2, 3)); // 12
    CHECK(g.is_valid_move(3, 2)); // 15
}

// Тест is_valid_move — некорректный ход
TEST(Is_Valid_Move_False) {
    Game g;
    CHECK(!g.is_valid_move(0, 0)); // 1 — далеко
    CHECK(!g.is_valid_move(3, 3)); // сама пустая клетка — недопустимо
    CHECK(!g.is_valid_move(-1, 0)); // отрицательные координаты
    CHECK(!g.is_valid_move(4, 0));  // за пределами доски
}

// Тест move — успешный ход
TEST(Move_Valid) {
    Game g;
    CHECK(g.move(15)); // двигаем 15 в пустую клетку (3,3)
    // Теперь:
    // - пустая клетка в (3,2)
    // - 15 в (3,3)
    CHECK_EQUAL(3, g.get_empty_x());
    CHECK_EQUAL(2, g.get_empty_y());
    CHECK_EQUAL(15, g.get_board()[3][3]);
    CHECK_EQUAL(0, g.get_board()[3][2]);
}

// Тест move — недопустимый номер плитки
TEST(Move_Invalid_Tile_Value) {
    Game g;
    CHECK_THROW(g.move(0), std::invalid_argument);
    CHECK_THROW(g.move(16), std::invalid_argument);
    CHECK_THROW(g.move(-5), std::invalid_argument);
}

// Тест move — недопустимое перемещение (нельзя двигать)
TEST(Move_Not_Ad_jacent) {
    Game g;
    CHECK_THROW(g.move(1), std::invalid_argument); // 1 в углу, не рядом с пустой
}

// Тест operator[]
TEST(Subscript_Operator) {
    Game g;
    CHECK_EQUAL(1, g[1]);
    CHECK_EQUAL(2, g[2]);
    CHECK_EQUAL(15, g[15]);
    CHECK_EQUAL(0, g[16]);

    // Тест на выход за границы
    CHECK_THROW(g[0], std::out_of_range);
    CHECK_THROW(g[17], std::out_of_range);
}

// Тест getBoard и геттеров
TEST(Getters) {
    Game g;
    auto board = g.get_board();
    CHECK_EQUAL(4, board.size());
    CHECK_EQUAL(4, board[0].size());
    CHECK_EQUAL(3, g.get_empty_x());
    CHECK_EQUAL(3, g.get_empty_y());
}

// Тест getSize
TEST(Get_Size) {
    Game g;
    CHECK_EQUAL(4, g.get_size());
}

// Тест create_random_board — должен создать решаемую доску
TEST(Create_RandomBoard_Solvable) {
    Game g;
    g.create_random_board();
    CHECK(g.is_solvable());
    
    // Проверяем, что есть ровно один 0
    int zeros = 0;
    for (int i = 1; i <= 16; i++) {
        if (g[i] == 0) zeros++;
    }
    CHECK_EQUAL(1, zeros);
    
    // Проверяем, что все числа от 0 до 15 присутствуют ровно один раз
    std::set<int> values;
    for (int i = 1; i <= 16; i++) {
        values.insert(g[i]);
    }
    CHECK_EQUAL(16, values.size());
    CHECK(values.find(0) != values.end());
    CHECK(values.find(15) != values.end());
}

// Тест edge: move в граничных условиях
TEST(Move_Edge_Cases) {
    // Создадим доску с 0 в (0,0)
    std::vector<std::vector<int>> board = {
        {0, 2, 3, 4},
        {1, 6, 7, 8},
        {5,10,11,12},
        {9,13,14,15}
    };
    Game g(board);
    CHECK_EQUAL(0, g.get_empty_x());
    CHECK_EQUAL(0, g.get_empty_y());
    // Можно двигать только 2 и 1
    CHECK(g.is_valid_move(0,1)); // 2
    CHECK(g.is_valid_move(1,0)); // 1
    CHECK(g.move(2));
    CHECK_EQUAL(0, g.get_empty_x());
    CHECK_EQUAL(1, g.get_empty_y());
}

// Тест: после перемещения состояние меняется, но остаётся корректным
TEST(Move_Updates_State_Correctly) {
    Game g;
    CHECK(g.is_solved());
    
    // Сделаем ход
    g.move(15);
    CHECK(!g.is_solved());
    CHECK_EQUAL(0, g[15]); // пустая клетка теперь на 15-м месте
    CHECK_EQUAL(15, g[16]); // 15 теперь на последнем месте
    
    // Вернём обратно
    g.move(15);
    CHECK(g.is_solved());
    CHECK_EQUAL(15, g[15]);
    CHECK_EQUAL(0, g[16]);
}

TEST(Display_Called) {
    Game g;
    std::string out = capture_print(g);
    std::string solved_board = "\n=========================\n|  1  |  2  |  3  |  4  |\n|=====|=====|=====|=====|\n|  5  |  6  |  7  |  8  |\n|=====|=====|=====|=====|\n|  9  | 10  | 11  | 12  |\n|=====|=====|=====|=====|\n| 13  | 14  | 15  |     |\n=========================\n\n";
    
    CHECK_EQUAL(solved_board, out);
}

int main() {
    return UnitTest::RunAllTests();
}