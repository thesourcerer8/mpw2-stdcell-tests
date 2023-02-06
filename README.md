# mpw2-stdcell-tests
Test-cases for the Sky130-MPW2 Standard Cell Tests

The original Standard Cell Test Design that was submitted to Sky130 MPW2 is a collection of digital CMOS standard cells that were automatically layouted with the Libresilicon StdCellLib toolchain. Those standard cells are placed and connected to the IOs and to the Logic Analyzer:

* IO2=AND(0,1)
* IO5=AND(3,4)
* IO9=AOI(8,7,6)
* IO20=BUF(19)
* IO22=INV(21)
* IO34=MUX(31,32,33)
* IO37=NAND(35,36)

The gpin Test is testing the GPIO Inputs, they are attached to the management CPU, and the CPU is repeatedly doing an XOR over all the input pins 0-31, and using the LED D3 on the Hat as an output. This way any IO changes on any of the inputs should be visible on the LED

The StdCell Tests are enabling the IOs to the Standard cells in the Userspace and testing them with test-code on the Nucleo MicroPython environment.

The fake-test is simulating the standard cells in the userspace by Caravel firmware that reads the inputs and generates he outputs. This way we can execute tests even if the standard cells in silicon turn out not to work correctly. Additionally you can turn any Caravel based chip with this firmware into one that behaves like our design, so anyone with a Nucleo+Hat+Caravel can reproduce our standard-cell tests


How to use these tests?
This repository needs to be cloned in the firmware_vex directory of the caravel_board repository:
```
git clone https://github.com/efabless/caravel_board
cd caravel_board/firmware_vex
git clone https://github.com/thesourcerer8/mpw2-stdcell-tests
cd nucleo
make run PART=Cxy
make get_config
cd ..
cd mpw2-stdcell-tests/gpin-tests
cp ../../nucleo/gpio_config_def.py .
make flash_nucleo
```
