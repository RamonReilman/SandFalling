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

    Color GREY = {29, 29, 29, 255};
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 1200;

    int FPS = 29;
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELLSIZE};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Sand Falling");
    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();
            int row = mousePos.y / CELLSIZE;
            int column = mousePos.x / CELLSIZE;
            simulation.ToggleCell(row, column);
        }
        if (IsKeyPressed(KEY_SPACE))
        {
            if (simulation.isRunning())
            {
                simulation.Stop();
            } else {simulation.Start();}
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
        simulation.Update();
        BeginDrawing();


        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
