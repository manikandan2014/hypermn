/**
********************************************************************************
\file   dllkcal.h

\brief  Definitions for kernel DLL CAL module

This file contains definitions for the kernel DLL CAL module

Copyright (c) 2012, SYSTEC electronik GmbH
Copyright (c) 2012, Bernecker+Rainer Industrie-Elektronik Ges.m.b.H. (B&R)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holders nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef _INC_dllkcal_H_
#define _INC_dllkcal_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <oplk/oplkinc.h>
#include <oplk/dll.h>
#include <common/dllcal.h>
#include <oplk/event.h>

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// typedef
//------------------------------------------------------------------------------
typedef struct
{
    ULONG       curTxFrameCountGen;
    ULONG       curTxFrameCountNmt;
    ULONG       curRxFrameCount;
    ULONG       maxTxFrameCountGen;
    ULONG       maxTxFrameCountNmt;
    ULONG       maxRxFrameCount;
} tDllkCalStatistics;

//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

tOplkError dllkcal_init(void);

tOplkError dllkcal_exit(void);

tOplkError dllkcal_getAsyncTxCount(tDllAsyncReqPriority* pPriority_p,
                                   UINT *pCount_p);

tOplkError dllkcal_getAsyncTxFrame(void* pFrame_p, UINT* pFrameSize_p,
                                   tDllAsyncReqPriority priority_p);

// only frames with registered AsndServiceIds are passed to CAL
tOplkError dllkcal_asyncFrameReceived(tFrameInfo* pFrameInfo_p);

tOplkError dllkcal_sendAsyncFrame(tFrameInfo* pFrameInfo_p, tDllAsyncReqPriority priority_p);

tOplkError dllkcal_writeAsyncFrame(tFrameInfo* pFrameInfo_p, tDllCalQueue dllQueue);

tOplkError dllkcal_clearAsyncBuffer(void);

tOplkError dllkcal_getStatistics(tDllkCalStatistics** ppStatistics);

tOplkError dllkcal_process(tEvent* pEvent_p);

#if defined(CONFIG_INCLUDE_NMT_MN)

tOplkError dllkcal_clearAsyncQueues(void);

tOplkError dllkcal_issueRequest(tDllReqServiceId service_p, UINT nodeId_p,
                                BYTE soaFlag1_p);

tOplkError dllkcal_getSoaRequest(tDllReqServiceId* pReqServiceId_p,
                                 UINT* pNodeId_p, tSoaPayload* pSoaPayload_p) SECTION_DLLKCAL_GETSOAREQ;

tOplkError dllkcal_setAsyncPendingRequests(UINT nodeId_p, tDllAsyncReqPriority asyncReqPrio_p,
                                           UINT count_p);

#endif


#ifdef __cplusplus
}
#endif

#endif /* _INC_dllkcal_H_ */


