#include "simulation.hpp"
#include <iostream>
#include <raylib.h>

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}

int Simulation::getBottoms(int row, int column)
{
    int WantedColumn1 = (column-1+grid.getColumns()) % grid.getColumns();
    int WantedColumn2 = (column+1+grid.getColumns()) % grid.getColumns();
    int right = grid.GetValue(row+1,WantedColumn1);
    int left = grid.GetValue(row+1,WantedColumn2);

    if (!left && !right) {return 0;}
    if (left && !right) {return -1;}
    if (!left && right){return 1;}
    if (left && right){return 2;}
    return 0;
}

void Simulation::Update()
{
    if (isRunning())
    {

        for (int row = 0; row < grid.getRows()-1; row++)
        {
            for (int column = 0; column < grid.getColumns(); column++)
            {
                int NewCol = (column-1+grid.getColumns()) % grid.getColumns();
                int NewCol2 = (column+1+grid.getColumns()) % grid.getColumns();
                float cellValue = grid.GetValue(row,column);
                if (cellValue > 0)
                {
                    if (grid.GetValue(row+1, column) == 0)
                    {
                        tempGrid.SetValue(row,column,0);
                        tempGrid.SetValue(row+1, column, cellValue);
                    }
                    else if (grid.GetValue(row+1, column) > 0)
                    {
                        if (getBottoms(row, column) == 0)
                        {
                            int randN = GetRandomValue(0,1);
                            if (randN == 0) {tempGrid.SetValue(row+1,column+1,cellValue);}
                            else if (randN == 1) {tempGrid.SetValue(row+1, column-1,cellValue);}
                            tempGrid.SetValue(row,column,0);
                        }
                        else if (getBottoms(row,column) == 1) {tempGrid.SetValue(row+1, NewCol2,cellValue); tempGrid.SetValue(row, column,0);}
                        else if (getBottoms(row,column) == -1) {tempGrid.SetValue(row+1, NewCol,cellValue); tempGrid.SetValue(row, column,0);}
                        else if (getBottoms(row,column) == 2) {tempGrid.SetValue(row, column,cellValue);}

                    }
                }
            }
        }
        grid = tempGrid;
    }
}

void Simulation::ToggleCell(int row, int column, int size)
{
    Hue += 1;
    if (Hue > 360)
    {
        Hue = 1;
    }
    grid.ToggleCell(row, column, Hue, size);

}

void Simulation::Clear()
{
    tempGrid.Clear();
    grid.Clear();

}
