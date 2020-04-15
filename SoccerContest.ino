#include<SoftwareSerial.h>
#define EnA 5
#define EnB 3
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
SoftwareSerial mySerial(11,12);
void setup() {
 pinMode(EnA, OUTPUT);
 pinMode(EnB, OUTPUT);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 mySerial.begin(9600);
 Serial.begin(9600);
}
char val;
int sep;
void loop() {
 if (mySerial.available()) {
 val = mySerial.read();
 Serial.println(val);
 //Serial.println();
 }
 if (val == 'T') {
 Forwoard(sep);
 }
 if (val == 'L') {
 Light(sep);
 }
 if (val == 'S') {
 Stop(sep);
 }
 if (val == 'B') {
 Backwoard(sep);
 }
 if (val == 'R') {
 Right(sep);
 }
 if (val == '0') {
 sep = 0;
 }
 if (val == '1' || val == '2') {
 sep = 80;
 }
 if (val == '3' || val =='4'){
 sep = 120;
 }
 if (val == '5' || val =='6'){
 sep = 160;
 }
 if (val == '7' || val == '8'){
 sep = 200;
 }
 if (val == '9'){
 sep = 225;
 }
}
void Stop(int spe) {
 digitalWrite(IN1, 0);
 digitalWrite(IN2, 0);
 digitalWrite(IN3, 0);
 digitalWrite(IN4, 0);
 digitalWrite(EnA, 0);
 digitalWrite(EnB, 0);
}
void Forwoard(int spe) {
 digitalWrite(IN1, 1);
 digitalWrite(IN2, 0);
 digitalWrite(IN3, 1);
 digitalWrite(IN4, 0);
 analogWrite(EnA, spe);
 analogWrite(EnB, spe);
}
void Backwoard(int spe) {
 digitalWrite(IN1, 0);
 digitalWrite(IN2, 1);
 digitalWrite(IN3, 0);
 digitalWrite(IN4, 1);
 analogWrite(EnA, spe);
 analogWrite(EnB, spe);
}
void Right(int spe) {
 digitalWrite(IN1, 1);
 digitalWrite(IN2, 0);
 digitalWrite(IN3, 0);
 digitalWrite(IN4, 1);
 analogWrite(EnA, spe);
 analogWrite(EnB, spe);
}
void Light(int spe) {
 digitalWrite(IN1, 0);
 digitalWrite(IN2, 1);
 digitalWrite(IN3, 1);
 digitalWrite(IN4, 0);
 analogWrite(EnA, spe);
 analogWrite(EnB, spe);
}
