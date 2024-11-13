
// MultiFunction Dice roller.
#include <Wire.h>
#include <MultiFuncShield.h>


class Dice
{
  //D20  //D12 //D10 //D8 //D6 //D4
private:
int diceType[5] = {20,12,8,6,4};
int currentSelection = 4;

public:
  int Roll()
  {
    Serial.print("Current Selection:"+currentSelection);
    
    Serial.println(diceType[currentSelection]);
    return (int)random(1,(diceType[currentSelection]+1));
  };

void biggerDice()
{
if (currentSelection >0 && currentSelection <= 4) currentSelection -=1;
}

void smallerDice()
{
if (currentSelection >= 0 && currentSelection<4 ) currentSelection +=1;
}

int getDiceType()
{
  
  return diceType[currentSelection];
}


};



Dice myDice = Dice();


void buttonHandler()
{
byte btn = MFS.getButton(); // Normally it is sufficient to compare the return
                              // value to predefined macros, e.g. BUTTON_1_PRESSED,
                              // BUTTON_1_LONG_PRESSED etc.
if (btn)
  {
    byte buttonNumber = btn & B00111111;
    byte buttonAction = btn & B11000000;
    
    if (btn == BUTTON_1_PRESSED)
    {
      diceAnimation();
      MFS.write(myDice.Roll());
      MFS.beep();
    }

       if (btn == BUTTON_2_PRESSED)
    {
      
      myDice.biggerDice();
      diceModeDisplay(myDice.getDiceType());
      MFS.beep();
    }
    if (btn == BUTTON_3_PRESSED)
    {
      
      myDice.smallerDice();
      diceModeDisplay(myDice.getDiceType());
      MFS.beep();
    }

  } 
}


void diceAnimation()
{
  MFS.write("   -");
  delay(40);
  MFS.write("  - ");
  delay(40);
  MFS.write(" -  ");
  delay(40);
  MFS.write("-   ");
  delay(40);
  MFS.write("-   ");
  delay(40);
  MFS.write(" -  ");
  delay(40);
  MFS.write("  - ");
  delay(40);
  MFS.write("   -");
  delay(40);
}

void diceModeDisplay(int die)
{
    //D6
    if (die == 6)
    {
      MFS.write("   d");
      delay(80);
      MFS.write("  d6");
      delay(80);
      MFS.write(" d6 ");
      delay(80);
      MFS.write("d6  ");
      delay(80);
      MFS.write("6   ");
      delay(80);
      MFS.write("    ");
      delay(80);
    }
    //D6
    if (die == 4)
    {
      MFS.write("   d");
      delay(80);
      MFS.write("  d4");
      delay(80);
      MFS.write(" d4 ");
      delay(80);
      MFS.write("d4  ");
      delay(80);
      MFS.write("4   ");
      delay(80);
      MFS.write("    ");
      delay(80);
    }
       if (die == 8)
    {
      MFS.write("   d");
      delay(80);
      MFS.write("  d8");
      delay(80);
      MFS.write(" d8 ");
      delay(80);
      MFS.write("d8  ");
      delay(80);
      MFS.write("8   ");
      delay(80);
      MFS.write("    ");
      delay(80);
    }
     if (die == 12)
    {
      MFS.write("   d");
      delay(80);
      MFS.write("  d1");
      delay(80);
      MFS.write(" d12");
      delay(80);
      MFS.write("d12 ");
      delay(80);
      MFS.write("12   ");
      delay(80);
      MFS.write("2   ");
      delay(80);
      MFS.write("    ");
      delay(80);
    }
         if (die == 20)
    {
      MFS.write("   d");
      delay(80);
      MFS.write("  d2");
      delay(80);
      MFS.write(" d20");
      delay(80);
      MFS.write("d20 ");
      delay(80);
      MFS.write("20  ");
      delay(80);
      MFS.write("0   ");
      delay(80);
       MFS.write("    ");
      delay(80);
    }
  
  
}

void splash()
{
MFS.write("Hi");
  delay(1000);
  MFS.write("dice");
  delay(1000);
  MFS.write("here");  // display to 2 decimal places.
  delay(1000);

  MFS.write("push");  // display to 2 decimal places.
  delay(1000);

  MFS.write("Btn1");  // display to 2 decimal places.
  delay(1000);
  MFS.write("to  ");  // display to 2 decimal places.
  delay(1000);
  MFS.write("roll");  // display to 2 decimal places.
  delay(1000);

 MFS.writeLeds(LED_ALL,ON);
 delay(200);
 MFS.writeLeds(LED_ALL,OFF);
}



void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  MFS.initialize(0000);    // initialize multi-function shield library
splash();  
  

MFS.beep();



}

void loop() {
  // put your main code here, to run repeatedly:
buttonHandler();

}
