// ECE 110 Lab
// Final Design
// Brett Jackson
// bbjacks2@illinois.edu
// Copyright (c) 2012 Brett Jackson
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without
// limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
// THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <SoftwareSerial.h>

// Variable declarations
int rightMotorSpeed          = 0;
int leftMotorSpeed           = 0;
int colorDetected            = 0;
int splitDetected            = 0;
int leftTapeDetected         = 0;
int rightTapeDetected        = 0;
int leftSplitDetected        = 0;
int rightSplitDetected       = 0;



// Pin declarations
const int rightMotor         = 14; // connect this pin to right CA module, pin A0
const int leftMotor          = 15; // connect this pin to left  CA module, pin A1
const int rightTapeAvoiding  = 2;
const int leftTapeAvoiding   = 3;
const int rightSplitDetector = 4;
const int leftSplitDetector  = 5;
const int colorDetector      = 6;




void setup() {
  Serial.begin(9600);
}

void loop() {
  leftSplitDetected  = digitalRead(leftSplitDetector);
  rightSplitDetected = digitalRead(rightSplitDetector);
  colorDetected      = digitalRead(colorDetector);
  leftTapeDetected   = digitalRead(leftTapeAvoiding);
  rightTapeDetected  = digitalRead(rightTapeAvoiding);

  analogWrite(leftMotor,  255);
  analogWrite(rightMotor, 255);
  
  if (leftSplitDetected == 1 && rightSplitDetected == 1) {
    splitDetected = 1;
    Serial.println("Split detected.");
  } else {
    splitDetected = 0;
  }
  
  
  if (splitDetected == 1) {
    if (colorDetected == 1) {
      colorDetectedRoutine();
      Serial.println("Split with color detected.");
    }
   } else { 
      splitDetectedRoutine(); 
    }

    tapeFollow();
  
}

void tapeFollow() {
  Serial.println("Following tape.");
}

void tapeAvoid() {
  Serial.println("Avoiding tape.");
  if (leftTapeAvoiding == 1)
  {
    leftTapeAvoid();
  } if (rightTapeAvoiding == 1) {
    rightTapeAvoid();
  }
}

void leftTapeAvoid() {
  Serial.println("LeftTapeAvoid routine started.");
  while (leftTapeAvoiding == 1)
  {
    analogWrite(leftMotor, 128);
  }
  Serial.println("LeftTapeAvoid finished");
}

void rightTapeAvoid() {
  Serial.println("RightTapeAvoid routine started.");
  while (rightTapeAvoiding == 1) 
  {
    analogWrite(rightMotor, 128);
  }
  Serial.println("RightTapeAvoid finished");
}

void colorDetectedRoutine() {
  Serial.println("ColorDetectedRoutine started.");
}

void splitDetectedRoutine() {
  Serial.println("SplitDetectedRoutine started.");
}
