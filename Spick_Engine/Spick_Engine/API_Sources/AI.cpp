#include "..\API_Headers\AI.hpp"

spic::AI::AI(spic::GameObject persuerGameObject, spic::GameObject escapeeGameObject, double speed, bool gameObjectAvoidanceActivated) : wandertheta(0), speed(speed), gameObjectAvoidanceActivated(gameObjectAvoidanceActivated)
{
    persuer = std::make_unique<spic::GameObject>(persuerGameObject);
    escapee = std::make_unique<spic::GameObject>(escapeeGameObject);
    vel.Set(0);
    acc.Set(0);
}

spic::Point spic::AI::Wander()
{
    double wanderR = 32;
    double wanderD = 120;
    int change = 10;
    wandertheta += rand() % change + (change * -1);

    spic::Point pos = vel;
    pos.Normalize();
    pos.Mult(wanderD);
    pos.Add(persuer->getTransform()->position);
    double h = atan2(vel.y, vel.x);

    spic::Point offset;
    offset.x = wanderR * cos(wandertheta + h);
    offset.y = wanderR * sin(wandertheta + h);

    spic::Point target;
    target.x = pos.x;
    target.y = pos.y;
    target.Add(offset);

    if (gameObjectAvoidanceActivated)
    {
        target = GameObjectAvoidance(target);
    }

    sight = pos;
    return Seek(target);
}

spic::Point spic::AI::Persue()
{
    auto target = escapee->getTransform()->position;
    spic::Point prediction;
    prediction.x = cos(escapee->getTransform()->rotation);
    prediction.y = sin(escapee->getTransform()->rotation);
    target.Add(prediction);
    auto targetWithWallAvoidance = GameObjectAvoidance(target);
    if (gameObjectAvoidanceActivated)
    {
        if (targetWithWallAvoidance.x != target.x && targetWithWallAvoidance.y != target.y)
        {
            return Seek(targetWithWallAvoidance);
        }
    }
    return Seek(target);
}

spic::Point spic::AI::Seek(spic::Point target)
{
    spic::Point force;
    force.Sub(target, persuer->getTransform()->position);
    force.SetMag(speed);
    force.Sub(vel);
    force.Limit(0.25);
    acc.Add(force);
    vel.Add(acc);
    vel.Limit(10);
    return vel;
}

spic::Point spic::AI::GameObjectAvoidance(spic::Point target)
{
    if (!collisionObjectName.empty())
    {
        auto collisionObject = Collision::AABB(persuer.get(), collisionObjectName);

        if (!collisionObject.empty())
        {
            auto collisionObjectPos = collisionObject[0]->GetGameObject()->getTransform()->position;
            if (collisionObjectPos.y >= persuer->getTransform()->position.y)
            {
                target.y += (-1000);
                target.x += -500;
            }
            else if (collisionObjectPos.y <= persuer->getTransform()->position.y)
            {
                target.y += 1000;
                target.x += (-500);
            }

            if (collisionObjectPos.x >= persuer->getTransform()->position.x)
            {
                target.x += (-1000);
                target.y += 500;
            }
            else if (collisionObjectPos.x <= persuer->getTransform()->position.x)
            {
                target.x += 1000;
                target.y += (-500);
            }
        }
    }
    
    return target;
}

void spic::AI::Update(spic::GameObject persuerGameObject, spic::GameObject escapeeGameObject)
{
    auto persueTrans = *persuer->getTransform();
    persueTrans.position = persuerGameObject.getTransform()->position;
    persuer->setTransform(&persueTrans);

    auto escapeeTrans = *escapee->getTransform();
    escapeeTrans.position = escapeeGameObject.getTransform()->position;
    escapeeTrans.rotation = escapeeGameObject.getTransform()->rotation;
    escapee->setTransform(&escapeeTrans);
}
