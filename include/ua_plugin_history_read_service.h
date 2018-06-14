/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *    Copyright 2018 (c) basysKom GmbH <opensource@basyskom.com> (Author: Peter Rustler)
 */

#ifndef UA_PLUGIN_HISTORY_READ_SERVICE_H_
#define UA_PLUGIN_HISTORY_READ_SERVICE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ua_types.h"
#include "ua_server.h"

typedef struct {
    void *context;


    void (*read_raw)(UA_Server *server,
                     const UA_NodeId *sessionId,
                     void *sessionContext,
                     const UA_HistoryReadRequest *request,
                     const UA_ReadRawModifiedDetails *details,
                     UA_HistoryReadResponse *response);

    // Add more function pointer here.
    // For example for read_event, read_modified, read_processed, read_at_time
} UA_HistoryReadService;

#ifdef __cplusplus
}
#endif

#endif /* UA_PLUGIN_HISTORY_READ_SERVICE_H_ */
