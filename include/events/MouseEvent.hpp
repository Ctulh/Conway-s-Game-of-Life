
#pragma once

class MouseEvent {
public:
    virtual ~MouseEvent() = default;
public:
    virtual bool onMouseButtonDown(int x, int y) {return false;};
    virtual bool onMouseButtonUp(int x, int y)  {return false;};
};