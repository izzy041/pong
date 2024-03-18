#include "raylib.h"

// Window variables
const int windowWidth = 800;
const int windowHeight = 450;

// Player variables
Rectangle player { 30.0f, (float) windowHeight / 2.0f,  10.0f, 30.0f};
const float playerSpeed = 5.0f;
int playerScore = 0;

// Handles player movement
void MovePlayer()
{
    // Move up if w pressed and not at the top of the screen
    // Move down if s pressed and not at the bottom of the screen
    if (IsKeyDown(KEY_W) && player.y > 0.0f)
        player.y -= playerSpeed;
    else if (IsKeyDown(KEY_S) && player.y < windowHeight - player.height)
        player.y += playerSpeed;
}

// Opponent variables
int opponentScore = 0;

// Ball variables
Vector2 ballPosition = { (float) windowWidth / 2.0f, (float) windowHeight / 2.0f };
Vector2 ballSpeed { 5.0f, 4.0f };
float ballRadius = 6.0f;

// Makes the ball move and bounce off of the walls
void MoveBall()
{
    // Move the ball
    ballPosition.x += ballSpeed.x;
    ballPosition.y += ballSpeed.y;

    // If the ball hits a vertical edge, reverse (bounce) it away
    if (ballPosition.x >= windowWidth - ballRadius || ballPosition.x <= ballRadius)
        ballSpeed.x *= -1.0f;
    // If the ball hits a horizontal edge, reverse (bounce) it away
    if (ballPosition.y >= windowHeight - ballRadius || ballPosition.y <= ballRadius)
        ballSpeed.y *= -1.0f;
}

// Checks for collisions and handles them
void HandleCollision()
{
    // If the player collides with the ball, bounce the ball off of the player
    if (CheckCollisionCircleRec(ballPosition, ballRadius, player))
        ballSpeed.x *= -1.0f;
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

        MovePlayer();
        DrawRectangleRec(player, WHITE);

        MoveBall();
        DrawCircleV(ballPosition, ballRadius, WHITE);

        HandleCollision();

        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}