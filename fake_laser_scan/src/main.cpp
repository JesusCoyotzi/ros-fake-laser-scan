//Author: Nicolas Gallardo
//Date:7/30/17
//Filename: main.cpp
//This us the main file that utilizes the created classes

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "fake_scan_node.h"


int main(int argc, char** argv )
{
								FakeLaserScan laserScan;
								ros::init(argc, argv, "laser_scan_publisher");
								laserScan.begin();
								laserScan.fakeScanPublisher();
								return 0;
}
