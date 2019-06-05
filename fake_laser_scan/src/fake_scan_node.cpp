//Author: Nicolas Gallardo
//Date:7/30/17
//Filename: fake_scan_node.cpp
//This cpp file implements the classes and functions required to produce and publish fake laser scans
//as a ROS LaserScan message

//ROS includes:

#include "fake_laser_scan/fake_scan_node.h"

void FakeLaserScan::begin()
{
								//create ros node and publishers
								ros::NodeHandle n;
								scan_pub = n.advertise<sensor_msgs::LaserScan>("scan", 50);

								ros::NodeHandle nh_priv("~");

								nh_priv.param<std::string>("laser_frame",laserFrame,"base_link");
								nh_priv.param<float>("noise_var",noiseVariance,0.2);
								nh_priv.param<float>("noise_mean",noiseMean,5.0);
								nh_priv.param<float>("angle_min",angleMin,-1.07);
								nh_priv.param<float>("angle_max",angleMax,1.07);
								nh_priv.param<int>("samples_per_rev",samplesRev,400);
								nh_priv.param<float>("laser_time",laserPeriod,0.1);

								srand(time(NULL));
								return;
}

void FakeLaserScan::fakeScanPublisher()
{
								sensor_msgs::LaserScan scan;
								scan.angle_min = angleMin;
								scan.angle_max = angleMax;
								scan.angle_increment = (angleMax-angleMin) / samplesRev;
								scan.time_increment = (1 / laserPeriod) / (samplesRev);;
								scan.range_min = 0.5;
								scan.range_max = 6.0;
								scan.header.frame_id = laserFrame;
								scan.ranges.resize(samplesRev);
								scan.intensities.resize(samplesRev);
								while (ros::ok())
								{
																scan.scan_time = 0.1; //same as rate
																for(int i = 0; i < samplesRev; i++)
																{
																								float x = (float) rand() / (float)(RAND_MAX);
																								scan.ranges[i] = noiseMean + x *noiseVariance;
																								scan.intensities[i] = x*100;
																}
																scan_pub.publish(scan);
																ros::Duration(0.1).sleep();
								}
								return;

}
