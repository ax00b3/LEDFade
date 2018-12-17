#define SWITCH_PIN 6   //make sure pullup resistor is enabled as appropriate
#define LED_PIN 9

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {

  //Wait for switch to go LOW:
  if (digitalRead(SWITCH_PIN) == LOW) {
    fadeLightUp();
  }
}

void fadeLightUp() {

  //fade up
  for (int brightness = 0; brightness < 255; brightness++) {
    analogWrite(LED_PIN, brightness);
    delay(50);   //modify depending how fast you want the fade
  }

  //Just loop here with LED_PIN high while switch is low
  while (digitalRead(SWITCH_PIN) == LOW) {
    delay(1000);
  }

  //If we're here, the swtich is HIGH again so fade down the light
  for (int brightness = 255; brightness > -1; brightness--) {
    analogWrite(LED_PIN, brightness);
    delay(50);   //modify depending how fast you want the fade
  }

  //return control to main loop, with led off

}
