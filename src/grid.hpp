#pragma once
#include <raylib.h>
#include <vector>

class Grid
{
    public:
        Grid(int width, int height, int cellSize)
        : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), cells(rows, std::vector<float>(columns, 0)){};
        void Draw();
        void SetValue(int row, int column, int value);

        int GetValue(int row, int column);

        int getRows(){return rows;}
        int getColumns(){return columns;}

        void ToggleCell(int row, int column, float hue, int size);
        bool isInBounds(int row, int column);

        void Clear();
    private:
        int rows;
        int columns;
        int cellSize;
        float H = 1;
        float S = 1;
        float V = 1;
        std::vector<std::vector<float>> cells;
};
