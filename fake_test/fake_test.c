#include "../defs.h"
#include "../gpio_config/gpio_config_io.c"

// --------------------------------------------------------
// Firmware routines
// --------------------------------------------------------

void set_registers() {

    reg_mprj_io_0 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_1 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_2 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_3 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_4 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_5 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_6 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_7 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_8 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_9 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_10 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_11 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_12 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_13 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_14 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_15 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_16 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_17 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_18 = GPIO_MODE_MGMT_STD_OUTPUT;

    reg_mprj_io_19 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_20 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_21 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_22 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_23 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_24 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_25 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_26 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_27 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_28 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_29 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_30 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_31 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_32 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_33 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_34 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_35 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_36 = GPIO_MODE_MGMT_STD_INPUT_PULLUP;
    reg_mprj_io_37 = GPIO_MODE_MGMT_STD_OUTPUT;

}

void main()
{
    reg_gpio_mode1 = 1;
    reg_gpio_mode0 = 0;
    reg_gpio_ien = 1;
    reg_gpio_oe = 1;

    set_registers();
    reg_mprj_datah = 0;
    reg_mprj_datal = 0;
    gpio_config_io();

    reg_gpio_out = 1; // OFF

    while(1)
    {
      int gpin=reg_mprj_datal; // Retrieving the GPIO values from the Input GPIOs
      int gpinh=reg_mprj_datah;

      int gpout=0x0; // Preparing the output value
      int gpouth=0x0;
      // Simulating Standard cell functions
      reg_gpio_out=gpin&1;

      gpout |= ((((gpin>>0)&1) && ((gpin>>1)&1))<<2); // 0&1=2  AND2X1
      gpout |= ((((gpin>>3)&1) && ((gpin>>4)&1))<<5); // 3&4=5  AND2X2
      gpout |= ((1^(((gpin>>6)&1) && ((gpin>>7)&1) || ((gpin>>8)&1)))<<9); // !(6&7|8)=9 OAI21

      gpout |= ((1^(((gpin>>10)&1) && ((gpin>>11)&1) || ((gpin>>12)&1) && ((gpin>>13)&1)))<<14); // !(6&7|8)=9 OAI22
      gpout |= ((gpin>>15)&1)<<16; //15=16 BUF
      gpout |= ((gpin>>17)&1)<<18; //17=18 BUF
      gpout |= ((gpin>>19)&1)<<20; //19=20 BUF
      gpout |= (1^((gpin>>21)&1))<<22; // INV
      gpout |= (1^((gpin>>23)&1))<<24; // INV
      gpout |= (1^((gpin>>25)&1))<<26; // INV
      gpout |= (1^((gpin>>27)&1))<<28; // INV
      gpout |= (1^((gpin>>29)&1))<<30; // INV
      gpouth |= (((gpinh>>1)&1)?(gpin>>31)&1:(gpinh>>0)&1)<<2; // 33?31:32=34 MUX
      gpouth |= ((1^(((gpinh>>3)&1) && ((gpinh>>4)&1)))<<5); // !35&36=37 NAND

      reg_mprj_datal = gpout;
      reg_mprj_datah = gpouth;

      reg_gpio_out=1;
      delay(500000);


    }

}
