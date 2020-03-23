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
#ifndef HELLO_ANDROID_H
#define HELLO_ANDROID_H

#include <jni.h>
#include "HelloAndroid.h"

enum hello_event_type {
    HELLO_ANDROID_NOP                   = 0, // interface test message
    HELLO_ANDROID_SERVICE_CONNECTED     = 1,
    HELLO_ANDROID_SERVICE_DISCONNECTED  = 2,
};

// ----------------------------------------------------------------------------
class HelloAndroid
{
public:
    static HelloAndroid*             Create();
    static HelloAndroid*             getInstance();

    ~HelloAndroid();

            void                    setup(JNIEnv *env, jobject contextObj);
            void                    startHelloActivity(JNIEnv *env);
            void                    notify(int msg, const void *obj);

protected:
    static HelloAndroid *sHelloAndroid;

private:
    static void                     setInstance(HelloAndroid *instance);
    HelloAndroid();
            void                    clear_l();
            bool                    init();
    jclass mClazz;
    jobject mContext;
    HelloAndroid* pHelloAndroid;
};

#endif // HELLO_ANDROID_H
