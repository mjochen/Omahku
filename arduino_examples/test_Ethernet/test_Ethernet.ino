// https://inventr.io/connecting-enc28j60-ethernet-lan-to-arduino/
// https://github.com/RobotDynOfficial/RBDDimmer

#include <EtherCard.h>
#include <RBDdimmer.h>

static byte mymac[] = { 0x74, 0x69, 0x69, 0x2D, 0x30, 0x31 };

byte Ethernet::buffer[700];

static int outPins[] = { 2, 3, 4, 5 };
static int inPins[] = { 6, 7, 8, 9 };

#define outputPin  9
dimmerLamp dimmer(outputPin); //initialase port for dimmer for MEGA, Leonardo, UNO, Arduino M0, Arduino Zero
int outVal = 0;

void setup() {
  Serial.begin(115200);
  Serial.println(F("n[testDHCP]"));

  Serial.print("MAC: ");
  for (byte i = 0; i < 6; ++i) {
    Serial.print(mymac[i], HEX);
    if (i < 5)
      Serial.print(': ');
  }
  Serial.println();

  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)
    Serial.println(F("Failed to access Ethernet controller"));

  Serial.println(F("Setting up DHCP"));
  if (!ether.dhcpSetup())
    Serial.println(F("DHCP failed"));

  ether.printIp("My IP: ", ether.myip);
  ether.printIp("Netmask: ", ether.netmask);
  ether.printIp("GW IP: ", ether.gwip);
  ether.printIp("DNS IP: ", ether.dnsip);

  // button tests:

  for (int i = 0; i < 4; i++)
  {
    pinMode(outPins[i], OUTPUT);
    pinMode(inPins[i], INPUT_PULLUP);
  }


  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE)
}

void printSpace(int val)
{
  if ((val / 100) == 0) Serial.print(" ");
  if ((val / 10) == 0) Serial.print(" ");
}

void loop() {

  for (int i = 0; i < 4; i++)
  {
    int val = digitalRead(inPins[i]);  // read input value
    if (val == HIGH) {         // check if the input is HIGH (button released)
      digitalWrite(outPins[i], LOW);  // turn LED OFF
    } else {
      digitalWrite(outPins[i], HIGH);  // turn LED ON
    }
  }

  int preVal = outVal;

  if (Serial.available())
  {
    int buf = Serial.parseInt();
    if (buf != 0) outVal = buf;
    delay(200);
  }
  dimmer.setPower(outVal); // setPower(0-100%);

  if (preVal != outVal)
  {
    Serial.print("lampValue -> ");
    printSpace(dimmer.getPower());
    Serial.print(dimmer.getPower());
    Serial.println("%");

  }

  delay(50);

}
