#include <IRremote.h>// load IRremote library
#include "TM1637.h" // load segment display library
#define CLK 4
#define DIO 5
TM1637 tm1637(CLK, DIO);
IRrecv ir(A0);// an instance of the IR receiver object A0 is IRreceive pin
decode_results result;// container for receiver IR codes
long codes[10] =
{ 0xFD708F,0xFD08F7,0xFD8877,0xFD48B7,0xFD28D7,0xFDA857, //0 1 2 3 4 5                
   0xFD6897,0xFD18E7, 0xFD9867,0xFD58A7}; // 6 7 8 9
void setup() {
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);
  ir.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  if(ir.decode(&result))
  {
    int i =-1;
    while(!((i > 9) || (result.value == codes[++i])))
    {
      Serial.println(i);
    }
    ir.resume(); // resume receiver
    if(i < 10)
    {
      tm1637.clearDisplay();
      Serial.print("viduj");
      Serial.println(i);
      tm1637.display(3, i);// IRremote value
    }
    
  }
}
