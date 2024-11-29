#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "NdHXJ7q29v7tq0Og35yM5LFPzGR9_fDT"; 
char ssid[] = "Karthik"; 
char pass[] = "eswar@12345"; 

#define RELAY_PIN_1 D0
#define RELAY_PIN_2 D2
#define RELAY_PIN_3 D4
#define RELAY_PIN_4 D6

#define MANUAL_SWITCH_PIN_1 D1 
#define MANUAL_SWITCH_PIN_2 D3 
#define MANUAL_SWITCH_PIN_3 D5 
#define MANUAL_SWITCH_PIN_4 D7

bool manualSwitchState_1 = LOW; 
bool manualSwitchState_2 = LOW; 
bool manualSwitchState_3 = LOW; 
bool manualSwitchState_4 = LOW; 

BlynkTimer timer;

void setup() {
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(RELAY_PIN_3, OUTPUT);
  pinMode(RELAY_PIN_4, OUTPUT);
  
  pinMode(MANUAL_SWITCH_PIN_1, INPUT_PULLUP);
  pinMode(MANUAL_SWITCH_PIN_2, INPUT_PULLUP);
  pinMode(MANUAL_SWITCH_PIN_3, INPUT_PULLUP);
  pinMode(MANUAL_SWITCH_PIN_4, INPUT_PULLUP);
  
  digitalWrite(RELAY_PIN_1, LOW); 
  digitalWrite(RELAY_PIN_2, LOW); 
  digitalWrite(RELAY_PIN_3, LOW); 
  digitalWrite(RELAY_PIN_4, LOW); 
  
  Blynk.begin(auth, ssid, pass);
  
  timer.setInterval(1000L, checkManualSwitches); 
}

void loop() {
  Blynk.run();
  timer.run();
}

void checkManualSwitches() {
  int switchState_1 = digitalRead(MANUAL_SWITCH_PIN_1);
  int switchState_2 = digitalRead(MANUAL_SWITCH_PIN_2);
  int switchState_3 = digitalRead(MANUAL_SWITCH_PIN_3);
  int switchState_4 = digitalRead(MANUAL_SWITCH_PIN_4);
  
  if (switchState_1 != manualSwitchState_1) {
    manualSwitchState_1 = switchState_1;
    
    if (manualSwitchState_1 == HIGH) {
      digitalWrite(RELAY_PIN_1, HIGH);
      Blynk.virtualWrite(V1, HIGH); 
    } else {
      digitalWrite(RELAY_PIN_1, LOW);
      Blynk.virtualWrite(V1, LOW); 
    }
  }
  
  if (switchState_2 != manualSwitchState_2) {
    manualSwitchState_2 = switchState_2;
    
    if (manualSwitchState_2 == HIGH) {
      digitalWrite(RELAY_PIN_2, HIGH);
      Blynk.virtualWrite(V2, HIGH); 
    } else {
      digitalWrite(RELAY_PIN_2, LOW);
      Blynk.virtualWrite(V2, LOW); 
    }
  }
  
  if (switchState_3 != manualSwitchState_3) {
    manualSwitchState_3 = switchState_3;
    
    if (manualSwitchState_3 == HIGH) {
      digitalWrite(RELAY_PIN_3, HIGH);
      Blynk.virtualWrite(V3, HIGH); 
    } else {
      digitalWrite(RELAY_PIN_3, LOW);
      Blynk.virtualWrite(V3, LOW); 
    }
  }
  
  if (switchState_4 != manualSwitchState_4) {
    manualSwitchState_4 = switchState_4;
    
    if (manualSwitchState_4 == HIGH) {
      digitalWrite(RELAY_PIN_4, HIGH);
      Blynk.virtualWrite(V4, HIGH); 
    } else {
      digitalWrite(RELAY_PIN_4, LOW);
      Blynk.virtualWrite(V4, LOW); 
    }
  }
}

BLYNK_WRITE(V1) {
  int relayState = param.asInt();
  digitalWrite(RELAY_PIN_1, relayState);
}

BLYNK_WRITE(V2) {
  int relayState = param.asInt();
  digitalWrite(RELAY_PIN_2, relayState);
}

BLYNK_WRITE(V3) {
  int relayState = param.asInt();
  digitalWrite(RELAY_PIN_3, relayState);
}

BLYNK_WRITE(V4) {
  int relayState = param.asInt();
  digitalWrite(RELAY_PIN_4, relayState);
}
