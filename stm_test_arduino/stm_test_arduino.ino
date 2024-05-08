// библиотека для работы программного Serial
#include <SoftwareSerial.h>
 
// создаём объект для работы с программным Serial
// и передаём ему пины TX и RX
SoftwareSerial mySerial(8, 9);

#define STM    mySerial

String s2 = "␀";
char array1[] = {'H', 'e', 'l', 'l', 'o', 0x00};
 
void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }

  Serial.print("Serial init OK\r\n");
  STM.begin(115200);
}
 
void loop() {
  while(true) {
    if (Serial.available() > 0) {
      byte buffer[1] = {Serial.read()};
      if (buffer[0] == 0x0A) {
        buffer[0] == 0x0D;
        continue;
      }

      if (buffer[0] == 0x0D) {
        STM.write((byte)0x00);
        Serial.println("OK");
      }

      if (buffer[0] != 0x0D && buffer[0] != 0x0A) {
        STM.write(buffer[0]);
        Serial.println("+++");
      }
    }
  }
}