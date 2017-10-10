
#define MAX_ADDR 4096 //Take 2 to the power of the number of address lines

void setup() 
{ 
   Serial.begin(9600); // Opens Serial Port to receive data
   
<<<<<<< HEAD
   DDRL = B00000000;  //Sets up L register pins as 8-bit input 
   DDRA = B11111111;  //Lower address (A register pins)
   DDRC = B11111111;  //Upper address (C register pins)
=======
   /*
    *Sets up L-pins as 8-bit input A + C as 16 bit output
    */
   
   DDRL = B00000000; 
   DDRA = B11111111;  //Lower address
   DDRC = B11111111;  //Upper address
>>>>>>> d0c85a7447b102450b42ee327ca71672e6da813a

   PORTA = B00000000; //Sets output data on pin register A as 0
   PORTC = B00000000; //Sets output data on pin register C as 0

}

void loop() 
{ 

 uint16_t i;

 for(i = 0; i <= (MAX_ADDR - 1); ++i)
 {
    PORTA = i & 0xff;         //Sets the first half of "i" to PORTA, the lower address
    PORTC = (i >> 8) & 0xff;  //Sets the second half of "i" to PORTC, the upper address

    print_data(1);            //Call to print_data function, with option to print full diagnostic data on
 }

 delay(500);                  //500 millisecond delay, ensures that all data gets sent to Serial Monitor
 exit(0);                     //Program Halt

}

/*
 * Print data function
 * Prints the necessary address data and data collected with it as well
 * Uses a "full_data" boolean value to allow the printing of address and data or just data
 */

void print_data(bool full_data)
{

  if(full_data) //If data option is 1 (TRUE)
  {
    Serial.print(PINL, HEX);    //Print data received from L register pins
    Serial.print(" ");          //Print a space 
    Serial.print(PORTC, BIN);   //Print Upper Address
    Serial.print(" ");          //Print a space
    Serial.print(PORTA, BIN);   //Print Lower Address
    Serial.print("\n");
    
  }
  else                          //If data option is 0 (FALSE)
  {
    Serial.print(PINF, HEX);    //Print data received from L register pins
    Serial.print(" ");          //Print space
  }
}

