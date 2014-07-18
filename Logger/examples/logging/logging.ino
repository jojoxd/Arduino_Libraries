#include <Bridge.h>
#include <Console.h>
#include <Logger.h>
// construct logger: Logger <any name you want>("what_ports to log on");
Logger logger("Serial, Console");
int times = 0;
int variable = 10;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Bridge.begin();
  Console.begin();
  
  // after the console loads, you can log
  
  // function                      output
  logger.Log("test", ""); //       [log]: test
  logger.Log("test1", "test2"); // [log] [test1]: test2
  
  // same goes for everything else:
  logger.Info("Casting", "you can cast variables(float, double int etc.) to string to include everything on 1 line! " + (String)variable);
}

void loop() {
  // put your main code here, to run repeatedly:
  times++;
  logger.Log("times", (String)times);
  delay(1000);
}
