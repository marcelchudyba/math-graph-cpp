#include <iostream>
#include <raylib.h>
#include <string>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "CoordinateSystem.h"



int main() {

    const int screen_width = 1280;
    const int screen_height = 720;
    InitWindow(screen_width, screen_height, "Math Graph");
    SetWindowState(FLAG_WINDOW_ALWAYS_RUN);
    float scale = 50.0f;
    const int step = 1;
    SetTargetFPS(999);

    CoordinateSystem coordinate_system = CoordinateSystem(screen_width, screen_height, scale,step);


    char equation[64] = "";
    char equation2[64] = "";

    bool editMode = false;
    bool editMode2 = false;



    while(WindowShouldClose() == false) {

        BeginDrawing();
        ClearBackground(BLACK);
        coordinate_system.DrawCoordinateSystem();
        coordinate_system.DrawFunction(equation,BLUE);
        coordinate_system.DrawSequence(equation2,GREEN);



        //moving system
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

            Vector2 delta = GetMouseDelta();
            coordinate_system.origin.x += delta.x;
            coordinate_system.origin.y += delta.y;

            SetMouseCursor(MOUSE_CURSOR_RESIZE_ALL);

            coordinate_system.UpdateScale(scale);
        } else {
            SetMouseCursor(DEFAULT);
        }



        //scaling system
        float wheelMove = GetMouseWheelMove();
        if (wheelMove != 0.0f) {

            float zoomFactor = 0.1f;
            scale +=  wheelMove * scale * zoomFactor;
            if (scale < 1.0f) {
                scale = 1.0f;
            }
            if (scale > 10000.0f)
            {
                scale = 10000.0f;
            }
            coordinate_system.UpdateScale(scale);
            TraceLog(LOG_INFO, "Wartosc scale: %0.0f", scale);

        }

        //Gui
        DrawRectangle(40, 80, 150, 30 , BLACK);
        DrawRectangle(40, 140, 150, 30  , BLACK);

        DrawFPS(5,10);
        DrawText(TextFormat("x: %.0f y: %.0f", coordinate_system.origin.x ,coordinate_system.origin.y), 5, 40, 20, WHITE);
        DrawText(TextFormat("y = "),5, 85, 20,BLUE);
        DrawText(TextFormat("y = "),5, 145, 20,GREEN);

        if (GuiTextBox(Rectangle{ 40, 80, 150, 30 }, equation, 64, editMode)) {
            editMode = !editMode;
        }
        if (GuiTextBox(Rectangle{ 40, 140, 150, 30 }, equation2, 64, editMode2)) {
            editMode2 = !editMode2;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
