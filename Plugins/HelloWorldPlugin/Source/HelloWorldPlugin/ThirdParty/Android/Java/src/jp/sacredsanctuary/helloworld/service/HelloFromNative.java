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
package jp.sacredsanctuary.helloworld.service;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;

import java.lang.ref.WeakReference;

import jp.sacredsanctuary.helloworld.HelloActivity;

public class HelloFromNative {
    private static WeakReference<HelloFromNative> mHelloFromNative = null;
    private Context mContext;
    private static HelloFromNative getInstance(Context context) {
        return (mHelloFromNative != null) ?
                mHelloFromNative.get() : new HelloFromNative(context);
    }

    private static void setInstance(WeakReference<HelloFromNative> ble) {
        mHelloFromNative = ble;
    }

    private static void setupFromNative(Context context) {
        if (context == null) return;
        getInstance(context);
    }

    private HelloFromNative(Context context) {
        mContext = context;
        setInstance(new WeakReference<>(this));
    }

    private static void startHelloActivityFromNative(Context context) {
        if (context == null) return;
        HelloFromNative hello = getInstance(context);
        hello.startHelloActivity();
    }

    private void startHelloActivity() {
        Intent intent = new Intent(mContext, HelloActivity.class);
        mContext.startActivity(intent);
    }
}
