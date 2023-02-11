#include "../defs.h"
#include "../gpio_config/gpio_config_io.c"

// --------------------------------------------------------
// Firmware routines
// --------------------------------------------------------

void set_registers() {

    reg_mprj_io_5 = GPIO_MODE_MGMT_STD_INPUT_NOPULL; // Rx
    reg_mprj_io_6 = GPIO_MODE_MGMT_STD_OUTPUT; // Tx

}

void main()
{
    int i;
    reg_gpio_mode1 = 1;
    reg_gpio_mode0 = 0;
    reg_gpio_ien = 1;
    reg_gpio_oe = 1;

#ifdef reg_uart_clkdiv
    reg_uart_clkdiv=10417; // If the speed is 12.5MHz then this would give 9600 baud
#endif
    reg_uart_enable=1;

    reg_mprj_xfer = 1; 

    set_registers();
    reg_mprj_datah = 0;
    reg_mprj_datal = 0;
    gpio_config_io();

    //reg_gpio_out = 1; // OFF
//    print("Hello World");
 
    while(1)
    {
      //reg_gpio_out=0;
 
      for(i='A'; i<='Z'; i++)
      {
        //while(reg_uart_txfull==1)     
        reg_uart_data=i;
        delay(5000);

      }

      //reg_gpio_out=1;
      //delay(5000);
    }

}
