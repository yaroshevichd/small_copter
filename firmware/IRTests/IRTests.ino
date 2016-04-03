#include <Servo.h>
#include <SharpIR.h>

Servo servo1;
SharpIR ir1(15, 1080);
SharpIR ir2(16, 1080);

void setup() {
  servo1.attach(14, 1000, 2000);
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  
  static int v = 0;
  static bool clockwise = true;
  
  servo1.write(v);
  v = v + (clockwise ? 1 : -1);
  if (v == 180) clockwise = false;
  else if (v == 0) clockwise = true;
  
//  int dis1 = ir1.distance();
  int dis2 = ir2.distance();
  
//  Serial.print("Distance 1: ");
//  Serial.println(dis1);
  Serial.print("Distance 2: ");
  Serial.println(dis2);
  
//  static int v = 0;
//
//  if ( Serial.available()) {
//    char ch = Serial.read();
//
//    switch(ch) {
//      case '0'...'9':
//        v = v * 10 + ch - '0';
//        break;
//      case 's':
//        servo1.write(v);
//        Serial.println(v);
//        v = 0;
//        break;
//    }
//  }
}
