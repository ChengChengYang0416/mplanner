#ifndef __MAVLINK_RECEIVER_HPP__
#define __MAVLINK_RECEIVER_HPP__

#include "mavlink.h"

void mavlink_attitude_quaternion_handler(mavlink_message_t *received_msg);
void mavlink_local_position_ned_handler(mavlink_message_t *received_msg);
void mavlink_polynomial_trajectory_ack_handler(mavlink_message_t *received_msg);

bool wait_mavlink_polynomial_trajectory_ack(uint8_t *ack_val);

#endif
