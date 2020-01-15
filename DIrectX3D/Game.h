#pragma once
#include "WinApp.h"
class Game :
    public WinApp
{
protected:
    int Update() noexcept;
public:
    int Run() override;
};

