//
//  main.cpp
//  Рисование таблицы
//
//  Created by Станислав Егоров on 06.11.2023.
//

#include <iostream>
using namespace std;

void drawLines(int columns, string edge, string closingEdge) {
    // рисуется линия
    for (size_t i = 0; i < columns; i++)
    {
        cout << edge;
    }
    cout << closingEdge << endl;
}

void drawCells(int columns, string cell, string closingCell) {
    // рисуются ячейки
    for (size_t i = 0; i < columns; i++)
    {
        cout << cell;
    }
    cout << closingCell << endl;
}

int main() {
    int columns = 4;
    int rows = 4;
    string edge = "+---";
    string closingEdge = "+";
    string cell = "|   ";
    string closingCell = "|";

    for (size_t i = 0; i < rows; i++)
    {
        drawLines(columns, edge, closingEdge);
        drawCells(columns, cell, closingCell);
    }
    drawLines(columns, edge, closingEdge);

}
