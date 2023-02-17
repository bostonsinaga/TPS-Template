/***************************/
/* USING ANALOG CONTROLLER */
/***************************/ 

#include "Controller.h"

USING_NS_CC;

Controller::Controller() {
    pad = NStool::createSpriteFrame(
        "",
        NStool::edgeSpawnVec2_SouthWest
    );

    stick[0] = NStool::createSpriteFrame(
        "",
        pad->getPosition();
    );

    stick[1] = NStool::createSpriteFrame(
        "",
        pad->getPosition();
    );

    stick[1]->setVisible(false);
}

void Controller::touchBegan(const std::vector<Touch*> &touches) {

}

void Controller::touchMoved(const std::vector<Touch*> &touches) {

}

void Controller::touchEnded(const std::vector<Touch*> &touches) {

}
