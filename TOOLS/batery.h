#include <Arduino.h> 

//read the tension with a tension divider 
//           PIN 
//            |
//            |
// VCC-----M-----------M------GND
//      330k          110k 
class battery
{
private:
    float voltage_read =0;
    float voltage = 0;
    float correction_b = 0;
    bool undervoltage = false;
    float correction_a = 0;
    float UnderVoltage_tolerance = 0;
    
public:
    battery(int PIN,int A,int B, float mimBat);
    float batteryVoltage();
    bool underVoltage();
    void debug();
};

battery::battery(int PIN,int A,int B, float mimBat )
{ correction_a = A;
  correction_b = B;
  UnderVoltage_tolerance = mimBat;
  pinMode(PIN,INPUT);
  
}
float battery::batteryVoltage(){
  voltage_read = analogRead(PIN_BAT);
  voltage = (voltage_read/correction_a)+correction_b;

  return voltage;
}
bool battery::underVoltage(){
  //TO DO
  //battery read is not stable something it can go 
  //below the undervage and go back 
  //add timer to only trigger the undervoltage 
  //if the reading is below the undervoltage after 3 s ;

  return batteryVoltage() < UnderVoltage_tolerance ;

}
void battery::debug(){
  Serial.print("| UNDERVOLTAGE: ");
  Serial.print(underVoltage());
  Serial.print(" | Read: ");
  Serial.print(voltage_read);
  Serial.print(" | Voltage:");
  Serial.print(voltage);
  Serial.print(" |");
  Serial.println();
}