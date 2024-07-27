#pragma once
#include "grid.hpp"

class Simulation
{
    public:
        Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), tempGrid(width, height, cellSize){};

        void Draw();
        void SetCellValue(int row, int column, int value);
        void Update();
        int getBottoms(int row, int column);
        bool isRunning() {return run;}

        void Start(){run = true;}
        void Stop(){run = false;}
        void NewGrid(int width, int height, int cellSize) {grid = Grid(width, height, cellSize); tempGrid = Grid(width, height, cellSize);}
        void ToggleCell(int row, int column, int size);

        void Clear();

    private:
        Grid grid;
        Grid tempGrid;
        float Hue = 1;
        bool run;
};
