void TIMEMACHINE_loop() {
  uint32_t  TIMEMACHINE_currMillis = millis();

  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prevMicros_173ms) > 173L) {
    TIMEMACHINE_173ms();
    TIMEMACHINE_prevMicros_173ms = TIMEMACHINE_currMillis;
  }
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prevMicros_873ms) > 873L) {
    TIMEMACHINE_873ms();
    TIMEMACHINE_prevMicros_873ms = TIMEMACHINE_currMillis;
  }
}

void TIMEMACHINE_173ms() {

}
void TIMEMACHINE_873ms() {
  BUTTON_check();   
   
  Serial.println(TIMER_OCR1A);
}


