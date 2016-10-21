// D.ino

//Programa : RFID - Controle de Acesso leitor RFID
//Autor : FILIPEFLOP

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

char st[20];

void setup() {
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
 // Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
}

void loop() {
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Mostra UID na serial
  //Serial.print("UID da tag :");
  String conteudo = "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();// só pra pular linha
  delay(1500);

  /*Serial.print("\nMensagem : ");
  conteudo.toUpperCase();
  //UID 1 - Chaveiro
  if (conteudo.substring(1) == "F4 AB 73 A7") {
    Serial.println("Chaveiro Identificado\n");
    delay(1500);
  }
  //UID 2 - Cartao
  if (conteudo.substring(1) == "03 C4 FE E5") {
    Serial.println("Cartao identificado\n");
    delay(1000);
  }
  */
}
