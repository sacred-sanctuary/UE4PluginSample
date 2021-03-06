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

import android.content.ComponentName;
import android.content.ServiceConnection;
import android.os.IBinder;

public class HelloServiceConnection implements ServiceConnection {
    private final ServiceConnection mCallback;
    public HelloServiceConnection(ServiceConnection callback) {
        mCallback = callback;
    }
    @Override
    public void onServiceConnected(ComponentName name, IBinder service) {
        mCallback.onServiceConnected(name, service);
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {
        mCallback.onServiceDisconnected(name);
    }
}
