﻿
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <android/log.h>
#include "cocos2d.h"
#include "MainGameApp.h"


#define  LOG_TAG    "main"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

using namespace cocos2d;

extern "C"
{
jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	JniHelper::setJavaVM(vm);
    return JNI_VERSION_1_4;
}

void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeInit(JNIEnv*  env, jobject thiz, jint w, jint h)
{
    if (!CCDirector::sharedDirector()->getOpenGLView())
    {
    	//CCLOG("Main init");
        CMainGameApp *pAppDelegate = new CMainGameApp;


        CCEGLView *view = CCEGLView::sharedOpenGLView();
        view->setFrameSize(w, h);
        //view->setFrameSize(960, 640);

        CCApplication::sharedApplication()->run();
        //pClientGlobal->Release();
        //pClientGlobal = NULL;
    }



    /*
    else
    {
        ccDrawInit();
        ccGLInvalidateStateCache();
        
        CCShaderCache::sharedShaderCache()->reloadDefaultShaders();
        CCTextureCache::reloadAllTextures();
        CCNotificationCenter::sharedNotificationCenter()->postNotification(EVNET_COME_TO_FOREGROUND, NULL);
        CCDirector::s haredDirector()->setGLDefaultValues();
    }
    */
}

}