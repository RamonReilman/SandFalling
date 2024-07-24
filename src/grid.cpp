#include "grid.hpp"
#include <codecvt>
#include <iostream>
#include <raylib.h>

void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            Color sand = ColorFromHSV(Grid::GetValue(row,column),S,V);

            Color color = cells[row][column] ? sand : Color{55, 55, 55, 255};
            DrawRectangle(column*cellSize, row*cellSize, cellSize, cellSize, color);
        }
    }
}

bool Grid::isInBounds(int row, int column)
{
    return (row >= 0 && row <= rows && column >= 0 && column <= columns);
}

void Grid::SetValue(int row, int column, int value)
{
    if (isInBounds(row, column))
    {


        cells[row][column] = value;
    }
}

int Grid::GetValue(int row, int column)
{
    if (isInBounds(row, column))
    {
        return cells[row][column];
    }
    return 0;
}

void Grid::ToggleCell(int row, int column, float hue)
{
    if (isInBounds(row, column))
    {
        if (cells[row][column] == 0)
        {
            cells[row][column] = hue;
        }
        else {
            cells[row][column] = 0;
        }


    }
}

void Grid::Clear()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cells[row][column] = 0;
        }
    }
}
