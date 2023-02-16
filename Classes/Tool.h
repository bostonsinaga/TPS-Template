#ifndef __TOOL_H__
#define __TOOL_H__

#include "cocos2d.h"
#include "Definition.h"

USING_NS_CC;

namespace mytool {

/*************/
/* VARIABLES */
/*************/

UserDefault *uDef = UserDefault::getInstance();
Size vSize = Director::getInstance()->getVisibleSize();
Vec2 vOrigin = Director::getInstance()->getVisibleOrigin();

// firstly, fill this with scene layer!
Layer currentLayer;

/*************/
/* FUNCTIONS */
/*************/

// VALUE FUNCTIONS //

float getBrickLength() {
    return uDef->getFloatForKey("SCALE RATE") * MAX_BRICK_LENGTH;
};

Size getBrickSize() {
    return Size(getBrickLength(), getBrickLength());
}

Vec2 centerVec2() {
    return vSize / 2 + vOrigin;
}

// NODE FUNCTIONS //

Node *createNode(
    Vec2 pos = Vec2::ZERO,
    Size size = Size::ZERO,
    Node *parent = nullptr,
    int zOrder = 0
) {
    Node *node = Node::create();
    node->setContentSize() = size;
    node->setPosition(pos);

    if (parent) parent->addChild(sprite, zOrder);
    else currentLayer->addChild(sprite, zOrder);
    
    return node;
}

Sprite *createSprite(
    std::string fileName,
    Vec2 pos = Vec2::ZERO,
    Size size = Size::ZERO,
    Node *parent = nullptr,
    int zOrder = 0
) {
    Sprite *sprite = Sprite::create(fileName);

    if (size != Size::ZERO && size != Size(0, 0)) {
        sprite->setContentSize() = size;
    }

    sprite->setPosition(pos);

    if (parent) parent->addChild(sprite, zOrder);
    else currentLayer->addChild(sprite, zOrder);

    return sprite;
}

Label *createLabel(
    std::string text,
    std::string fontName = "",
    Vec2 pos = Vec2::ZERO,
    float height = 0.0,
    Node *parent = nullptr,
    int zOrder = 0
) {
    Label *sprite = Label::createWithTTF(
        text,
        fontName,
        height == 0.0 ? getBrickLength() / 2 : height
    );

    sprite->setPosition(pos);

    if (parent) parent->addChild(sprite, zOrder);
    else currentLayer->addChild(sprite, zOrder);

    return sprite;
}

}

#endif // __TOOL_H__