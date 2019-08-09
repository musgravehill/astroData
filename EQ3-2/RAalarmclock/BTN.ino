void BUTTON_check() {
  uint8_t state;

  //RA_speed_inc 5 //PD5
  state = bitRead(PIND, 5);
  if (state == 0) { //btn pressed
    TIMER_OCR1A_inc();
  }

  //RA_speed_dec PD4
  state = bitRead(PIND, 4);
  if (state == 0) { //btn pressed
    TIMER_OCR1A_dec();
  }
}

void BUTTON_init() {
  pinMode(RA_speed_inc,  INPUT);
  pinMode(RA_speed_dec,  INPUT);
}


