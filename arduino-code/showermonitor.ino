#define FLOWPIN 2
#define TOGGLEPIN 4

long ltime,cumul=0;
volatile int pulses=0;
unsigned int pcount=0;
boolean toggled=false;
char inbyte;

void setup()
{
  Serial.begin(115200);
  pinMode(FLOWPIN,INPUT);
  pinMode(TOGGLEPIN,OUTPUT);
  digitalWrite(TOGGLEPIN,LOW);
  attachInterrupt(0,isr,RISING); // 0=Digital Pin 2 (FLOWPIN)
  ltime=millis();
}

void isr()
{
  // We keep the interrupt service routine to a
  // bare minimum to minimise disruption and so
  // help ensure accuracy.
  pulses++;
}

void dotoggle()
{
  // TOGGLEPIN will change between HIGH and LOW
  // each five seconds. We can use an oscilloscope
  // to check timing with it, or we could attach
  // an LED and resistor for visual feedback.
  if(toggled==false)
  {
    digitalWrite(TOGGLEPIN,HIGH);
    toggled=true;
  }
  else
  {
    digitalWrite(TOGGLEPIN,LOW);
    toggled=false;
  }
}

void loop()
{
  // Send the data every 1000ms (i.e. 1 second).
  if((millis()-ltime)>=1000)
  {
    ltime=millis();
    // We will use a copy of pulses, in pcount,
    // because isr() can change the value at
    // at any time.
    pcount=pulses;
    pulses=0;
    // If used for a long period and/or with
    // high flows, remember cumul can overflow
    // to a negative value. However, it should be
    // OK for over a month (at 100 pulses every
    // five minutes) using the long data type.
    cumul+=pcount;
    dotoggle();
    Serial.print(pcount,DEC);
    Serial.print(",");
    Serial.println(cumul,DEC);
  }
  if(Serial.available()>0)
  {
    inbyte=Serial.read();
    switch(inbyte)
    {
      // This allows us to reset the flowmeter cumulative
      // counter to zero.
      case 'r': cumul=0;
                break;
    }
  }
}

