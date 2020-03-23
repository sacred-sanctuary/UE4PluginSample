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

#include <jp_sacredsanctuary_helloworld_nativeaccess_NativeAccess.h>
#include <utils/log_main.h>
#include <assert.h>

#include <HelloAndroid.h>

JNIEXPORT void JNICALL
Java_jp_sacredsanctuary_helloworld_nativeaccess_NativeAccess_onServiceConnectedJNI(
        JNIEnv *env, jobject thiz) {
    ALOGV("Java_jp_sacredsanctuary_helloworld_nativeaccess_NativeAccess_onServiceConnectedJNI");

    HelloAndroid *hello= HelloAndroid::getInstance();
    if (NULL != hello) {
        hello->notify(HELLO_ANDROID_SERVICE_CONNECTED, NULL);
    }
}

JNIEXPORT void JNICALL
Java_jp_sacredsanctuary_helloworld_nativeaccess_NativeAccess_onServiceDisconnected(
        JNIEnv *env, jobject thiz) {
    ALOGV("Java_jp_sacredsanctuary_helloworld_nativeaccess_NativeAccess_onServiceConnectedJNI");

    HelloAndroid *hello= HelloAndroid::getInstance();
    if (NULL != hello) {
        hello->notify(HELLO_ANDROID_SERVICE_DISCONNECTED, NULL);
    }
}
