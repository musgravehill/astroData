void TIMEMACHINE_loop() {
  uint32_t  TIMEMACHINE_currMillis = millis();

  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prevMicros_83ms) > 83L) {
    TIMEMACHINE_83ms();
    TIMEMACHINE_prevMicros_83ms = TIMEMACHINE_currMillis;
  }
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prevMicros_313ms) > 313L) {
    TIMEMACHINE_313ms();
    TIMEMACHINE_prevMicros_313ms = TIMEMACHINE_currMillis;
  }
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prevMicros_873ms) > 873L) {
    TIMEMACHINE_873ms();
    TIMEMACHINE_prevMicros_873ms = TIMEMACHINE_currMillis;
  }
}

void TIMEMACHINE_83ms() {
  BUTTON_PULT_check();
}
void TIMEMACHINE_313ms() {
  BUTTON_BOX_check();
}
void TIMEMACHINE_873ms() {
  //Serial.println(TIMER_OCR1A);
  //Serial.println(SYS_STATE);
}


