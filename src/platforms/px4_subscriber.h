/****************************************************************************
 *
 *   Copyright (c) 2014 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file px4_subscriber.h
 *
 * PX4 Middleware Wrapper Subscriber
 */
#pragma once
#if defined(__linux) || (defined(__APPLE__) && defined(__MACH__))
/* includes when building for ros */
#include "ros/ros.h"
#else
/* includes when building for NuttX */
#include <uORB/Subscription.hpp>
#endif

namespace px4
{

#if defined(__linux) || (defined(__APPLE__) && defined(__MACH__))
class Subscriber
{
public:
	Subscriber(ros::Subscriber ros_sub) :
		_ros_sub(ros_sub)
	{}
	~Subscriber() {};
private:
	ros::Subscriber _ros_sub;
};
#else
template<typename M>
class Subscriber :
	public uORB::Subscription<M>
public:
	Subscriber(List<SubscriptionBase *> * list,
			const struct orb_metadata *meta, unsigned interval) :
		uORB::Subsciption(list, meta, interval)
	{}
	~Subscriber() {};
{
};
#endif

}