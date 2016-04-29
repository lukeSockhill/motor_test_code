
// bump switch pin
int bumpPin = 2;

// motor variables
int E1 = 5;
int M1 = 4;

// debounce function variables
boolean lastButton = LOW;
boolean currentButton = LOW;

// variable that tracks whether the motor
// should be on, used in checkWall function
boolean wallDetect = false;





void setup() {

  Serial.begin(9600);
  
  // make the bump switch's pin an input:
  pinMode(bumpPin, INPUT);

  pinMode(M1, OUTPUT);
  // activate pull up resistor
  digitalWrite(2, HIGH);
}



// eliminates the effect of switch bouncing
boolean debounce(boolean last)
{
  boolean current = digitalRead(bumpPin);
  
  {
    if (last != current)
    {
      delay(5);
      current = digitalRead(bumpPin);
    }
  }
  
  return current;
}

// checks whether the craft has hit a wall
boolean checkWall() {
    
    currentButton = debounce(lastButton);
    
    if (lastButton == LOW && currentButton == HIGH)
    {
      wallDetect = !wallDetect; // *wall detect = true*    
    }

    lastButton = currentButton;  
    
    return wallDetect;
    
  }

void motorRun(boolean dir, int vel) {

  digitalWrite(M1, dir);
  analogWrite(E1, vel);
}

void motorStop() {
  analogWrite(E1,0);
}

void craftTurn() {

    motorRun(LOW, 110);
    delay(3000);
    motorStop();
    delay(1500);
  }
  
  


//MAIN LOOP
void loop() {
  
  int wallHit = checkWall(); //checkWall will be true or false
  
  
  if (wallHit == true)
  { 
    motorRun(HIGH, 220); 
  }
  
  // this statement is executed if the craft hits a wall
  else
  { 
          
    motorStop();
    delay(1000);
    
    craftTurn();
    wallDetect= true;
    }
   
    
}





  
  

