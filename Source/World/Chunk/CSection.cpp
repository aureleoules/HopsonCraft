#include "CSection.h"

#include <iostream>

#include "../World_Constants.h"
#include "CMap.h"

namespace Chunk
{
    Section::Section(const Chunklet_Position& position, Map& map)
    :   m_position      (position)
    ,   m_meshBuilder   (*this)
    ,   mp_chunks       (&map)
    {

    }

    void Section::makeMesh()
    {
        m_meshBuilder.generateMesh(m_meshes);
        m_meshes.solidMesh.buffer();
        made = true;
    }


    Section* Section::getSection(Block::Small_Position& position)
    {
        static const sf::Vector3<int32_t> noChnage(0, 0, 0);
        auto change = noChnage;

        auto pos = position;

        checkBound(pos.x, change.x);
        checkBound(pos.y, change.y);
        checkBound(pos.z, change.z);

        if (change == noChnage)
        {
            return this;
        }
        else
        {

            Chunk::Chunklet_Position newPos(m_position.x + change.x,
                                            0,
                                            m_position.z + change.z);
            if (change.y != 0) return nullptr;
            if (mp_chunks->existsAt({newPos.x, newPos.z}))
            {
                return mp_chunks->get({newPos.x, newPos.z});
            }
            else
            {
                return nullptr;
            }
        }
    }

    const Section* Section::getConstSection(Block::Small_Position& position) const
    {
        static const sf::Vector3<int32_t> noChnage(0, 0, 0);
        auto change = noChnage;

        auto pos = position;

        checkBound(pos.x, change.x);
        checkBound(pos.y, change.y);
        checkBound(pos.z, change.z);

        if (change == noChnage)
        {
            return this;
        }
        else
        {
            Chunk::Chunklet_Position newPos(m_position.x + change.x,
                                            0,
                                            m_position.z + change.z);
            if (change.y != 0)
                return nullptr;
            if (mp_chunks->existsAt({newPos.x, newPos.z}))
            {
                return mp_chunks->get({newPos.x, newPos.z});
            }
            else
            {
                return nullptr;
            }
        }
    }

    void Section::checkBound(int8_t& pos, int32_t& change) const
    {
        if (pos > CHUNK_SIZE - 1)
        {
            change = 1;
            pos -= CHUNK_SIZE;
        }
        else if (pos < 0)
        {
            change = -1;
            pos += CHUNK_SIZE;
        }
    }

    uint32_t Section::getIndexFrom(const Block::Small_Position& position) const
    {
        return position.y *
               CHUNK_AREA + position.z *
               CHUNK_SIZE + position.x;
    }

}