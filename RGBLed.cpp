// You can load this one file as your main sketch
// with an arduino nano
// 
// copied from https://create.arduino.cc/projecthub/muhammad-aqib/arduino-rgb-led-tutorial-fc003e
//
int red_light_pin= 3;
int green_light_pin = 5;
int blue_light_pin = 6;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  while (Serial.available() > 0) {
      // look for the next valid integer in the incoming serial stream:
      int red = Serial.parseInt(); 
      // do it again:
      int green = Serial.parseInt(); 
      // do it again:
      int blue = Serial.parseInt(); 

      // look for the newline. That's the end of your
      // sentence:
      if (Serial.read() == '\n') {
        // constrain the values to 0 - 255 and invert
        // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
        red = constrain(red, 0, 255);
        green = constrain(green, 0, 255);
        blue = constrain(blue, 0, 255);
        RGB_color(red, green, blue);
        delay(500);
      }
  }

}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
