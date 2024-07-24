#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include <SPI.h>

// LCD setup (if using an LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change address and size if needed

// RFID setup
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

// Predefined RFID card UID (set this to your card UID)
String allowedUID = "12 34 56 78";

// Variables
String currentUID = "";

void setup() {
  Serial.begin(9600);
  SPI.begin(); 
  rfid.PCD_Init();
  
  // Initialize LCD (if used)
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("RFID Reader");
  
  Serial.println("Scan your RFID card");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  currentUID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    currentUID += String(rfid.uid.uidByte[i], HEX);
    if (i < rfid.uid.size - 1) {
      currentUID += " ";
    }
  }

  currentUID.toUpperCase();
  Serial.println("Card UID: " + currentUID);

  if (currentUID == allowedUID) {
    Serial.println("Access Granted");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Granted");
  } else {
    Serial.println("Access Denied");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Denied");
  }

  delay(2000); // Delay to allow user to remove card
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
