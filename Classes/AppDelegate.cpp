#include "AppDelegate.h"
#include "SCENES/GameScene.h"

// #define USE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#endif

USING_NS_CC;

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() {
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#endif
}

bool AppDelegate::applicationDidFinishLaunching() {

    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("TPS-Template", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("TPS-Template");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    auto fileUtils = FileUtils::getInstance();
    auto screenSize = glview->getFrameSize();
    std::vector<std::string> resDirOrders;
    float scaleRate;

    // check which assets the devices require
    // QHD
    if (screenSize.width + screenSize.height > 3500) {
    
        resDirOrders.push_back("2560x1440");
        glview->setDesignResolutionSize(2560, 1440, ResolutionPolicy::NO_BORDER);
        scaleRate = 1.0;
    }
    // FHD
    else if (screenSize.width + screenSize.height > 2500) {
    
        resDirOrders.push_back("1920x1080");
        glview->setDesignResolutionSize(1920, 1080, ResolutionPolicy::NO_BORDER);
        scaleRate = 0.75;
    }
    // HD
    else if (screenSize.width + screenSize.height > 1500) {
    
        resDirOrders.push_back("1280x720");
        glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::NO_BORDER);
        scaleRate = 0.5;
    }
    // SD
    else {
    
        resDirOrders.push_back("960x540");
        glview->setDesignResolutionSize(960, 540, ResolutionPolicy::NO_BORDER);
        scaleRate = 0.375;
    }

    fileUtils->setSearchPaths(resDirOrders);

    UserDefault *uDef = UserDefault::getInstance();
    uDef->setFloatForKey("SCALE RATE", scaleRate);
    uDef->flush();

    // create a scene. it's an autorelease object
    auto scene = GameScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#endif
}