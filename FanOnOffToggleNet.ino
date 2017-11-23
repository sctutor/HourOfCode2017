/***********************************************************
 * Particle API Control of Mini-Fan
 * By Mike Leonard
 * By using a simple web form or If This Then That (IFTTT) we can remotely
 * control a Particle Photon with and Mini-Fan connected on pin D2.
 * To simplfy the code we have a TOGGLE function in addtion to ON and OFF functions
 * When you press the DO BUTTON the Mini-Fan goes to the opposite state (ON/OFF)
 * The Photon internal LED on pin D7 does the same thing
 * *********************************************************/


//Assign variable names to Photon pin numbers
int FanOut = D2;
int IntLedOut = D7;

//Define and initialize the variable state which will keep track of if the fan is on or off 
int state = 1;

//This gets run one time
//Set the mode of the Photon pins to OUTPUT
//Assign the name of the Particle function name and routine to call
//Make sure fan is initially off
void setup()
{
   pinMode(FanOut, OUTPUT);
   pinMode(IntLedOut, OUTPUT);

   Particle.function("FanControl",FanControl);
   
   digitalWrite(FanOut, LOW);
   digitalWrite(IntLedOut, LOW);
}

//Nothing happens in here, it just spins waiting for the Particle.function to be called by API or IFTTT
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
