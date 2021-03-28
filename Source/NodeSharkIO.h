#ifndef _NODESHARK_IO_H_
#define _NODESHARK_IO_H_

#include <stdint.h>

/* pin data type */
typedef uint8_t ns_pin_t;
/* ns_functions */
typedef enum 
{
    NS_IO_FUN_PWM       = 0,
    NS_IO_FUN_GPIO      = 1,
    NS_IO_FUN_ANALOGE   = 2
}ns_io_fun_t;

/* ns_dir */
typedef enum 
{
    NS_IO_DIR_INPUT     = 0,
    NS_IO_DIR_OUTPUT    = 1
}ns_io_dir_t;

/* ns_level */
typedef enum 
{
    NS_IO_LOW     = 0,
    NS_IO_HIGH    = 1
}ns_io_level_t;

/* Errors */
typedef enum
{
    NS_OK = 0,
    NS_NOK,
    NS_INTERNAL,
    NS_ERR_READ_COMMS,
    NS_ERR_WRITE_COMMS,
    NS_ERR_OPEN,
    NS_ERR_CLOSE
}ns_err_t;

/* Comm API structure */
typedef struct ns_comms
{
    uint8_t     (*ns_comms_open)    (void);
    uint8_t     (*ns_comms_close)   (void);
    uint8_t     (*ns_comms_read)    (uint8_t *data, uint8_t len);
    uint8_t     (*ns_comms_write)   (uint8_t *data, uint8_t len);
}ns_comms_api_instance_t;

/* IO Driver API structure */
typedef struct ns_io_driver
{
    uint8_t     (*ns_io_set_mode)       (ns_pin_t, ns_io_dir_t);
    uint8_t     (*ns_io_read)           (ns_pin_t, uint8_t*);
    uint8_t     (*ns_io_write_pwm)      (ns_pin_t, uint8_t*);
    uint8_t     (*ns_io_write_gpio)     (ns_pin_t, ns_io_level_t);
    uint8_t     (*ns_io_write_analoge)  (ns_pin_t, uint8_t*);
}ns_io_driver_t;

/* data field */
typedef struct data
{
    uint8_t len;
    uint8_t *data;
}NodeShark_Data_t;

/* NodeShark IO Structure */
typedef struct NodeShark_IO
{
    uint8_t ns_function;
    uint8_t ns_pin;
    uint8_t ns_dir;
    NodeShark_Data_t ns_data;
}NodeShark_IO_t;

/* Node shark Handler */
void ns_run();

/* Ack if data is available to process */
uint8_t ns_available();

/* setup the user comm driver */
void ns_comms_driver(ns_comms_api_instance_t*);
/* IO api setup */
void ns_io_driver(ns_io_driver_t * );

#endif