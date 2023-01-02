//Importar las librerias a utilizar
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
//NO BORRAR
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's

//NO BORRAR
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
//Inicializa la configuración de la pantalla
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 


void setup()   {
  Serial.begin(115200);
  
  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
  display.setContrast (255); // dim display
 
  // Clear the buffer.
  display.clearDisplay();
  display.display();
}

void loop() {
  //set text size, 1 es 8px, 2 es 16px, 3, es 32px, etc.
  display.setTextSize(1); 
  //Set text color define el color del texto de la pantalla
  display.setTextColor(SH110X_WHITE); 
  //Set cursor coloca el cursor en donde se va a comenzar escribir (px ancho, px alto)
  display.setCursor(20, 0);
  //Println permite escribir en la posicion en la que se encuentra el cursor
  display.println("Texto o Variable");

  //Para imprimir otro dato, se coloca nuevamente el cursor bajando la columna
  display.setCursor(20, 11);
  display.println("Nueva info");

  //Para guardar los cambios hechos en la pantalla
  display.display();
  
  //Se borra la pantalla para que no se monten los datos
  display.clearDisplay();
}
