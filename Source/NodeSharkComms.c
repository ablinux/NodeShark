#include "NodeSharkComms.h"

/* local var for keeping the record of comms api instance */
static ns_comms_api_instance_t *g_ns_comms;

/* NodeShark IO to access the NodeShark Comms driver apis */
void *ns_get_comm_driver()
{
    return g_ns_comms;
}

/* communication api setup */
void ns_comms_driver(ns_comms_api_instance_t* user_comms)
{
    g_ns_comms = user_comms;
    g_ns_comms->ns_comms_open();
}