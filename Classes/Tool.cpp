#include "Tool.h"

USING_NS_CC;

void Tool::settleNode(
    Node *node,
    Vec2 &pos,
    int &zOrder,
    Node *parent
) {
    // WARNING! 'label' node is not recommended to use this
    if (node) {

        /* using brick length as padding value */

        float paddingValue = getBrickLength() / 2;

        if (pos == edgeSpawnVec2_North) {
            node->setPosition(
                centerVec2 +
                Vec2(0, vSize.height / 2) +
                Vec2(0, -node->getContentSize().height / 2) +
                Vec2(0, -paddingValue)
            );
        }
        else if (pos == edgeSpawnVec2_NorthEast) {
            node->setPosition(
                centerVec2 +
                Vec2(vSize.width / 2, vSize.height / 2) +
                Vec2(-node->getContentSize().width / 2, -node->getContentSize().height / 2) +
                Vec2(-paddingValue, -paddingValue)
            );
        }
        else if (pos == edgeSpawnVec2_East) {
            node->setPosition(
                centerVec2 +
                Vec2(vSize.width / 2, 0) +
                Vec2(-node->getContentSize().width / 2, 0) +
                Vec2(-paddingValue, 0)
            );
        }
        else if (pos == edgeSpawnVec2_SouthEast) {
            node->setPosition(
                centerVec2 +
                Vec2(vSize.width / 2, -vSize.height / 2) +
                Vec2(-node->getContentSize().width / 2, node->getContentSize().height / 2) +
                Vec2(-paddingValue, paddingValue)
            );
        }
        else if (pos == edgeSpawnVec2_South) {
            node->setPosition(
                centerVec2 +
                Vec2(0, -vSize.height / 2) +
                Vec2(0, node->getContentSize().height / 2) +
                Vec2(0, paddingValue)
            );
        }
        else if (pos == edgeSpawnVec2_SouthWest) {
            node->setPosition(
                centerVec2 +
                Vec2(-vSize.width / 2, -vSize.height / 2) +
                Vec2(node->getContentSize().width / 2, node->getContentSize().height / 2) +
                Vec2(paddingValue, paddingValue)
            );
        }
        else if (pos == edgeSpawnVec2_West) {
            node->setPosition(
                centerVec2 +
                Vec2(-vSize.width / 2, 0) +
                Vec2(node->getContentSize().width / 2, 0) +
                Vec2(paddingValue, 0)
            );
        }
        else if (pos == edgeSpawnVec2_NorthWest) {
            node->setPosition(
                centerVec2 +
                Vec2(-vSize.width / 2, vSize.height / 2) +
                Vec2(node->getContentSize().width / 2, -node->getContentSize().height / 2) +
                Vec2(paddingValue, -paddingValue)
            );
        }
        else {
            node->setPosition(pos);
        }
        
        if (parent) parent->addChild(node, zOrder);
        else currentLayer->addChild(node, zOrder);
    }
}