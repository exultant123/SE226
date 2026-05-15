int LED0pin = 43;
int LED1pin = 44;
int LED2pin = 45;
int LED3pin = 46;
int button1pin = 39;
int button2pin = 40;
byte prevbutton1state = LOW;
byte prevbutton2state = LOW;
byte led1State = LOW;
byte globalState = LOW;
int mod = 0;
int cur = 0;
byte blink = HIGH;
unsigned long lastUpdateTime = 0;
int interval = 1000; 
int prevmod=0;

void setup() {
pinMode(LED1pin, OUTPUT);
pinMode(LED2pin, OUTPUT);
pinMode(LED3pin, OUTPUT);
pinMode(LED0pin, OUTPUT);
pinMode(button1pin, INPUT);
pinMode(button2pin, INPUT);
}
void loop() {
// Read button states here.
// Write your LED control code here.
 byte button1state = digitalRead(button1pin);
 byte button2state = digitalRead(button2pin);


 if (button1state==HIGH && prevbutton1state == LOW) {

  // led1State = !led1State;
  globalState = !globalState;
  // digitalWrite(LED0pin,globalState);
  // digitalWrite(LED1pin,globalState);
  // digitalWrite(LED2pin,globalState);
  // digitalWrite(LED3pin,globalState);
 } 
  prevbutton1state = button1state;

//  else {
//     // digitalWrite(LED1pin,led1State);
//   digitalWrite(LED0pin,globalState);
//   digitalWrite(LED1pin,globalState);
//   digitalWrite(LED2pin,globalState);
//   digitalWrite(LED3pin,globalState);
//  }
 if (button2state==HIGH && prevbutton2state == LOW) {
  mod+=1;
  mod = mod % 3;
 }
prevbutton2state = button2state;
 if (globalState==HIGH) {
  if (millis() - lastUpdateTime >= interval) {
      lastUpdateTime = millis(); // Reset timer
  // mod logic
  if (prevmod!=mod) {
    digitalWrite(LED0pin,LOW);
    digitalWrite(LED1pin,LOW);
    digitalWrite(LED2pin,LOW);
    digitalWrite(LED3pin,LOW);
    prevmod=mod;
  }
  if (mod==0) {
    digitalWrite(LED0pin,blink);
    digitalWrite(LED1pin,blink);
    digitalWrite(LED2pin,blink);
    digitalWrite(LED3pin,blink);
    blink = !blink;

  } else if (mod==1) {
    if (cur==0) {
    digitalWrite(LED3pin, LOW);
    digitalWrite(LED0pin,HIGH);
    cur+=1;
    cur=cur%4;
    }   else if (cur==1) {
    digitalWrite(LED0pin, LOW);
    digitalWrite(LED1pin,HIGH);
    cur+=1;
    cur=cur%4;
    } else if (cur==2) {
    digitalWrite(LED1pin, LOW);
    digitalWrite(LED2pin,HIGH);
    cur+=1;
    cur=cur%4;
    } else if (cur==3) {
    digitalWrite(LED2pin, LOW);
    digitalWrite(LED3pin,HIGH);
    cur+=1;
    cur=cur%4;
    }
  } else if (mod==2) {
    if (cur==0) {
    digitalWrite(LED0pin, LOW);
    digitalWrite(LED3pin,HIGH);
    cur+=1;
    cur=cur%4;
    }   else if (cur==1) {
    digitalWrite(LED3pin, LOW);
    digitalWrite(LED2pin,HIGH);
    cur+=1;
    cur=cur%4;
    } else if (cur==2) {
    digitalWrite(LED2pin, LOW);
    digitalWrite(LED1pin,HIGH);
    cur+=1;
    cur=cur%4;
    } else if (cur==3) {
    digitalWrite(LED1pin, LOW);
    digitalWrite(LED0pin,HIGH);
    cur+=1;
    cur=cur%4;
    }
  }
  }
 } else {
  digitalWrite(LED0pin,LOW);
  digitalWrite(LED1pin,LOW);
  digitalWrite(LED2pin,LOW);
  digitalWrite(LED3pin,LOW);
 }


//  if (button1state==HIGH) {
//   if (led1State!=HIGH) {
//     led1State=HIGH;
//     digitalWrite(LED1pin, HIGH);
//   }
//  } 
//  else {
//     if (led1State!=LOW) {
//     led1State=LOW;
//     digitalWrite(LED1pin, led1State);
//   }
//  }

}