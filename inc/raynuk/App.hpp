#ifndef RAYNUK_APP_HPP_
#define RAYNUK_APP_HPP_

#include <string>
#include "raylib-nuklear.h"

namespace raynuk
{
  class App
  {
  public:
    App(int width, int height, const std::string &name);
    ~App() = default;
  public:
    void Run();
  private:
    virtual void OnSetup() {};
    virtual void OnUpdate() {};
    virtual void OnUI(nk_context *nuklear) {};
    virtual void OnDraw() {};
    virtual void OnTeardown() {};
  private:
    const std::string m_name;
    const int m_width; 
    const int m_height; 
  };
} // namespace raynuk



#endif // APP_HPP_