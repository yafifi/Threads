#include <CapacitiveSensor.h>
#include "Adafruit_GFX.h"
#include "Adafruit_HT1632.h"
// Add necessary arduino libaries to control the hardware

#define HT_DATA 2
#define HT_WR 3
#define HT_CS 4
#define HT_CS2 5
// Declare the digital pins used for powering and controlling the two LED panels

const int buttonPin = 22;
int buttonState = 0;
// Define digital pin for button that will "clear" the screen
// Set binary state of button to 0

Adafruit_HT1632LEDMatrix matrix = Adafruit_HT1632LEDMatrix(HT_DATA, HT_WR, HT_CS, HT_CS2);
// Define the connected matrices as "matrix"
// Assign the parameters to the previously defined digital pins

CapacitiveSensor  cs_9_8 = CapacitiveSensor(9,8);
CapacitiveSensor  cs_7_6 = CapacitiveSensor(7,6);
CapacitiveSensor  cs_13_12 = CapacitiveSensor(13,12);
CapacitiveSensor  cs_11_10 = CapacitiveSensor(11,10);
CapacitiveSensor  cs_30_31 = CapacitiveSensor(30,31);
CapacitiveSensor  cs_34_35 = CapacitiveSensor(34,35);
CapacitiveSensor  cs_28_29 = CapacitiveSensor(28,29);
CapacitiveSensor  cs_32_33 = CapacitiveSensor(32,33);
CapacitiveSensor  cs_36_37 = CapacitiveSensor(36,37);
CapacitiveSensor  cs_38_39 = CapacitiveSensor(38,39);
CapacitiveSensor  cs_40_41 = CapacitiveSensor(40,41);
CapacitiveSensor  cs_42_43 = CapacitiveSensor(42,43);
// Declare the read and write digital pins used for each capacitive sensor

void setup() {
 Serial.begin(9600);
 // Set baud rate
 matrix.begin(ADA_HT1632_COMMON_16NMOS);
 // Initialize matrices
 matrix.fillScreen();
 delay(500);
 // Illuminate entire screen for 500 milliseconds
 matrix.clearScreen();
 }

void loop() {
  long square1 =  cs_13_12.capacitiveSensor(30);
  long square2 =  cs_11_10.capacitiveSensor(30);
  long square3 =  cs_9_8.capacitiveSensor(30);
  long square4 =  cs_7_6.capacitiveSensor(30);
  long square5 =  cs_30_31.capacitiveSensor(30);
  long square6 =  cs_34_35.capacitiveSensor(30);
  long square7 =  cs_28_29.capacitiveSensor(30);
  long square8 =  cs_32_33.capacitiveSensor(30);
  long square9 =  cs_36_37.capacitiveSensor(30);
  long square10 =  cs_38_39.capacitiveSensor(30);
  long square11 =  cs_40_41.capacitiveSensor(30);
  long square12 =  cs_42_43.capacitiveSensor(30);
// Assign each sensor to a variable that corresponds to a square on the sensing pad
// The parameter 30 is the resolution of the returned integer of absolute capacitance in arbitrary units

  if (square1 > 50) {
    Serial.println("touched1");
    Serial.println(square1);
    matrix.fillRect(0, 0, 8, 8, 1);
    matrix.writeScreen();  }
  else if (square2 > 50){
    Serial.println("touched2");
    Serial.println(square2);
    matrix.fillRect(8, 0, 8, 8, 1);
    matrix.writeScreen();  }
  else if (square3 > 50) {
    Serial.println("touched3");
    Serial.println(square3);
    matrix.fillRect(16, 0, 8, 8, 1);
    matrix.writeScreen(); }
  else if (square4 > 50){
    Serial.println("touched4");
    Serial.println(square4);
    matrix.fillRect(24, 0, 8, 8, 1);
    matrix.writeScreen(); }
  else if (square5 > 50) {
    Serial.println("touched5");
    Serial.println(square5);
    matrix.fillRect(32, 0, 8, 8, 1);
    matrix.writeScreen();  }
  else if (square6 > 50){
    Serial.println("touched6");
    Serial.println(square6);
    matrix.fillRect(40, 0, 8, 8, 1);
    matrix.writeScreen();  }
  else if (square7 > 50){
    Serial.println("touched7");
    Serial.println(square7);
    matrix.fillRect(0, 8, 8, 8, 1);
    matrix.writeScreen();  }
  else if (square8 > 50) {
    Serial.println("touched8");
    Serial.println(square8);
    matrix.fillRect(8, 8, 8, 8, 1);
    matrix.writeScreen(); }
  else if (square9 > 50){
    Serial.println("touched9");
    Serial.println(square9);
    matrix.fillRect(16, 8, 8, 8, 1);
    matrix.writeScreen(); }
  else if (square10 > 50) {
    Serial.println("touched10");
    Serial.println(square10);
    matrix.fillRect(24, 8, 8, 8, 1);
    matrix.writeScreen(); }
  else if (square11 > 50){
    Serial.println("touched11");
    Serial.println(square11);
    matrix.fillRect(32, 8, 8, 8, 1);
    matrix.writeScreen();  }
  else if (square12 > 50){
    Serial.println("touched12");
    Serial.println(square12);
    matrix.fillRect(40, 8, 8, 8, 1);
    matrix.writeScreen();  }
  // Check the capacitance of each sensor
  // If their value is greater than 50, fill the corresponding square on the LED matrix
 
  buttonState = digitalRead(buttonPin);
  // Read the digital pin assigned to buttonPin for a signal
  
  if (buttonState == HIGH){
    matrix.clearScreen(); }
  // If the button is clicked/high signal is read, the matrices are cleared
    
  delay(500);
  // Void loop restarts every 500 milliseconds
}