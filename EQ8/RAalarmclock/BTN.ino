void BUTTON_check() {
  uint8_t state;
  uint8_t SYS_STATE_TMP = SYS_STATE_STAR_TRACKING;

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

  //BUTTON_RA_FORWARD 7 //PD7
  state = bitRead(PIND, 7);
  if (state == 0) {
    SYS_STATE_TMP = SYS_STATE_PULT_RA_FORWARD;
  }

  //BUTTON_RA_BACKWARD 6 //PD6
  state = bitRead(PIND, 6);
  if (state == 0) {
    SYS_STATE_TMP = SYS_STATE_PULT_RA_BACKWARD;
  }

  //BUTTON_DEC_FORWARD 9 //PB1
  state = bitRead(PINB, 1);
  if (state == 0) {
    SYS_STATE_TMP = SYS_STATE_PULT_DEC_FORWARD;
  }

  //BUTTON_DEC_BACKWARD 8 //PB0
  state = bitRead(PINB, 0);
  if (state == 0) {
    SYS_STATE_TMP = SYS_STATE_PULT_DEC_BACKWARD;
  }

  SYS_STATE = SYS_STATE_TMP;

  if (SYS_STATE_PREV != SYS_STATE) {
    switch (SYS_STATE) {
      case SYS_STATE_PULT_RA_FORWARD:
        TIMER_config(PULT_SPEED_COEFF, true, true);
        break;
      case SYS_STATE_PULT_RA_BACKWARD:
        TIMER_config(PULT_SPEED_COEFF, false, true);
        break;
      case SYS_STATE_PULT_DEC_FORWARD:
        TIMER_config(PULT_SPEED_COEFF, true, true);
        break;
      case SYS_STATE_PULT_DEC_BACKWARD:
        TIMER_config(PULT_SPEED_COEFF, true, false);
        break;
      case SYS_STATE_STAR_TRACKING:
        TIMER_config(1, true, true);
        break;
    }
  }
  SYS_STATE_PREV = SYS_STATE;  
}

void BUTTON_init() {
  pinMode(RA_speed_inc,  INPUT);
  pinMode(RA_speed_dec,  INPUT);

  pinMode(BUTTON_RA_FORWARD,  INPUT);
  pinMode(BUTTON_RA_BACKWARD,  INPUT);
  pinMode(BUTTON_DEC_FORWARD,  INPUT);
  pinMode(BUTTON_DEC_BACKWARD,  INPUT);
}


