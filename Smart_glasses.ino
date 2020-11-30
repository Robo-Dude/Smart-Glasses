#include <dht11.h>
#include<SoftwareSerial.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
char c;

SoftwareSerial bluetoothSerial(7, 8);
#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);
dht11 DHT11; // create object of DHT11
#define dhtpin 3 // set the pin to connect to DHT11

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  bluetoothSerial.begin(9600);
  Serial.begin(115200);
   display.clearDisplay();
    display.display(); 
  }

void loop() 
{ DHT11.read(dhtpin);// initialize the reading
  //code for Robojax.com video
  int humidity = DHT11.humidity;// get humidity
   Serial.print("Temperture");
   Serial.print(getTemp('C'));
   Serial.print("C ");
   Serial.print(" humidity:");
   Serial.print (humidity);
   Serial.println("% ");
   Serial.println();
   delay(500);
   display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  
  if(bluetoothSerial.available()>0)
 {
  c=bluetoothSerial.read();
  
   Serial.print(c);
   if (c=='t')
    { display.clearDisplay();
      display.print("Temperture   ");
      display.print(getTemp('C'));
      display.print(" C");
      delay(1000);
}
 
  if (c=='h')
  {
     display.clearDisplay();
     display.println("      HI");
  }
  if (c=='c')
  {
    display.clearDisplay();
    
  }
   if (c=='9')
  {
     display.clearDisplay();
     display.println("How are      you ?");
  }
   if (c=='0')
  {
     display.clearDisplay();
     display.println(" Smart     Glasses");
  }
   if (c=='8')
  {
     display.clearDisplay();
     display.println("Hari bhai");
  }
   if (c=='7')
  {
     display.clearDisplay();
     display.println("  Pretty    Girl");
  }
   if (c=='4')
  {
     display.clearDisplay();
     display.println("");
  }

  display.display();
 }
}
int getTemp(char type) {
    int temp = (float)DHT11.temperature;//get temp
  
   return temp; 
}
   
 
