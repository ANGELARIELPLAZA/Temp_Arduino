#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_MLX90614.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);
int distance;

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
   Serial.begin(9600);
  while (!Serial);

  Serial.println("Adafruit MLX90614 test");

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };
}

void loop() {

  Serial.print("Object = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  float TEMP = mlx.readObjectTempC(); 
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(TEMP,1);
  lcd.print("\337C");
  Serial.println();
   // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(2000);
  
}
