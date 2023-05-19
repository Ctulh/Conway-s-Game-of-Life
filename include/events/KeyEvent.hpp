
#pragma once

class KeyEvent {
public:
    virtual ~KeyEvent() = default;
public:
    virtual bool onKeyPressed(int key) {
        return false;
    }
};