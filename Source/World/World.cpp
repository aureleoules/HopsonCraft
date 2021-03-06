#include "World.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Renderer/RMaster.h"
#include "../Player/Player.h"
#include "../Camera.h"
#include "../Maths/Position_Conversion.h"

#include "../Util/STD_Util.h"

World::World(const World_Settings& worldSettings, const Camera& camera)
:   m_worldSettings (worldSettings)
,   m_pCamera       (&camera)
{

}


void World::setBlock (int x, int y, int z, CBlock block)
{

}


CBlock World::getBlock (int x, int y, int z) const
{
    return 0;
}

const World_Settings& World::getWorldSettings() const
{
    return m_worldSettings;
}

