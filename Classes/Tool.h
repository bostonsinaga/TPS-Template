#ifndef __TOOL_H__
#define __TOOL_H__

#include "cocos2d.h"
#include "Definition.h"

USING_NS_CC;

namespace NStool {

/*************/
/* VARIABLES */
/*************/

UserDefault *uDef = UserDefault::getInstance();
Size vSize = Director::getInstance()->getVisibleSize();
Vec2 vOrigin = Director::getInstance()->getVisibleOrigin();

// firstly, fill this with scene layer!
Layer *currentLayer;

// spawn position flag for near edge of screen
Vec2 edgeSpawnVec2_North = Vec2(0, std::INT_MAX),
     edgeSpawnVec2_NorthEast = Vec2(std::INT_MAX, std::INT_MAX),
     edgeSpawnVec2_East = Vec2(std::INT_MAX, 0),
     edgeSpawnVec2_SouthEast = Vec2(std::INT_MAX, -std::INT_MAX),
     edgeSpawnVec2_South = Vec2(0, -std::INT_MAX),
     edgeSpawnVec2_SouthWest = Vec2(-std::INT_MAX, -std::INT_MAX),
     edgeSpawnVec2_West = Vec2(-std::INT_MAX, 0),
     edgeSpawnVec2_NorthWest = Vec2(-std::INT_MAX, std::INT_MAX);

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

void settleNode(
    Node *node,
    Vec2 &pos,
    int &zOrder,
    Node *parent
);

Node *createNode(
    Vec2 pos = Vec2::ZERO,
    Size size = Size::ZERO,
    Node *parent = nullptr,
    int zOrder = 0
) {
    Node *node = Node::create();
    node->setContentSize() = size;
    settleNode(node, pos, zOrder, parent);
    return node;
}

// call this in 'SplashScene.h' or in enterance scene
void setupSpriteFrameCache(std::string fileName) {
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile(fileName);
}

// using sprite sheet (recommended)
Sprite *createSpriteFrame(
    std::string frameName,
    Vec2 pos = Vec2::ZERO,
    Size size = Size::ZERO,
    Node *parent = nullptr,
    int zOrder = 0
) {
    auto sprite = Sprite::createWithSpriteFrameName(frameName);

    if (size != Size::ZERO && size != Size(0, 0)) {
        sprite->setContentSize() = size;
    }

    settleNode(sprite, pos, zOrder, parent);
    return sprite;
}

// conventional sprite creation (without sprite sheet)
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

    settleNode(sprite, pos, zOrder, parent);
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
    Label *label = Label::createWithTTF(
        text,
        fontName,
        height == 0.0 ? getBrickLength() / 2 : height
    );

    // not using 'settleNode()'
    label->setPosition(pos);
    if (parent) parent->addChild(label, zOrder);
    else currentLayer->addChild(label, zOrder);

    return label;
}

// PHYSICS FUNCTIONS //

PhysicsBody *createPhysicsBody(
    Node *target,
    int catMask,
    /* category bitmask (flag for object) eg. 1, 2, 4, 8, ... */
    int colMask,
    /* collision bitmask (flags count of interactable objects for the object) eg. 2 + 4 */
    bool isDynamic = true
) {
    PhysicsBody *body = PhysicsBody::create();
    body->setDynamic(isDynamic);
    body->setCategoryBitmask(catMask);
    body->setCollisionBitmask(colMask);
    target->setPhysicsBody(body);
    return body;
}

PhysicsBody *createPhysicsBodyCircle(
    Node *target,
    float radius,
    int catMask,
    int colMask,
    bool isDynamic = true
) {
    PhysicsBody *body = createPhysicsBody(target, catMask);
    body->addShape(PhysicsShapeCircle::create(radius));
}

PhysicsBody *createPhysicsBodyPolygon(
    Node *target,
    const Vec2 *vec2Arr,
    int arrCount,
    int catMask,
    int colMask,
    bool isDynamic = true
) {
    PhysicsBody *body = createPhysicsBody(target, catMask);
    body->addShape(PhysicsShapePolygon::create(vec2Arr, arrCount));
}

PhysicsBody *createPhysicsBodyBox(
    Node *target,
    const Size &size,
    int catMask,
    int colMask,
    bool isDynamic = true
) {
    PhysicsBody *body = createPhysicsBody(target, catMask);
    body->addShape(PhysicsShapeBox::create(size));
}

PhysicsBody *createPhysicsBodyEdgeSegment(
    Node *target,
    const Vec2 &a,
    const Vec2 &b,
    int catMask,
    int colMask,
    bool isDynamic = true
) {
    PhysicsBody *body = createPhysicsBody(target, catMask);
    body->addShape(PhysicsShapeEdgeSegment::create(a, b));
}

PhysicsBody *createPhysicsBodyEdgePolygon(
    Node *target,
    const Vec2 *vec2Arr,
    int arrCount,
    int catMask,
    int colMask,
    bool isDynamic = true
) {
    PhysicsBody *body = createPhysicsBody(target, catMask);
    body->addShape(PhysicsShapeEdgePolygon::create(vec2Arr, arrCount));
}

PhysicsBody *createPhysicsBodyEdgeBox(
    Node *target,
    const Size &size,
    int catMask,
    int colMask,
    bool isDynamic = true
) {
    PhysicsBody *body = createPhysicsBody(target, catMask);
    body->addShape(PhysicsShapeEdgeBox::create(size));
}

}

#endif // __TOOL_H__