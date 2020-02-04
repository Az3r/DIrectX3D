#pragma once
#include "WinApp.h"
#include "Graphics.h"
#include <memory>
class Game :
    public WinApp
{
private:
     std::unique_ptr<Graphics> mGfx;
protected:
    virtual int Update() noexcept;
public:
    Game() = default;
    virtual int InitInstance() override;
    virtual int Run() override;
};

