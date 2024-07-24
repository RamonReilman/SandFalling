#include "grid.hpp"
#include <cmath>
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
    return (row >= 0 && row <= rows-1 && column >= 0 && column <= columns-1);
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
        int Size = 5;
        int extent = std::floor(Size);
        for (int rowDelta = -extent; rowDelta < extent; rowDelta++)
        {
            for (int columnDelta = -extent; columnDelta < extent; columnDelta++)
            {
                int rowNew =row + rowDelta;
                int columnNew = column + columnDelta;

                if (isInBounds(rowNew, columnNew))
                {
                    if (cells[rowNew][columnNew] == 0)
                    {
                        cells[rowNew][columnNew] = hue;
                    }
                    else {

                        cells[rowNew][columnNew] = 0;
                    }
                }
            }
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
