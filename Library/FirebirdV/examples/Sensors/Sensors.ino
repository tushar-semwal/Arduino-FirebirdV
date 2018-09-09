/*
 * A sample code to fetch all the sensor values from the Firebird V robot and display it on the terminal. 
 * Note: If a sensor is not connected, the function will return garbage value.
 * Created by Tushar Semwal (semwaltushar@gmail.com), September 2, 2018.
 * Released into the public domain.
 */

#include <Firebird.h>

Firebird fb;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial2.begin(57600); //Uses USB cable for communication; For Xbee use Serial.begin(_baudrate)
}

void loop() {
  // read the value from the sensor:
  
  int battery = fb.readBattery();
  float batteryVolt = fb.readBatteryVolt();
    
  int wl1 = fb.readLine1();
  int wl2 = fb.readLine2();
  int wl3 = fb.readLine3();

  int ir1 = fb.readIR1();
  int ir2 = fb.readIR2();
  int ir3 = fb.readIR3();
  int ir4 = fb.readIR4();
  int ir5 = fb.readIR5();

  int sharp1 = fb.readSharpIR1();
  int sharp2 = fb.readSharpIR2();
  int sharp3 = fb.readSharpIR3();
  int sharp4 = fb.readSharpIR4();
  int sharp5 = fb.readSharpIR5();

  int sharpDistance = fb.sharpDistance(sharp3);

  Serial2.print("Battery: "); 
  Serial2.println(battery);

  Serial2.print("Batteryin Volts: "); 
  Serial2.println(batteryVolt);
  
  Serial2.print("White Line 1: ");
  Serial2.println(wl1);
  Serial2.print("White Line 2: ");
  Serial2.println(wl2);
  Serial2.print("White Line 3: ");
  Serial2.println(wl3);
  
  Serial2.print("IR 1: ");
  Serial2.println(ir1);
  Serial2.print("IR 2: ");
  Serial2.println(ir2);
  Serial2.print("IR 3: ");
  Serial2.println(ir3);
  Serial2.print("IR 4: ");
  Serial2.println(ir4);
  Serial2.print("IR 5: ");
  Serial2.println(ir5);

  Serial2.print("SharpIR 1: ");
  Serial2.println(sharp1);
  Serial2.print("SharpIR 2: ");
  Serial2.println(sharp2);
  Serial2.print("SharpIR 3: ");
  Serial2.println(sharp3);
  Serial2.print("SharpIR 4: ");
  Serial2.println(sharp4);
  Serial2.print("SharpIR 5: ");
  Serial2.println(sharp5);

  Serial2.print("Sharp Distance in mm: ");
  Serial2.println(sharpDistance);

  Serial2.println("***********************************");
  
  delay(2000);
  
}
