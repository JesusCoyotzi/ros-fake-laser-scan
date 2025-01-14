//Author: Nicolas Gallardo
//Date:7/30/17
//This header file defines the classes and functions required to produce and publish fake laser scans
//a as ROS LaserScan message

#ifndef FAKE_SCAN_NODE_H_
#define FAKE_SCAN_NODE_H_

//ROS includes:

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <time.h>
#include <std_msgs/Float32.h>



class FakeLaserScan {

public:
FakeLaserScan(){
};
void begin();
void fakeScanPublisher();

private:
ros::Publisher scan_pub;
std::string laserFrame;
float noiseVariance,noiseMean;
float angleMin, angleMax;
float laserPeriod;
int samplesRev;
std_msgs::Float32 angle_min;
std_msgs::Float32 angle_max;
std_msgs::Float32 angle_increment;
std_msgs::Float32 time_increment;
std_msgs::Float32 scan_time;
std_msgs::Float32 range_min;
std_msgs::Float32 range_max;
std_msgs::Float32 ranges[];
std_msgs::Float32 intensities[];
std_msgs::Float32 last_scan_time;
std_msgs::Float32 current_scan_time;

};


#endif /* FAKE_SCAN_NODE_H_ */
