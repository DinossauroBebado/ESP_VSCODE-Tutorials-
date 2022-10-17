

//PWM control for the motors with h bridge without pwm pin
#include <Arduino.h>
class motor
{
private:
    int FREQUENCIA = 800;
  
public:
    int In_A ;
    int In_B ; 
    int canal_A;
    int canal_B;
  
    motor(int IN_A, int IN_B,int CANAL_A , int CANAL_B);
    void init();
    void write(int pwm);
};

motor::motor(int IN_A, int IN_B,int CANAL_A , int CANAL_B)
{   
    In_A = IN_A ;
    In_B = IN_B ;
    canal_A = CANAL_A;
    canal_B = CANAL_B;

}
void motor::init(){

    pinMode(In_A,OUTPUT);
    pinMode(In_B,OUTPUT);

   
    ledcAttachPin(In_A, canal_A);
    ledcAttachPin(In_B, canal_B);

    ledcSetup(canal_A, FREQUENCIA, 10);
    ledcSetup(canal_B, FREQUENCIA, 10);

    ledcWrite(canal_A, 0);
    ledcWrite(canal_B, 0);

};

void motor::write(int pwm){
    //add saturation

   
    ledcWrite(canal_A, 0);
    ledcWrite(canal_B, pwm);
   
}