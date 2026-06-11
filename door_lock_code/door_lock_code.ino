#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>
const String SYSTEM_PASSWORD = "1234"; 

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo srv;
String pass = "";

char keys[4][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}, {'*','0','#'}};
byte rPins[4] = {2, 3, 4, 5}; 
byte cPins[3] = {6, 7, 8};
Keypad kpd = Keypad(makeKeymap(keys), rPins, cPins, 4, 3);

void setup() {
  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight();
  srv.attach(9); 
  srv.write(0);
  
  // Boot Sequence
  lcd.setCursor(0, 0); 
  lcd.print("Loading.......");
  lcd.setCursor(0, 1); 
  lcd.print("piter did it");
  delay(2000); 
  
  resetForNextUser();
}

void loop() {
  char Key = kpd.getKey();
  
  if (Key) {
    if (Key == '#') {
      if (pass == SYSTEM_PASSWORD) {
        lcd.setCursor(0, 1); 
        lcd.print("correct pin   ");
        Serial.print("correct pin");
        srv.write(180);
        delay(4000); 
        resetForNextUser();
      } 
      else {
        lcd.setCursor(0, 1); 
        lcd.print("incorrect pin ");
        Serial.print("incorrect pin");
        srv.write(0);
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0); 
        lcd.print("press * to try");
        lcd.setCursor(0, 1);
        lcd.print("again");
        pass = "";
      }
    }
    else if (Key == '*') {
      resetForNextUser();
    }
    else {
      if (pass.length() < 4) {
        pass += Key;
        lcd.setCursor(pass.length() - 1, 0); 
        lcd.print("*");
        Serial.println("*");
      }} }}
void resetForNextUser() {
  pass = "";
  srv.write(0); 
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("enter pin");
  Serial.print("enterpin");
}
