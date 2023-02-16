#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene() {
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2::ZERO);

    /* DEBUG ONLY */
    // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto layer = GameScene::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init() {

    //////////////////////////////
    // 1. super init first
    if (!Layer::init()) {
        return false;
    }

    /***************************/
    /* TEMPLATE INITIALIZATION */
    /***************************/

    NStool::currentLayer = this;

    // event listeners
    initTouch();
    onKeyReleasing();

    /*************************/
    /* CUSTOM INITIALIZATION */
    /*************************/

    // codes..

    return true;
}

// SCENES //

void GameScene::goToPauseScene() {

    // auto scene = PauseScene::createScene(getRenTex());
    // Director::getInstance()->pushScene(scene);
}

void GameScene::goToGameOverScene(float dt) {

    // auto scene = GameOverScene::createScene(getRenTex());
    // Director::getInstance()->pushScene(scene);
}

// take a screenshot
cocos2d::RenderTexture *GameScene::getRenTex() {

    auto renTex = RenderTexture::create(NStool::vSize.width, NStool::vSize.height);
    renTex->setPosition(NStool::ctrPos());

    renTex->begin();
    this->getParent()->visit();
    renTex->end();

    return renTex;
}

// EVENT LISTENERS //

void GameScene::initTouch(bool touchableToggleFlag) {

    isTouchable = touchableToggleFlag;
    auto touchListener = EventListenerTouchAllAtOnce::create();

    /*****************/
    /* TOUCHES BEGAN */
    /*****************/

    touchListener->onTouchBegan = [=] (const std::vector<Touch*> &touches, Event *event) {


        return true;
    };

    /*****************/
    /* TOUCHES MOVED */
    /*****************/
    
    touchListener->onTouchMoved = [=](const std::vector<Touch*> &touches, Event *event) {

    };

    /*****************/
    /* TOUCHES ENDED */
    /*****************/

    touchListener->onTouchEnded = [=](const std::vector<Touch*> &touches, Event *event) {
        
    };

    // add to event dispatcher
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void GameScene::delayTouch(float dt) {
    isTouchable = false;
    this->scheduleOnce(static_cast<SEL_SCHEDULE>(&GameScene::scheduleActivate_isTouchable), dt);
}

void GameScene::scheduleActivate_isTouchable(float dt) {
    isTouchable = true;
}

// back button ANDROID (called once)
void GameScene::onKeyReleasing() {

    auto backButtonListener = EventListenerKeyboard::create();
    backButtonListener->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_BACK) {

            
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(backButtonListener, this);
}