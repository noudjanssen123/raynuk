
#include "raynuk/App.hpp"

#include <cstdio>

class MyApp : public raynuk::App
{
public:
  MyApp()
    : App(1200,800,"MyApp")
  {

  }
  ~MyApp() = default;
public:
  void OnUI(nk_context *nuklear) override {
    if (nk_begin(nuklear,"main",nk_rect(0,0,GetScreenWidth(),GetScreenHeight()), NK_WINDOW_BACKGROUND)) {
      nk_layout_row_static(nuklear,60,200,2);
      nk_label(nuklear,"Hello: ",NK_TEXT_ALIGN_LEFT | NK_TEXT_ALIGN_MIDDLE);
      if (nk_button_label(nuklear,"world!")) {
        printf("Hello World!\n");
      }
    }
    nk_end(nuklear);
  }
};

int main(int argc, char const *argv[])
{
  MyApp app;
  app.Run();
  return 0;
}
