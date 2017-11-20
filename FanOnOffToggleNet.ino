int FanOut = D2;
int IntLedOut = D7;
int state = 1;

void setup()
{
   pinMode(FanOut, OUTPUT);
   pinMode(IntLedOut, OUTPUT);

   Particle.function("FanControl",FanControl);
   
   digitalWrite(FanOut, LOW);
   digitalWrite(IntLedOut, LOW);
}


void loop()
{
}

int FanControl(String command) {

    if (command =="on") {
        digitalWrite(FanOut,HIGH);
        digitalWrite(IntLedOut,HIGH);
        state = 0;
        return 1;
    }
    else if (command =="off") {
        digitalWrite(FanOut,LOW);
        digitalWrite(IntLedOut,LOW);
        state = 1;
        return 0;
    }
    else if (command =="toggle") {
        digitalWrite(FanOut, (state) ? HIGH : LOW);
        digitalWrite(IntLedOut, (state) ? HIGH : LOW);
        state = !state;
        return 3;
    }

    else {
        return -1;
    }
}
