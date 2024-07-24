#pragma once
#include <raylib.h>
#include <vector>

class Grid
{
    public:
        Grid(int width, int height, int cellSize)
        : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)){};
        void Draw();
        void SetValue(int row, int column, int value);

        int GetValue(int row, int column);

        int getRows(){return rows;}
        int getColumns(){return columns;}

        void ToggleCell(int row, int column);
        bool isInBounds(int row, int column);

        void Clear();
    private:
        int rows;
        int columns;
        int cellSize;
        Color sand = {194, 178, 128, 255};
        std::vector<std::vector<int>> cells;
};
