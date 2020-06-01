// rc-switch kütüphanesi yüklenmeli
// kumanda kodları: A: 10314241 
//                  B: 10314242 
//                  C: 10314244 
//                  D: 10314248 
                  
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int led1 = 12;
int led2 = 11;
int led3 = 10;
boolean statusLed1=LOW;
boolean statusLed2=LOW;
boolean statusLed3=LOW;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0); 

}

void loop() {
  if(mySwitch.available())
  {
   
    unsigned long int num = mySwitch.getReceivedValue();
    Serial.println("Gelen Deger:" + String(num));
    switch(num)
    {
    case 10314241: mySwitch.disableReceive();
                  statusLed1 = HIGH;
                  break;
    case 10314242: mySwitch.disableReceive();
                  statusLed2 = HIGH;
                  break;
    case 10314244: mySwitch.disableReceive();
                  statusLed3 = HIGH;
                  break;
    case 10314248: mySwitch.disableReceive();
                  statusLed1 = LOW;
                  statusLed2 = LOW;
                  statusLed3 = LOW;
                  break;
      
    }
    digitalWrite(led1, statusLed1);
    digitalWrite(led2, statusLed2);
    digitalWrite(led3, statusLed3);
    delay(100);

    mySwitch.resetAvailable();
    mySwitch.enableReceive(0);
    }

}
