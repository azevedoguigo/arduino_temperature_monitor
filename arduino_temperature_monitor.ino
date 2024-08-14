#include <Thermistor.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGH 64

#define OLED_RESET -1

Thermistor temp(2);

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGH,
  &Wire,
  OLED_RESET
);

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Fail to init display SSD1306!"));
    for(;;);
  }

  display.clearDisplay();
}

void loop() {
  int temperature = temp.getTemp();
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15, 1);

  display.println("Temperatura atual");

  display.setTextSize(2);
  display.setCursor(40, 35);
  display.print(temperature);
  display.setCursor(65, 30);
  display.write(248);
  display.setCursor(77, 35);
  display.println("C");

  display.display();

  delay(500);
}
