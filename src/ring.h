/* @@@LICENSE
*
*      Copyright (c) 2007-2013 LG Electronics, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */

/**
 ***********************************************************************
 * @file ring.h
 *
 * @brief This file contains definition of ring buffer related functions.
 *
 ***********************************************************************
 */


#ifndef PMLOGDAEMON_RING_H
#define PMLOGDAEMON_RING_H

#include <stdbool.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "print.h"

typedef struct
{
	bool isEmpty;
	int bufferSize;
	int flushLevel;
	char* buff;
	char* nextWritePos;
}
PmLogRingBuffer_t;

static const int RBMinBufferSize = 2048; /* Minimum is 2K */

typedef void (*RBTraversalFunc)(const char* msg, gpointer data);

PmLogRingBuffer_t* RBNew(int bufferSize, int flushLevel);

bool RBFlush(PmLogRingBuffer_t* rb, RBTraversalFunc flushMsgFunc, gpointer data);
void RBWrite(PmLogRingBuffer_t* rb, const char *buffMsg, int numBytes);

#endif
