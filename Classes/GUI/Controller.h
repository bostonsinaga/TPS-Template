/***************************/
/* USING ANALOG CONTROLLER */
/***************************/ 

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Tool.h"

class Controller {
public:
    Controller();

    void touchBegan(const std::vector<Touch*> &touches);
    void touchMoved(const std::vector<Touch*> &touches);
    void touchEnded(const std::vector<Touch*> &touches);

private:
    cocos2d::Sprite
        *pad,
        *stick[2]; // [0] = normal, [1] = pressed
};

#endif // __CONTROLLER_H__