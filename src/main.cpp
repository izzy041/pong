#include "raylib.h"

int main()
{
    // Initialise window
    InitWindow(1280, 720, "Pong");

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}