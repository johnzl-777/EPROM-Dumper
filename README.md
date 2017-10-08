# EPROM-Dumper
A sketch for the Arduino Mega that allows you to dump the contents of EPROM chips

___

## How it Works

The EPROM Dumper simply cycles through all the possible address locations while reading and printing data via the Serial Monitor. It isn't particularly pretty but it gets the job done if you just want to see what's on an old EPROM chip in a short amount of time.

The EPROM Dumper works as such:

1. Setup
  1. Serial port open to 9600 Baud (standard rate)
  2. Set pins on L port register as Input (This will be the data bus)
  3. Set pins on A and C port registers as Output (This will be the address bus)
    * A - Lower part of the address
    * B - Upper part of the address
