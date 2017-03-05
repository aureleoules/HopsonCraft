#ifndef CMAP_H_INCLUDED
#define CMAP_H_INCLUDED

#include <memory>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <queue>


#include "CColumn.h"
#include "CPosition.h"

class Camera;

namespace Renderer
{
    class Master;
}

namespace Chunk
{
    class Map
    {
        public:
            Map(const Camera& camera);
            ~Map();

            void update();
            void draw(Renderer::Master& renderer);

            void addChunk(const Position& pos);
            const Column* getChunklet(const Chunk::Position& pos) const;
            Column* getChunklet(const Chunk::Position& pos);

        private:
            void manageChunks();
            void loadAndGenChunks();
            void flagChunks();

            std::unordered_map<Position, std::unique_ptr<Column>> m_chunks;

            const Camera* m_p_camera;

            int8_t m_renderDistance    = 10;
            int8_t m_currentLoadDist   = 2;

            std::atomic<bool> m_isRunning;

            std::mutex m_addChunkMutex;
            std::mutex m_chunkUpdateMutex;
            std::vector<std::unique_ptr<std::thread>> m_chunkGenThreads;
    };
}

#endif // CMAP_H_INCLUDED