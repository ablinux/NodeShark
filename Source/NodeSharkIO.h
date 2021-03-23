#ifndef _NODESHARK_IO_H_
#define _NODESHARK_IO_H_

#include <stdint.h>

/* NodeShark IO Structure */
typedef struct NodeShark_IO
{
    uint8_t ns_function;
    uint8_t ns_pin;
    uint8_t ns_data;
    uint8_t ns_dir;
}NodeShark_IO_t;


/* Node shark Handler */
void ns_run();

#endif