/*
 * Copyright (C) 2020 Sacred Sanctuary Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#define LOG_NDEBUG 0
#define LOG_TAG "HelloWorldPlugin-Native"

#include "HelloAndroid.h"
#include "utils/log_main.h"
#include "utils/GoToIF.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJava.h"
#include <jni.h>

/*static*/ HelloAndroid* HelloAndroid::sHelloAndroid = NULL;

/*static*/ HelloAndroid* HelloAndroid::Create() {
    HelloAndroid *hello = new HelloAndroid();

    if (!hello->init()) {
        return NULL;
    }

    ALOGV("Create new HelloAndroid(%p)", hello);

    setInstance(hello);

    return hello;
}

/*static*/ void HelloAndroid::setInstance(HelloAndroid* instance) {
    sHelloAndroid = instance;
}

/*static*/ HelloAndroid* HelloAndroid::getInstance() {
    return sHelloAndroid;
}

HelloAndroid::HelloAndroid() {
    ALOGV("HelloAndroid constructor");
}

HelloAndroid::~HelloAndroid() {
    ALOGV("HelloAndroid destructor");
    setInstance(NULL);
}

bool HelloAndroid::init() {
    return true;
}

void HelloAndroid::setup(JNIEnv *env, jobject contextObj) {
    ALOGV("HelloAndroid::setup [I N] ");
    status_t status = NO_ERROR;
    jmethodID method;

    mClazz = FAndroidApplication::FindJavaClassGlobalRef("jp/sacredsanctuary/helloworld/service/HelloFromNative");
    GOTO_IF_NULL(mClazz);

    method = FJavaWrapper::FindStaticMethod(env, mClazz, "setupFromNative", "(Landroid/content/Context;)V", false);
    GOTO_IF_NULL(method);

    mContext = env->NewGlobalRef(contextObj);
    GOTO_IF_NULL(mContext);

    env->CallStaticVoidMethod(mClazz, method, mContext);

Exit:
    ALOGV("HelloAndroid::setup [OUT] ");
}

void HelloAndroid::clear_l() {
    ALOGV("HelloAndroid::clear_l");
}

void HelloAndroid::startHelloActivity(JNIEnv *env) {
    ALOGV("HelloAndroid::startHelloActivity [I N] ");

    status_t status = NO_ERROR;
    jmethodID method;
    jboolean  ret = false;

    method = FJavaWrapper::FindStaticMethod(env, mClazz, "startHelloActivityFromNative", "(Landroid/content/Context;)V", false);
    GOTO_IF_NULL(method);

    env->CallStaticVoidMethod(mClazz, method, mContext);

Exit:
    ALOGV("HelloAndroid::startHelloActivity [OUT] ret:%d", ret);
}

void HelloAndroid::notify(int msg, const void *obj)
{
    ALOGV("HelloAndroid::notify message received msg=%d", msg);
}

