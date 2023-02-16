#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "Tool.h"

class GameScene : public cocos2d::Layer {
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
        /***********/
        /* METHODS */
        /***********/ 

        // PHYSICS SPECIAL //
        void setPhysicsWorld(cocos2d::PhysicsWorld *world) {sceneWorld = world;}

        // TOUCH EVENT //
        void initTouch();
        void delayTouch(float dt);
        void scheduleActivate_isTouchable(float dt);
        void onKeyReleasing();

        // SCENES //
        void goToPauseScene();
        void goToGameOverScene(float dt);
        cocos2d::RenderTexture *getRenTex();

        /*************/
        /* VARIABLES */
        /*************/

        cocos2d::PhysicsWorld *sceneWorld;

        bool isTouchable;
        cocos2d::Vec2 tBegan, tMoved, tEnded;
};

#endif // __GAME_SCENE_H__