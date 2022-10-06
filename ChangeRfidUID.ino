#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   9     
#define SS_PIN    18    

MFRC522 mfrc522(SS_PIN, RST_PIN);   

byte newUid[] = {0x02, 0xF6, 0xBE, 0xB9, 0xF3, 0x88, 0x04, 0x00, 0xC8, 0x26, 0x00, 0x20, 0x00, 0x00, 0x00, 0x18};

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600); 
  while (!Serial);     
  SPI.begin();         
  mfrc522.PCD_Init();  
  Serial.println(F("Warning: this example overwrites the UID of your UID changeable card, use with care!"));
  
  
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
