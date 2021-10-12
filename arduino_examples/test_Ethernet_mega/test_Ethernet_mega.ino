// https://inventr.io/connecting-enc28j60-ethernet-lan-to-arduino/

#include <EtherCard.h>

static byte mymac[] = { 0x74, 0x69, 0x69, 0x2D, 0x30, 0x32 };

byte Ethernet::buffer[700];

static int outPins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
static int inPins[] = { 49, 48, 47, 46, 45, 44, 43, 42  };


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

  for (int i = 0; i < 8; i++)
  {
    pinMode(outPins[i], OUTPUT);
    pinMode(inPins[i], INPUT_PULLUP);
  }
}

void loop() {

  for (int i = 0; i < 8; i++)
  {
    int val = digitalRead(inPins[i]);  // read input value
    if (val == HIGH) {         // check if the input is HIGH (button released)
      digitalWrite(outPins[i], LOW);  // turn LED OFF
    } else {
      digitalWrite(outPins[i], HIGH);  // turn LED ON
    }
  }

  delay(100);

}
