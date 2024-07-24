# RFID.IDE
ARDUINO RFID READER WITH MRC522 LIBRARY

### Hardware Required:
1. Arduino (e.g., Uno, Mega, etc.)
2. RFID Reader (e.g., RC522)
3. RFID Tags or Cards
4. LCD Display (optional, for showing status)
5. Breadboard and Jumper Wires

### Wiring:
**RC522 RFID Reader to Arduino:**
- SDA to pin 10
- SCK to pin 13
- MOSI to pin 11
- MISO to pin 12
- IRQ to not connected
- GND to GND
- RST to pin 9
- 3.3V to 3.3V (or 5V if your reader supports it)

**LCD (if used) to Arduino:**
- VCC to 5V
- GND to GND
- SDA to A4
- SCL to A5

First, you need to install the `MFRC522` library in the Arduino IDE.
### Explanation:
1. **Libraries:**
   - `Wire.h`: For I2C communication with the LCD.
   - `LiquidCrystal_I2C.h`: For controlling the LCD.
   - `MFRC522.h`: For the RFID reader.
   - `SPI.h`: For SPI communication.

2. **LCD Initialization (Optional):**
   - Initializes the LCD and displays a welcome message.

3. **RFID Reader Initialization:**
   - Sets up the RFID reader and waits for a card to be scanned.

4. **Reading RFID Cards:**
   - Reads the card UID when a new card is present.
   - Compares the UID with the predefined allowed UID.
   - Displays "Access Granted" or "Access Denied" on the LCD and in the Serial Monitor.

5. **Access Control:**
   - If the UID matches the allowed UID, access is granted; otherwise, it's denied.

### Upload and Test:
1. Connect your Arduino to your computer and upload the code.
2. Open the Serial Monitor to see the UID of scanned cards.
3. Scan your RFID card and observe the output on both the Serial Monitor and the LCD (if used).

Feel free to customize the `allowedUID` and modify the LCD messages as needed.


HAVE FUN CODING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

ASTRAL
