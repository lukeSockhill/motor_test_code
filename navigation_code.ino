// sensor pin initialisation
int bumpLeft = 2;
int bumpRight = 3;

// motor pin initialisation
int M1 = 4;
int E1 = 5;

int M2 = 6;
int E2 = 7;

// other global variables //

// checkWall function variables
boolean wallDetect = false;
boolean retrieved = false;

// other
int defaultSpeed = 220;
boolean dir = void //false = right sensor hit, turn left


//SETUP_FUNCTION//
void setup() {
  Serial.begin(9600);

  //pin setup
  pinMode(bumpLeft, INPUT);
  pinMode(bumpRight, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(M@, OUTPUT);
  
  //activate pull up resistor
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);

}

//DEBOUNCE_FUNCTION//
boolean debounce(boolean last)
{
  boolean currentLeft = digitalRead(bumpLeft);
  boolean currentRight = digitalRead(bumpRight);
  
  {
    if (last != currentLeft)
    {
      delay(5);
      currentLeft = digitalRead(bumpLeft);
      //dir = false
    }
    else if (last != currentRight)
    {
      delay(5);
      currentRight = digitalRead(bumpRight);
      //dir = true
    }
  }
  
  return current;

//WALLCHECK_FUNCTION//
boolean checkWall(boolean wallHit) 
{
  leftState = debounce(digitalRead(bumpLeft));
  rightState = debounce(digitalRead(bumpRight));
  boolean state = false;

  if (leftState == true)
  {
    wallHit = true;
    dir = true;
  }
  else if (rightState == true)
  {
    wallHit = true;
    dir = false;
  } 

  return wallHit;
}

//DETECTION_FUNCTION//                  //STILL TO DO
boolean boxDetect(boolean boxFound)
{


  return boxFound;
}

//CHECKRETRIEVAL_FUNCTION//             //STILL TO DO
void checkRetrieval();
{
    retireved = false;
}


//MOTORRUN_FUNCTIONS//

void motor1Run(boolean dir, int vel) 
{
  digitalWrite(M1, HIGH);
  analogWrite(E1, defaultSpeed);
}

void motor2Run(boolean dir, int vel) 
{
  digitalWrite(M2, HIGH);
  analogWrite(E2, defaultSpeed);
}

void motorStop();
{
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}

// used when box is detected to ensure craft
// does not drift away from detection site
void activeStop();
{
  digitalWrite(M1, LOW);
  analogWrite(E1, 120); //Adjust when testing
  digitalWrite(M2, LOW);
  analogWrite(E2, 120);
  delay(400);
  motorStop();
}

//CRAFTTURN_FUNCTIONS//
void craftTurnLeft() 
{
  motor1Run(LOW, 150);
  motor2Run(HIGH, 150);
  delay(3000);
  motor1Stop();
  motor2Stop();
  delay(1500);
}
  
void craftTurnRight() 
{
  motor1Run(HIGH, 110);
  motor2Run(LOW, 110);
  delay(3000);
  motor1Stop();
  motor2Stop();
  delay(1500);
    
} 


//MAIN_LOOP//
void loop() 
{
  motor1Run(HIGH, defaultSpeed); 
  motor2Run(HIGH, defaultSpeed);
  
  int wallHit = checkWall();

  if (wallHit == true)
  {
    motorStop();
    if dir == true;
    {
      craftTurnRight();
    }
    else if dir == false;
    {
      craftTurnLeft;
    }
  }

  if (boxFound == true)
  {
    activeStop();
    retrieve();
    checkRetrieval();
    if (retrieved == true)
    {
      int wallHit = checkWall();

      while (wallHit == false)
      {
        motor1Run(HIGH, defaultSpeed);
        motor2Run(HIGH, defaultSpeed);
        wallHit = checkWall();
      }
      
    }
  }

}






