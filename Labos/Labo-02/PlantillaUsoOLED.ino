
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void setup()   {

  Serial.begin(9600);
  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
  display.setContrast (255); // dim display
 
 

  // Clear the buffer.
  display.clearDisplay();
  display.display();

}

void loop() {

  display.setTextSize(1); //set text size
  display.setTextColor(SH110X_WHITE); //set text color
  display.setCursor(20, 0);   // set cursor
  display.println("Texto o Variable");  //to print
  display.display();
  

}
