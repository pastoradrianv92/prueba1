#ifndef LISTENER
#define LISTENER

#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "std_msgs/String.h"

#include <stdio.h>
#include <thread>

namespace gazebo{
	class Listener{
	private:
			std::unique_ptr<ros::NodeHandle> nodo;
			ros::Subscriber subscriber;
			ros::Publisher publisher;
			ros::CallbackQueue cola;
			ros::CallbackQueue cola2;
			std::thread threadColas;

	public:
			void init();
			void listener(const std_msgs::String::CostPtr& msg);
			static void conexion(const ros::SingleSubscriberPubisher&);
			static void desconexion(const ros::SingleSubscriberPubisher&);
			void thread();

	};
}

#endif
