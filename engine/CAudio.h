#ifndef CAUDIO_H
#define CAUDIO_H

#include <SDL2/SDL_mixer.h>

#include <map>

class CAudio
{
    public:
        static bool enabled;
        static void Init();
        static Mix_Chunk* loadSound(char* path, bool music = false);
        static bool isMusic(Mix_Chunk* chunk);
        static void play(Mix_Chunk* chunk, int loops = 0);
    private:
        static std::map<char*, Mix_Chunk*> loadedChunks;
        static std::map<Mix_Chunk*, bool> loadedMusic;
};

#endif // CAUDIO_H
