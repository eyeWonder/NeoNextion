#include <NeoNextion.h>
#include <NextionButton.h>
#include <NextionPage.h>
#include <INextionStringValued.h>
#include <SoftwareSerial.h>

SoftwareSerial nextionSerial(10, 11); // RX, TX

Nextion nex(nextionSerial);
NextionPage pgText(nex, 0, 0, "pgText");
NextionButton button(nex, 0, 1, "bEgButton");
INextionStringValued textField(nex, 0, 2, "tTextField");

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  nextionSerial.begin(9600);
  nex.init();

  Serial.println(pgText.show());

  Serial.println(button.attachCallback(&callback));
  
}

void loop()
{
  nex.poll();
}

void callback(NextionEventType type, INextionTouchable *widget)
{
  char buffer[30];	
  if (type == NEX_EVENT_PUSH)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    if (textField.getText(buffer, 30)) {
      Serial.println(buffer);
    }
  }
  else if (type == NEX_EVENT_POP)
  {
    digitalWrite(LED_BUILTIN, LOW);
    if (textField.getText(buffer, 30)) {
      Serial.println(buffer);
    }
  }
}

