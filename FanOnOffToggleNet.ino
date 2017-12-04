/***********************************************************
 * Particle API Control of Mini-Fan
 * By Mike Leonard
 * By using a simple web form or If This Then That (IFTTT) we can remotely
 * control a Particle Photon with and Mini-Fan connected on pin D2.
 * To simplfy the code we have a TOGGLE function in addtion to ON and OFF functions
 * When you call the TOGGLE function the Mini-Fan goes to the opposite state (ON/OFF)
 * The Photon internal LED on pin D7 follows the (ON/OFF) state of the Mini-Fan for debug
 * *********************************************************/


//Assign variable names to Photon pin numbers
int FanOut = D2;
int IntLedOut = D7;

//Define and initialize the variable state which will keep track of if the Mini-Fan is ON or OFF 
int state = 1;

//The setup() function runs only one time
//It sets the mode of the Photon pins D2 and D7 to OUTPUT
//It assigns names to the Particle Cloud Function and corresponding Local Function
//Make sure fan is initially off
void setup()
{
   pinMode(FanOut, OUTPUT);
   pinMode(IntLedOut, OUTPUT);

   Particle.function("FanControl",FanControl);
   
   digitalWrite(FanOut, LOW);
   digitalWrite(IntLedOut, LOW);
}

//Nothing happens in here, it just spins waiting for the Particle Cloud Function to be called by API or IFTTT
void loop()
{
}

//The Local Function accepts 3 different command parameters (on, off, toggle)
//A value of -1 is returned if and invalid parameter is passed
//Enhancements could be made to add SPEED and DIRECTION parameters as well
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
