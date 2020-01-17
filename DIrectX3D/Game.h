#pragma once
#include "WinApp.h"
class Game :
    public WinApp
{
protected:
    virtual int Update() noexcept;
public:
    virtual int Run() override;
};

