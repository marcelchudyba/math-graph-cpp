#include <iostream>
#include <raylib.h>
#include <string>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include "CoordinateSystem.h"

int main() {

    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "Math Graph");
    SetWindowState(FLAG_WINDOW_ALWAYS_RUN);
    float scale = 50.0f;
    const int step = 1;
    SetTargetFPS(144);

    CoordinateSystem coordinate_system = CoordinateSystem(screen_width, screen_height, scale,step);



    char equation[64] = "";

    bool editMode = false;



    while(WindowShouldClose() == false) {

        BeginDrawing();

        ClearBackground(RAYWHITE);


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

        ClearBackground(BLACK);

        //scaling system
        float wheelMove = GetMouseWheelMove();
        if (wheelMove != 0.0f) {

            float zoomFactor = 0.1f;
            scale += scale * wheelMove * zoomFactor;
            if (scale < 2.0f) {
                scale = 2.0f;
            }
            coordinate_system.UpdateScale(scale);
            TraceLog(LOG_INFO, "Wartosc scale: %0.0f", scale);

        }


        //Gui
        DrawText(TextFormat("x: %.0f y: %.0f", coordinate_system.origin.x ,coordinate_system.origin.y), 10, 50, 20, WHITE);
        if (GuiTextBox(Rectangle{ 10, 80, 150, 30 }, equation, 64, editMode)) {
            editMode = !editMode;
        }

        coordinate_system.DrawCoordinateSystem();
        coordinate_system.DrawFunction(equation);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
