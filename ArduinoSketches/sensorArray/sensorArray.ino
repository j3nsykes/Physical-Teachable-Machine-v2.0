int numPins = 5;
const int sensorPins [5] = {0,1,2,3,4};



void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

for(int i=0;i<numPins;i++){
  int sensorValue = analogRead(sensorPins[i]);
     Serial.print(sensorValue);
    Serial.print(" ");
  }
    Serial.println("");
}
