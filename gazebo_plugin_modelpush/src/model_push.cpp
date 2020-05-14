#include <functional>
#include <gazebo/common/Plugin.hh>
#include <gazebo/common/common.hh>
#include <gazebo/physics/World.hh>
#include <gazebo/physics/Model.hh>
#include <ignition/math/Vector3.hh>

namespace mymodelplugin{

class ModelPush : public gazebo::ModelPlugin {
public:
    void Load(gazebo::physics::ModelPtr _parent, sdf::ElementPtr _sdf) override{
        this->model = _parent;
        this->updateConnection = gazebo::event::Events::ConnectWorldUpdateBegin(std::bind(&ModelPush::OnUpdate, this));
    }

    void OnUpdate(){
        this->model->SetLinearVel(ignition::math::Vector3d(0.3, 0, 0));
    }

private:
    gazebo::physics::ModelPtr model;
    gazebo::event::ConnectionPtr updateConnection;
};
GZ_REGISTER_MODEL_PLUGIN(ModelPush)

}//namespace mymodelplugin