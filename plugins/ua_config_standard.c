#include "ua_config_standard.h"

#define MANUFACTURER_NAME "open62541.org"
#define PRODUCT_NAME "open62541 OPC UA Server"
#define PRODUCT_URI "urn:unconfigured:open62541"
#define APPLICATION_NAME "open62541-based OPC UA Application"
#define APPLICATION_URI "urn:unconfigured:application"

#define UA_STRING_STATIC(s) {sizeof(s)-1, (UA_Byte*)s}
#define UA_STRING_STATIC_NULL {0, NULL}

UA_UsernamePasswordLogin usernamePasswords[2] = {
    { UA_STRING_STATIC("user1"), UA_STRING_STATIC("password") },
    { UA_STRING_STATIC("user2"), UA_STRING_STATIC("password1") } };

const UA_ServerConfig UA_ServerConfig_standard = {
    .nThreads = 1,
    .logger = Logger_Stdout,

    /* Server Description */
    .buildInfo = {
        .productUri = UA_STRING_STATIC(PRODUCT_URI),
        .manufacturerName = UA_STRING_STATIC(MANUFACTURER_NAME),
        .productName = UA_STRING_STATIC(PRODUCT_NAME),
        .softwareVersion = UA_STRING_STATIC("0"),
        .buildNumber = UA_STRING_STATIC("0"),
        .buildDate = 0 },
    .applicationDescription = {
        .applicationUri = UA_STRING_STATIC(APPLICATION_URI),
        .productUri = UA_STRING_STATIC(PRODUCT_URI),
        .applicationName = { .locale = UA_STRING_STATIC(""),
                             .text = UA_STRING_STATIC(APPLICATION_NAME) },
        .applicationType = UA_APPLICATIONTYPE_SERVER,
        .gatewayServerUri = UA_STRING_STATIC_NULL,
        .discoveryProfileUri = UA_STRING_STATIC_NULL,
        .discoveryUrlsSize = 0,
        .discoveryUrls = NULL },
    .serverCertificate = UA_STRING_STATIC_NULL,

    /* Networking */
    .networkLayersSize = 0,
    .networkLayers = NULL,

    /* Login */
    .enableAnonymousLogin = true,
    .enableUsernamePasswordLogin = true,
	.authCallback = NULL,
    .usernamePasswordLogins = usernamePasswords,
    .usernamePasswordLoginsSize = 2,

    /* Limits for SecureChannels */
    .maxSecureChannels = 100,
    .maxSecurityTokenLifetime = 10 * 60 * 1000, /* 10 minutes */

    /* Limits for Sessions */
    .maxSessions = 100,
    .maxSessionTimeout = 60.0 * 60.0 * 1000.0, /* 1h */

    /* Limits for Subscriptions */
    .publishingIntervalLimits = { .min = 100.0, .max = 3600.0 * 1000.0 },
    .lifeTimeCountLimits = { .max = 15000, .min = 3 },
    .keepAliveCountLimits = { .max = 100, .min = 1 },
    .maxNotificationsPerPublish = 1000,

    /* Limits for MonitoredItems */
    .samplingIntervalLimits = { .min = 50.0, .max = 24.0 * 3600.0 * 1000.0 },
    .queueSizeLimits = { .max = 100, .min = 1 }
};

const UA_EXPORT UA_ClientConfig UA_ClientConfig_standard = {
    .timeout = 5000,
    .secureChannelLifeTime = 600000,
    .logger = Logger_Stdout,
    .localConnectionConfig = {
        .protocolVersion = 0,
        .sendBufferSize = 65536,
        .recvBufferSize  = 65536,
        .maxMessageSize = 65536,
        .maxChunkCount = 1 },
    .connectionFunc = UA_ClientConnectionTCP
};
