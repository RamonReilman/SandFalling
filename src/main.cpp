#include <cstdlib>

#include <iostream>
#include <raylib.h>
#include <sstream>
#include "simulation.hpp"

int main(int argc, char* argv[])
{
    int CELLSIZE = 25;
    if (argc == 2)
    {
        try {
            std::istringstream iss( argv[1] );
            int WantedCells;
            if (iss >> WantedCells)
            {
                CELLSIZE = WantedCells;
            }else {
                throw (argv[1]);
            }

        } catch (char* arg) {
            std::cout << "Cannot set CELLSIZE to given value, setting it to 25\n";
            std::cout << "Given value: " << arg << ", is not an integer.\n";
        }
    }
    if (CELLSIZE > 25)
    {
        CELLSIZE = 25;
    }

    Color GREY = {55, 55, 55, 255};
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 1200;

    int FPS = 100;
    int monitor = GetCurrentMonitor();



    InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor) , "Sand Falling");
    SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
    SetTargetFPS(FPS);

    ToggleFullscreen();
    Simulation simulation{GetMonitorWidth(monitor),  GetMonitorHeight(monitor), CELLSIZE};
    while (!WindowShouldClose())
    {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();
            int row = mousePos.y / CELLSIZE;
            int column = mousePos.x / CELLSIZE;
            simulation.ToggleCell(row, column, 50/CELLSIZE);
        }
        if (IsKeyPressed(KEY_SPACE))
        {
            if (simulation.isRunning())
            {
                simulation.Stop();
                SetWindowTitle("Sand is Not Falling");
            } else {simulation.Start(); SetWindowTitle("Sand is Falling");}
        }
        else if (IsKeyPressed(KEY_C))
        {
            simulation.Clear();
        }
        else if (IsKeyDown(KEY_W))
        {
            std::cout << "FPS: " << FPS << std::endl;
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyDown(KEY_S))
        {
            if (FPS >= 10)
            {
                std::cout << "FPS: " << FPS << std::endl;
                FPS -=2;
                SetTargetFPS(FPS);
            }
        }
        if (IsKeyPressed(KEY_F))
        {
            if (!IsWindowFullscreen())
            {
                int monitor = GetCurrentMonitor();
                SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
                ToggleFullscreen();
                simulation.NewGrid(GetMonitorWidth(monitor), GetMonitorHeight(monitor), CELLSIZE);
            }
            else {
                ToggleFullscreen();
                SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
                simulation.NewGrid(WINDOW_WIDTH, WINDOW_HEIGHT, CELLSIZE);
            }
        }

        simulation.Update();
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
