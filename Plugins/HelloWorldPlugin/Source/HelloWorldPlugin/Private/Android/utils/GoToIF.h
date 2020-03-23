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
#ifndef __GOTOIF_H__
#define __GOTOIF_H__

#include "Errors.h"
#include "log_main.h"

/*******************************
 * #define
 *******************************/
#define GOTO_IF_CORE(EXP, FUNC, TYPE, SET_ERROR_TYPE, SZEXP)        \
do {                                                                \
    TYPE tmpVal = (EXP);                                            \
    if (FUNC(tmpVal)) {                                             \
        SET_ERROR_TYPE;                                             \
        if (!status) {                                              \
            ALOGE("[ERROR] %s(%d) %s", __FILE__, __LINE__, SZEXP);  \
        }                                                           \
        goto Exit;                                                  \
    }                                                               \
}while(0)

#define GOTO_IF_NULL(EXP)       GOTO_IF_CORE(EXP, NULL ==, const void *, status = NO_MEMORY, #EXP)
#define GOTO_IF_ERROR(EXP)      GOTO_IF_CORE(EXP, OK !=, status_t, status = UNKNOWN_ERROR, #EXP)

#endif /* __GOTOIF_H__ */
