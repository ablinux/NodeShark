#include <stdio.h>
#include <stdint.h>
#include "NodeSharkIO.h"
#include "NodeSharkComms.h"
/* create fake comm driver */
uint8_t fake_comms_open(void);
uint8_t fake_comms_close(void);
uint8_t fake_write(uint8_t*data,uint8_t len);
uint8_t fake_read(uint8_t*data,uint8_t len);

/* fake io driver */
uint8_t     fake_io_set_mode       (ns_pin_t, ns_io_dir_t);
uint8_t     fake_io_read           (ns_pin_t, uint8_t*);
uint8_t     fake_io_write_pwm      (ns_pin_t, uint8_t*);
uint8_t     fake_io_write_gpio     (ns_pin_t, ns_io_level_t);
uint8_t     fake_io_write_analoge  (ns_pin_t, uint8_t*);

/* boiler plat code to setup the comms api*/
ns_comms_api_instance_t g_comms={.ns_comms_open = fake_comms_open,
                                .ns_comms_close = fake_comms_close,
                                .ns_comms_read = fake_read,
                                .ns_comms_write = fake_write};

/* IO driver setup */
ns_io_driver_t g_IO = {
    .ns_io_read = fake_io_read,
    .ns_io_set_mode = fake_io_set_mode,
    .ns_io_write_analoge = fake_io_write_analoge,
    .ns_io_write_gpio = fake_io_write_gpio,
    .ns_io_write_pwm = fake_io_write_pwm
};

void main()
{
    /* setup code */
    ns_comms_driver(&g_comms);
    
    /*setup io driver */
    ns_io_driver(&g_IO);

    /* Run code */
    while(1)
    {
        ns_run();
    }
}

/* create fake comm driver */
uint8_t fake_comms_open(void)
{
    printf("Driver Open\n");

}
uint8_t fake_comms_close(void)
{
    printf("Driver Close\n");
}
uint8_t fake_write(uint8_t*data,uint8_t len)
{
    printf("Driver Writting %d bytes amound of data\n",len);
}
uint8_t fake_read(uint8_t*data,uint8_t len)
{
    printf("Driver reading %d bytes amount of data\n",len);
}

uint8_t     fake_io_set_mode       (ns_pin_t pin, ns_io_dir_t mode)
{

}
uint8_t     fake_io_read           (ns_pin_t pin, uint8_t* fakedata)
{

}
uint8_t     fake_io_write_pwm      (ns_pin_t pin, uint8_t* fakedata)
{

}
uint8_t     fake_io_write_gpio     (ns_pin_t pin, ns_io_level_t level)
{

}
uint8_t     fake_io_write_analoge  (ns_pin_t pin, uint8_t* data)
{

}