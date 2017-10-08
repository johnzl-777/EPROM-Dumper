
#define MAX_ADDR 4096 //Take 2 to the power of the number of address lines

void setup() 
{ 
   Serial.begin(9600); // Opens Serial Port to receive data
   
   DDRL = B00000000;  //Sets up L-pins as 8-bit input A + C as 16 bit output
   DDRA = B11111111;  //Lower address
   DDRC = B11111111;  //Upper address

   PORTA = B00000000; //Sets output data on pin register A as 0
   PORTC = B00000000; //Sets output data on pin register C as 0

}

void loop() 
{ 

 uint16_t i;

 for(i = 0; i <= (MAX_ADDR - 1); ++i)
 {
    PORTA = i & 0xff;
    PORTC = (i >> 8) & 0xff;

    print_data(1);
 }

 delay(500);
 exit(0);

}

void print_data(bool full_data)
{

  if(full_data)
  {
    Serial.print(PINL, HEX);
    Serial.print(" ");
    Serial.print(PORTC, BIN);
    Serial.print(" ");
    Serial.print(PORTA, BIN);
    Serial.print("\n");
    
  }
  else
  {
    Serial.print(PINF, HEX);
    Serial.print(" ");
  }
}

