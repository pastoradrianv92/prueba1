#include "robot1.h"
#include "listener.h"
#include <gazebo/gazebo.hh>
namespace gazebo{
	class robot1: public ModelPlugin{
		virtual void Load (physics::ModelPtr _model,sdf::ElementPtr_sdf){
			gzbdb<<"Hola Mundo\r\n";
			listener=new listener();
			listener->init();
		}
	};

	GZ_REGISTER_MODEL_PLUGIN(Robot1);
}
