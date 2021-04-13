#include "NodeSharkIO.h"
#include "NS_XF.h"
#include "NodeSharkComms.h"

static ns_io_driver_t *g_ns_io;
static ns_comms_api_instance_t *g_ns_comms;
/* Node shark Handler */
/* ns_run is should be executed by user in a loop to handle all the event received by phy or wireless protocol ns_recv()
 ns_run then parse the packet NodeShark_IO_t to perform the action to the IO */
void ns_run()
{
    /* local var to store the data */
    static uint8_t rcvdData[30];
    /* Errors*/
    uint8_t error;
    /* Local var for NS_IO */
    static NodeShark_IO_t data;
    /* check if data is received */
    
    /*Get comms driver */
    g_ns_comms = ns_get_comm_driver();
    /*Read the buffer */
    error = g_ns_comms->ns_comms_read(rcvdData,sizeof(NodeShark_IO_t));
    if(NS_OK == error)
    {
    
        /* De-Stream the data */
        DeStream_NodeShark_IO_t(rcvdData, &data);
    
        /*Parse the data */
        switch (data.ns_function)
        {
        case NS_IO_FUN_GPIO:
            /* make sure IO pin is in correct state */
            g_ns_io->ns_io_set_mode(data.ns_pin,data.ns_dir);
            /* write data */
            break;
        case NS_IO_FUN_PWM:
            break;
        case NS_IO_FUN_ANALOGE:
            break;
        default:
            break;
        }
    }
    
}

/* IO api setup */
void ns_io_driver(ns_io_driver_t * user_IO)
{
    g_ns_io = user_IO;
}