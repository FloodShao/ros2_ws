#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/World.hh>

namespace gazebo_hello_world
{

class WorldPluginTutorial : public gazebo::WorldPlugin{
    public:
        WorldPluginTutorial() : WorldPlugin(){
            printf("Hello World!\n");
        }

        void Load(gazebo::physics::WorldPtr _world, sdf::ElementPtr _sdf){

        }
};

GZ_REGISTER_WORLD_PLUGIN(WorldPluginTutorial)

}