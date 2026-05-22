#include <LiquidCrystal.h>

int pinA = 22;
int pinB = 28;
int pinC = 27;
int pinD = 26;
int pinE = 25;
int pinF = 24;
int pinG = 23;
int pinDP = 22;

int gnd1 = 36; 
int gnd2 = 35; 
int gnd3 = 34; 
int gnd4 = 33; 
int backlight_pin=31;

LiquidCrystal lcd(36, 37, 26, 27, 28, 29);

int counter = 1;
unsigned long lastIncrementTime = 0;
const long interval = 1000; 

void displayDigit(int digit, int targetGnd); 

void setup() {
  pinMode(pinA, OUTPUT); pinMode(pinB, OUTPUT); pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT); pinMode(pinE, OUTPUT); pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT); pinMode(pinDP, OUTPUT);

  pinMode(gnd1, OUTPUT); digitalWrite(gnd1, HIGH);
  pinMode(gnd2, OUTPUT); digitalWrite(gnd2, HIGH);
  pinMode(gnd3, OUTPUT); digitalWrite(gnd3, HIGH);
  pinMode(gnd4, OUTPUT); digitalWrite(gnd4, HIGH);
  pinMode(backlight_pin,OUTPUT);
  analogWrite(backlight_pin,255);
  lcd.begin(16, 2);
  lcd.print("Counter:");
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastIncrementTime >= interval) {
    lastIncrementTime = currentTime;
    counter++;
    
    if (counter > 9999) {
      counter = 1; 
    }


  }

  int thousands = (counter / 1000) % 10;
  int hundreds  = (counter / 100) % 10;
  int tens      = (counter / 10) % 10;
  int ones      = counter % 10;
 lcd.setCursor(0, 0);
 lcd.print("Counter: ");
 lcd.print(thousands);
 lcd.print(hundreds);
 lcd.print(tens);
 lcd.print(ones);
 lcd.print(" "); 
  if (counter >= 1000) {
    displayDigit(thousands, gnd1);
  }
  if (counter >= 10) { 
    if (counter >= 100) {
      displayDigit(hundreds, gnd2);
    }
    displayDigit(tens, gnd3);
  }
  displayDigit(ones, gnd4);
}

void displayDigit(int digit, int targetGnd) {
  
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, LOW);

  
  digitalWrite(gnd1, LOW);
  digitalWrite(gnd2, LOW);
  digitalWrite(gnd3, LOW);
  digitalWrite(gnd4, LOW);

  
  switch (digit) {
    case 0: 
      digitalWrite(pinA, HIGH); 
      digitalWrite(pinC, HIGH); 
      digitalWrite(pinD, HIGH); 
      digitalWrite(pinG, HIGH); 
      digitalWrite(pinF, HIGH); 
      digitalWrite(pinE, HIGH); 
      break;
      
    case 1:
      digitalWrite(pinG, HIGH); 
      digitalWrite(pinF, HIGH); 
      break;
      
    case 2: 
      digitalWrite(pinA, HIGH); 
      digitalWrite(pinG, HIGH); 
      digitalWrite(pinB, HIGH); 
      digitalWrite(pinD, HIGH); 
      digitalWrite(pinE, HIGH); 
      break;
      
    case 3: 
      digitalWrite(pinA, HIGH); 
      digitalWrite(pinG, HIGH); 
      digitalWrite(pinB, HIGH); 
      digitalWrite(pinF, HIGH); 
      digitalWrite(pinE, HIGH); 
      break;
      
    case 4:
      digitalWrite(pinC, HIGH); 
      digitalWrite(pinB, HIGH); 
      digitalWrite(pinG, HIGH); 
      digitalWrite(pinF, HIGH); 
      break;
      
    case 5: 
      digitalWrite(pinA, HIGH); 
      digitalWrite(pinC, HIGH); 
      digitalWrite(pinB, HIGH); 
      digitalWrite(pinF, HIGH); 
      digitalWrite(pinE, HIGH); 
      break;
      
    case 6: 
      digitalWrite(pinA, HIGH); 
      digitalWrite(pinC, HIGH); 
      digitalWrite(pinD, HIGH); 
      digitalWrite(pinB, HIGH); 
      digitalWrite(pinF, HIGH); 
      digitalWrite(pinE, HIGH); 
      break;
      
    case 7: 
      digitalWrite(pinA, HIGH); 
      digitalWrite(pinG, HIGH); 
      digitalWrite(pinF, HIGH); 
      break;
      
    case 8: 
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
      
    case 9:
      digitalWrite(pinA, HIGH); 
      digitalWrite(pinC, HIGH); 
      digitalWrite(pinB, HIGH); 
      digitalWrite(pinG, HIGH); 
      digitalWrite(pinF, HIGH); 
      digitalWrite(pinE, HIGH); 
      break;
      
    default:
      break;
  }

  
  digitalWrite(targetGnd, HIGH);
  delay(4); 
  digitalWrite(targetGnd, LOW);
}