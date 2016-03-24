#ifndef RADIX_PHYSICS_SYSTEM_HPP
#define RADIX_PHYSICS_SYSTEM_HPP

#include <radix/core/event/EventDispatcher.hpp>
#include <radix/system/System.hpp>

class btBroadphaseInterface;
class btDefaultCollisionConfiguration;
class btSequentialImpulseConstraintSolver;
class btDiscreteDynamicsWorld;
class btGhostPairCallback;

namespace radix {

class CollisionDispatcher;
class Uncollider;

class PhysicsSystem : public System {
private:
  EventDispatcher::CallbackPointer cpCompAdd, cpCompRem;

  friend class Uncollider;
  Uncollider *filterCallback;

  btBroadphaseInterface *broadphase;
  btDefaultCollisionConfiguration *collisionConfiguration;
  CollisionDispatcher *dispatcher;
  btSequentialImpulseConstraintSolver *solver;
  btDiscreteDynamicsWorld *physWorld;
  btGhostPairCallback *gpCallback;

public:
  PhysicsSystem(World&);
  ~PhysicsSystem();

  const char* getName() const {
    return "PhysicsSystem";
  }

  TypeId getTypeId() const {
    return System::getTypeId<std::remove_reference<decltype(*this)>::type>();
  }

  btDiscreteDynamicsWorld& getPhysWorld() const {
    return *physWorld;
  }

  void update(float dtime);
};

} /* namespace radix */

#endif /* RADIX_PHYSICS_SYSTEM_HPP */
