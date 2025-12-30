#define RAYLIB_NUKLEAR_IMPLEMENTATION
#include "raylib-nuklear.h"


#include "raynuk/App.hpp"
#include <raylib.h>

namespace raynuk
{
  App::App(int width, int height, const std::string &name)
    : m_name(name), 
      m_width(width), 
      m_height(height)
  {
  
  }
  
  
  void App::Run()
  {
    SetTraceLogLevel(LOG_WARNING);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(m_width,m_height,m_name.c_str());
    struct nk_context *nuklear = nullptr;
    int fontSize = 18;
    Font font = LoadFontEx("/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf",fontSize,NULL,0);
    if (IsFontValid(font)) {
      nuklear = InitNuklearEx(font,fontSize);
    }
    else
    {

      nuklear = InitNuklear(fontSize);
    }

    SetTargetFPS(60);

    // Create the Nuklear Context
  
    OnSetup();
  
    while (!WindowShouldClose())
    {
      UpdateNuklear(nuklear);
      OnUpdate();
      OnUI(nuklear);
      BeginDrawing();
      ClearBackground(BLACK);
      OnDraw();
      DrawNuklear(nuklear);
      EndDrawing();
    }
  
    OnTeardown();
    // De-initialize the Nuklear GUI
    UnloadNuklear(nuklear);
    CloseWindow();
  }
} // namespace raynuk
