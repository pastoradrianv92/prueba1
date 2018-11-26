#include "listener.h"
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "std_msgs/String.h"

#include <stdio.h>
#include <gazebo/gazebo.hh>
namespace gazebo{
	void Listener::init(){
/*en caso de que ROS no este iniciado*/
		if(!ros::isInitialized()){
			int argc=0;
			char **argv=NULL;
			ros::init(argc,argv,"gazebo_client", ros::init_options::NoSigintHandler);
		}
		this->nodo.reset(new ros::NodeHandle("gazebo_client"));
/*definimos uno de los metodos que vamos a tener,
 *  -empezando con el suscriptor, el elemento que
 *  recibe las llamadas desde afuera y le diremos que recibira una cadena de
 *  texto como parametro para enviarle comandos como las instrucciones del robot
 *  por medio de una cadena de texto, variables numericas, booleanas, etc, y
 *  - le pondremos a el topico el nombre de robot1,
 *  - de 1 parametro,
 *  - se le añade tambien un conector RosListener y le diremos que tiene ue llamara cuando
 *    alguien invoque al topic a la libreria listener y enviara el valor 1,el primer parametro
 *    que reciba de la peticion
 *  - traera in ptr de vacio
 *  - y cual cola procesara la informacion*/
		ros::SubscribeOptions so=ros::SubscribeOptions::create<std_msgs::String>(
		"/robot1",
		1,
		boost::bind(&RosListener::listener,this, _1),
		ros::VoidPtr(),
		&this->cola
		);

		/*ya definido el suscriptor se añadira al SUSCRIPTOR"*/
	this->subscriber=this->nodo->subscribe(so);
	}
	/*definir el listener, agarraremos el mensaje y los depuraremos (debug)
	 * su variable no es una variable aceptada por el debug asi que
	 * hay que hacer una conversion*/
	void Listener::listener(const std_msg::String::CostPtr& msg){
		std::string
		m->data.c_strl();
		gzdbg<<m<<"\r\n";
	}
	/*AHORA HAREMOS EL SUSCRIPTOR PARA LUEGO AÑADIR UN PUBLICADOR*/

	void Listener::conexion(const ros::SingleSubscriberPubisher&){
		ROS_INFO("Me conecto");
	}

	void Listener::desconexion(const ros::SingleSubscriberPubisher&){
		ROS_INFO("Me desconecto");
	}
	void Listener::thread(){
		static const double timeout=0.01;
		while(this->nodo->ok()){
			this->cola.callAvailable(ros::WallDuration(timeout));
		}
	}
}
