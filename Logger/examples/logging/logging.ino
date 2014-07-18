#include <Bridge.h>
#include <Console.h>
#include <LoggerConsole2.h>
// construct logger: Logger <any name you want>("what_ports to log on");
Logger logger("Serial, Console");
int SEC_DELAY = 1;
int times = 0;

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  Console.begin();
  
  // after the console loads, you can log
  
  // function                      output
  logger.Log("test", ""); //       [log]: test
  logger.Log("test1", "test2"); // [log] [test1]: test2
  
  // same goes for everything else:
}

void loop() {
  // put your main code here, to run repeatedly:
  times++;
  logger.Log("times", (String)times);
  delay(1000 * SEC_DELAY);
}
