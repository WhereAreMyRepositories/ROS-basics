/*
 * Prints value from sensor like potentiometer
 */
 #define USE_USBCON

#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle  nh;

std_msgs::Int16 int_msg;
ros::Publisher chatter("chatter", &int_msg);

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  Serial.begin(57600);
}

void loop()
{
  
  int_msg.data = analogRead(A0);
  chatter.publish( &int_msg );
  nh.spinOnce();
  delay(1000);
}
