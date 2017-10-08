# EPROM-Dumper
A sketch for the Arduino Mega that allows you to dump the contents of EPROM chips


## How it Works

The EPROM Dumper simply cycles through all the possible address locations while reading and printing data via the Serial Monitor. It isn't particularly pretty but it gets the job done if you just want to see what's on an old EPROM chip in a short amount of time.

As of now, the EPROM dumper program is designed for dumping the Intel D7232A-2 EPROM's although the code can easily be modified for EPROM's with more memory by editing the `MAX_ADDR` value to 2^(number of address lines) and connecting the unused pins of the C port register to the address pins of your EPROM. 

There are some pins that, because only a read operation is being performed, are set permanently to LOW. These pins include CE (Chip Enable) and OE/Vpp (Output Enable/Programming Voltage Input) with only Vcc (Usually +5V standard power input) being high and fed from the Arduino itself. 

More information about the D27232A-2 can be found here: [D27232A-2 Datasheet] (http://www.datasheets360.com/pdf/4657049655793235876)

The EPROM Dumper works as such:

1. Setup
   1. Serial port open to 9600 Baud (standard rate)
   2. Set pins on L port register as Input (This will be the data bus)
   3. Set pins on A and C port registers as Output (This will be the address bus)
      * A - Lower part of the address
      * C - Upper part of the address
   4. Set up output to be at 0 (Just in case)
2. Looped read
   1. Unsigned 16 bit integer is declared to hold the address
   2. FOR loop established, increments unsigned 16 bit address as counter (stops at maximum possible address combinations - 1)
       * First half of the unsigned integer is assigned to A port register
       * Second half of the unsigned integer is assigned to C port register
       * Data is printed using the "print_data" function in the program that shows both the address and data or just data
3. Termination
   1. 500 ms delay initiated (needed because of lag between data received on Arduino and transmitted to computer)
   2. `exit(0);` activated, stops the loop
   
## To-Do

These are things I might possibly consider doing with the program later in time. 

### High priority
* Experiment with increasing baud rate
* Find a better way to print data (alternative to Serial.print)
* Automatically save data into a text file

### Medium priority
* Add an LED status indicator (Busy/Complete)

### Low priority
* Add an LED decimal/LCD to show each byte read
* Add multiple LED's to indicate 25%, 50%, and 75% completion of read
* Use the Atmega328 DIP chip and create a dedicated reader
* Fabricate a ZIF shield for the Arduino Mega just for reading EPROM chips

      
