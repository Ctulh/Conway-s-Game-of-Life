
#pragma once

class Event {
public:
    virtual ~Event() = default;
public:
    virtual void onUpdate() = 0;
};