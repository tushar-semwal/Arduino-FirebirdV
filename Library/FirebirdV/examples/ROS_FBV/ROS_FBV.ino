/*
* Firebird Subscriber and Publisher example
*/

#include <Firebird.h>

#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Int16.h>

#include <firebird_v/Battery.h>
#include <firebird_v/SharpSensor.h>
#include <firebird_v/IR.h>
#include <firebird_v/WhiteLine.h>
#include <firebird_v/LCD.h>


#include <avr/io.h>
#include <util/delay.h>

#include "LCD.c"

Firebird fb;

ros::NodeHandle nh;

int x = 0;
void messageCb( const std_msgs::Empty& toggle_buzzer){
  if(x == 0)
  {
    fb.buzzerOn();   // switch ON the buzzer
    x = 1;
  }

  else 
  {
    fb.buzzerOff(); // switch OFF the buzzer
    x = 0;
  }

}

void bargraph(const std_msgs::UInt8& bargraph_msg)
{
  fb.showBargraph(bargraph_msg.data);
}

void moveMotors(const std_msgs::Int16 &speedl_msg,const std_msgs::Int16 &speedr_msg)
{
  if( (speedl_msg.data >= 0) && (speedr_msg.data >= 0) )
  {
    fb.moveForward(speedl_msg.data,speedr_msg.data);
  }
  else if( (speedl_msg.data) < 0 && (speedr_msg.data < 0) )
  {
    fb.moveBackward(speedl_msg.data,speedr_msg.data);
  }
  
  else if(speedl_msg.data >= 0)
  {
    fb.moveForwardL(speedl_msg.data);
  }
  else if(speedl_msg.data < 0)
  {
    fb.moveBackwardL(speedl_msg.data);
  }
  else if(speedr_msg.data >= 0)
  {
    fb.moveForwardR(speedr_msg.data);
  }
  else if(speedr_msg.data < 0)
  {
    fb.moveBackwardR(speedr_msg.data);
  }
 
}



//********************************************//
//credits: Function definition taken from https://github.com/badrobot15/firebird_ros
void lcd(const firebird_v::LCD &lcd_msg)
{
  lcd_cursor(lcd_msg.row,lcd_msg.col);
  lcd_string(lcd_msg.val);
}

void lcd_clear(const std_msgs::Empty& lcd_clear_msg)
{
  lcd_wr_command(0x01);
}
//********************************************//

firebird_v::Battery battery_msg;
firebird_v::SharpSensor sharp_msg;
firebird_v::IR ir_msg;
firebird_v::WhiteLine wl_msg;

//****Subscribers here*******//
ros::Subscriber<std_msgs::Empty> sub("toggle_buzzer", &messageCb );
ros::Subscriber<std_msgs::UInt8> bargraph_sub("bargraph", &bargraph);
ros::Subscriber<firebird_v::LCD> lcd_sub("lcd/print", &lcd);
ros::Subscriber<std_msgs::Empty> lcd_clear_sub("lcd/clear", &lcd_clear);
//ros::Subscriber<std_msgs::Int16, std_msgs::Int16> motor_sub("motors", &moveMotors); 


//****Publishers here*******//
ros::Publisher battery("battery", &battery_msg);
ros::Publisher sharp("sharp", &sharp_msg);
ros::Publisher ir("ir", &ir_msg);
ros::Publisher whiteline("whiteline", &wl_msg);

void setup()
{
cli();
lcd_port_config();
lcd_set_4bit();
lcd_init();  
sei();

nh.initNode();

//****Subscribers here*******//
nh.subscribe(sub);
nh.subscribe(bargraph_sub);
nh.subscribe(lcd_sub);
nh.subscribe(lcd_clear_sub);

//****Publishers here*******//
nh.advertise(battery);
nh.advertise(sharp);
nh.advertise(ir);
nh.advertise(whiteline);

}

void loop()
{
nh.spinOnce(); //STRANGE!!-- KEEP THIS AT THE FIRST STATEMENT INSIDE THE LOOP()
battery_msg.voltage = fb.readBattery();
battery.publish(&battery_msg);

sharp_msg.sharp1 = fb.readSharpIR1();
sharp_msg.sharp2 = fb.readSharpIR2();
sharp_msg.sharp3 = fb.readSharpIR3();
sharp_msg.sharp4 = fb.readSharpIR4();
sharp_msg.sharp5 = fb.readSharpIR5();
sharp.publish(&sharp_msg);

ir_msg.ir1 = fb.readIR1();
ir_msg.ir2 = fb.readIR2();
ir_msg.ir3 = fb.readIR3();
ir_msg.ir4 = fb.readIR4();
ir_msg.ir5 = fb.readIR5();
ir.publish(&ir_msg);

wl_msg.wl1 = fb.readLine1();
wl_msg.wl2 = fb.readLine2();
wl_msg.wl3 = fb.readLine3();
whiteline.publish(&wl_msg);


delay(10);
}
