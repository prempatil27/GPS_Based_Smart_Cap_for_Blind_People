#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial Gsm(8, 9);
char phoneno[] = "+91xxxxxxxxxx"; // Phone number to send SMS. Replace x with the number
TinyGPS gps;
int state;
String textMessage;

void setup() {
  Serial.begin(9600);
  Gsm.begin(9600);

  // Set GSM module to text mode
  Serial.print("AT+CMGF=1\r");
  delay(100);
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);

  // Initialize push button pins
  pinMode(11, INPUT);
}

void loop() {
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // Read data from GPS module
  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (Serial.available()) {
      char c = Serial.read();
      Serial.print(c);
      if (gps.encode(c)) {
        newData = true;
      }
    }
  }

  if (Gsm.available() > 0) {
    textMessage = Gsm.readString();
    textMessage.toUpperCase();
    delay(10);
  }

  Serial.println(failed);

  // Check the state of the push button
  state = digitalRead(11);
  if (state == 0) {
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);

    // Send SMS with location data
    Gsm.print("AT+CMGF=1\r");
    delay(400);
    Gsm.print("AT+CMGS=\"");
    Gsm.print(phoneno);
    Gsm.println("\"");
    Gsm.println("Alert I need help.............");
    Gsm.print("http://maps.google.com/maps?q=loc:");
    Gsm.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Gsm.print(", ");
    Gsm.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    delay(200);
    Gsm.println((char)26);
    delay(200);
    Gsm.println();
    Serial.println("SMS Sent");

    // Make a phone call
    Serial.println("Call");
    delay(20000);
    Gsm.println("ATD+91xxxxxxxxxx;");
    delay(150000);
    Gsm.println("ATH");
    delay(1000);
  } else {
    delay(10);
  }
}
