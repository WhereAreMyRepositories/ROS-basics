/*
 * rosserial Publisher Example
 * Prints +Int16
 */
 #define USE_USBCON

#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle  nh;

std_msgs::Int16 int_msg;
ros::Publisher chatter("chatter", &int_msg);

int hello = 12;

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  int_msg.data = hello;
  chatter.publish( &int_msg );
  nh.spinOnce();
  delay(1000);
}
