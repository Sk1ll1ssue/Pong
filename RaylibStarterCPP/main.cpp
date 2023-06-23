/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "Raylib/include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "Raygui/src/raygui.h"
#include "Ball.h"
#include "Player.h"
#include "Score.h"



int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
   
    Player player1 = Player{};
    Player player2 = Player{};

    player1.position = { 25, 180 };
    player1.size = { 10,100 };
    player1.color = RED;

    player2.position = { 775, 180 };
    player2.size = { 10,100 };
    player2.color = GREEN;

    Ball ball = Ball{};

    ball.position = { 400, 225 };
    ball.radius = 10;
    ball.speed = { 3.5,3.5 };
    ball.active = false;

    Score scoreBoard1 = Score{};
    Score player1Score = Score{};
    Score scoreBoard2 = Score{};
    Score player2Score = Score{};

    scoreBoard1.position = { 10,10 };
    scoreBoard1.size = { 170,35 };

    player1Score.position = { 15,15 };
    player1Score.score = 0;
    player1Score.fontSize = 25;
    player1Score.player = true;

    scoreBoard2.position = { 625,10 };
    scoreBoard2.size = { 170,35 };

    player2Score.position = { 630,15 };
    player2Score.score = 0;
    player2Score.fontSize = 25;
    player2Score.player = false;

    int speed = 5;

    //--------------------------------------------------------------------------------------

    if (ball.active) {

        ball.position.x += ball.speed.x;
        ball.position.y += ball.speed.y;

        if (ball.speed.x >= 5) {
            ball.speed.x = 3.5;
        }
        if (ball.speed.y >= 5) {
            ball.speed.y = 3.5;
        }

        if (IsKeyDown(KEY_DOWN)) {
            player2.position.y += speed;
        }
        if (IsKeyDown(KEY_UP)) {
            player2.position.y -= speed;
        }
        if (IsKeyDown(KEY_S)) {
            player1.position.y += speed;
        }
        if (IsKeyDown(KEY_W)) {
            player1.position.y -= speed;
        }

        if ((ball.position.x + ball.radius) >= screenWidth) {
            ball.speed.x *= -1;
            player1Score.score += 1;
            ball.active = false;
        }
        if ((ball.position.x - ball.radius) <= 0) {
            ball.speed.x *= -1;
            player2Score.score += 1;
            ball.active = false;
        }

        if (CheckCollisionCircleRec(ball.position, ball.radius, Rectangle{ player1.position.x, player1.position.y, player1.size.x, player1.size.y })) {
            ball.speed.y *= (ball.position.y - player1.position.y) / (player1.size.y / 2) * 2;
            ball.speed.x *= -1;
        }

        if (CheckCollisionCircleRec(ball.position, ball.radius, Rectangle{ player2.position.x, player2.position.y, player2.size.x, player2.size.y })) {
            ball.speed.y *= (ball.position.y - player2.position.y) / (player2.size.y / 2) * 2;
            ball.speed.x *= -1;
        }


        if (ball.position.y + ball.radius >= screenHeight) {
            ball.speed.y *= -1;
        }

        if (ball.position.y - ball.radius <= 0) {
            ball.speed.y *= -1;
        }

    }

    if (!ball.active) {
        ball.speed = { 0,0 };
        ball.position = { 400,250 };

        if (IsKeyDown(KEY_DOWN)) {
            player2.position.y += speed;
        }
        if (IsKeyDown(KEY_UP)) {
            player2.position.y -= speed;
        }
        if (IsKeyDown(KEY_S)) {
            player1.position.y += speed;
        }
        if (IsKeyDown(KEY_W)) {
            player1.position.y -= speed;
        }

        if (IsKeyPressed(KEY_SPACE)) {
            int random = (rand() % 3);

            switch (random)
            {
            case 0:
                ball.speed = { 3.5, 3.5 };
                break;
            case 1:
                ball.speed = { -3.5,3.5 };
                break;
            case 2:
                ball.speed = { 3.5, -3.5 };
                break;
            case 3:
                ball.speed = { -3.5, -3.5 };
                break;
            }

            ball.active = true;
        }
    }

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        player1.Draw();
        player2.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}