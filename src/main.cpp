#include "raylib.h"

// Window variables
const int windowWidth = 800;
const int windowHeight = 450;

// Player variables
Rectangle player { 30.0f, (float) windowHeight / 2.0f,  10.0f, 30.0f};
const float playerSpeed = 5.0f;
int playerScore = 0;

// Opponent variables
int opponentScore = 0;

// Handles player movement
void MovePlayer(Rectangle& rec)
{
    // Move up if w pressed and not at the top of the screen
    // Move down if s pressed and not at the bottom of the screen
    if (IsKeyDown(KEY_W) && rec.y > 0.0f)
        rec.y -= playerSpeed;
    else if (IsKeyDown(KEY_S) && rec.y < windowHeight - rec.height)
        rec.y += playerSpeed;
}

int main()
{
    // Initialise window
    InitWindow(windowWidth, windowHeight, "Pong");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        MovePlayer(player);
        DrawRectangleRec(player, WHITE);
        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}