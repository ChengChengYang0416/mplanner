#include <math.h>
#include <thread>
#include <ros/ros.h>
#include "ros_thread.hpp"
#include "shell_thread.hpp"
#include "mavlink_thread.hpp"
#include "pose.hpp"
#include "serial.hpp"

extern uav_pose_t uav_pose;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "mplanner");
	ros::Time::init();

	//serial_init("/dev/ttyUSB1", 115200);

	init_uav_pose(&uav_pose);

	std::thread thread_ros(ros_thread_entry);
	std::thread thread_shell(shell_thread_entry);
	//std::thread thread_mavlink(mavlink_thread_entry);

	thread_ros.join();
	thread_shell.join();
	//thread_mavlink.join();

	return 0;
}
