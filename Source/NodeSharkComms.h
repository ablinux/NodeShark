#ifndef _NSCOMMS_H_
#define _NSCOMMS_H_

#include <stdint.h>


/* Comm API structure */
typedef struct ns_comms
{
    uint8_t     (*ns_comms_open)    (void);
    uint8_t     (*ns_comms_close)   (void);
    uint8_t     (*ns_comms_read)    (uint8_t *data, uint8_t len);
    uint8_t     (*ns_comms_write)   (uint8_t *data, uint8_t len);
}ns_comms_api_instance_t;

/* setup the user comm driver */
void ns_comms_driver(ns_comms_api_instance_t*);

/* NodeShark IO to access the NodeShark Comms driver apis */
void *ns_get_comm_driver();

#endif