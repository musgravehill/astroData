void EEPROM16_Write(uint8_t a, uint16_t b) {
  EEPROM.write(a, lowByte(b));
  EEPROM.write(a + 1, highByte(b));
}

uint16_t EEPROM16_Read(uint8_t a) {
  return word(EEPROM.read(a + 1), EEPROM.read(a));
}
