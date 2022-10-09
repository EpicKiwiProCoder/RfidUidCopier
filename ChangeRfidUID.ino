#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   9     
#define SS_PIN    18    

MFRC522 mfrc522(SS_PIN, RST_PIN);   

byte newUid[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600); 
  while (!Serial);     
  SPI.begin();         
  mfrc522.PCD_Init();  
  
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
  delay(2000);
}

void loop() {
  mfrc522.MIFARE_OpenUidBackdoor(false);
  mfrc522.MIFARE_Write((byte)0, newUid, (byte)16);
  Serial.println("done");
  delay(1000);
}
