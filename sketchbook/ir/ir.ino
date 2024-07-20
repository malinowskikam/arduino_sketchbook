#include <IRremote.h>

int ir_snd_data_pin = 2;
int ir_rec_data_pin = 3;
int button_pin = 5;
  
void setup() {
  Serial.begin(115200);
  IrReceiver.begin(ir_rec_data_pin);
  IrSender.begin(ir_snd_data_pin);
  pinMode(button_pin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(button_pin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    IrSender.sendSamsung(0x7, 0x2, 1);  
  }


  //Receive
  if (IrReceiver.decode()) {
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.printIRSendUsage(&Serial);
      IrReceiver.resume();
  }

  if (buttonState == HIGH) {
    delay(500);
  }


}
