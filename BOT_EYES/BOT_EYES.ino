#include "LedControl.h"

LedControl lc=LedControl(11,13,10,4);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=100;  // Delay between Frames

byte invader1a[] =
{
   B11111000,  // First frame of invader #1
   B00100000,
   B00100000,
   B00100000,
   B00100000,
   B00100000,
   B00100000,
   B11000000
};

byte invader1b[] =
{
  B00000000, // Second frame of invader #1
  B00000000,
  B00000000,
  B00000000,
  B11111100,
  B00000000,
  B00000000,
  B00000000
};

byte invader2a[] =
{
  B00011111, // First frame of invader #2
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000011
};

byte invader2b[] =
{
  B00000000, // Second frame of invader #2
  B00000000,
  B00000000,
  B00000000,
  B00111111,
  B00000000,
  B00000000,
  B00000000
};

byte invader3a[] =
{
  B11111000,  // First frame of invader #3
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B11000000
};

byte invader3b[] =
{
  B00000000, // Second frame of invader #3
  B00000000,
  B00000000,
  B00000000,
  B11111100,
  B00000000,
  B00000000,
  B00000000
};

byte invader4a[] =
{
  B00011111, // First frame of invader #4
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000011
};

byte invader4b[] =
{
  B00000000, // Second frame of invader #4
  B00000000,
  B00000000,
  B00000000,
  B00111111,
  B00000000,
  B00000000,
  B00000000
};

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.shutdown(2,false);
  lc.shutdown(3,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.setIntensity(2,5);
  lc.setIntensity(3,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
}


//  Take values in Arrays and Display them
void sinvader1a()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,invader1a[i]);
  }
}

void sinvader1b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,invader1b[i]);
  }
}

void sinvader2a()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1,i,invader2a[i]);
  }
}

void sinvader2b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1,i,invader2b[i]);
  }
}

void sinvader3a()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(2,i,invader1a[i]);
  }
}

void sinvader3b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(2,i,invader1b[i]);
  }
}

void sinvader4a()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(3,i,invader2a[i]);
  }
}

void sinvader4b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(3,i,invader2b[i]);
  }
}

void loop()
{
// Put #1 frame on both Display
    sinvader1a();sinvader2a();sinvader3a();sinvader4a();
    delay(delayTime*50);
    sinvader1b();sinvader2b();sinvader3b();sinvader4b();
    delay(delayTime);


// Put #2 frame on both Display
    
    delay(delayTime);
    
    delay(delayTime);

// Put #3 frame on both Display
    
    delay(delayTime);
    
    delay(delayTime);


// Put #4 frame on both Display
    
    delay(delayTime);
    
    delay(delayTime);

}