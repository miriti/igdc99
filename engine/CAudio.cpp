#include "CAudio.h"

#include <iostream>

using namespace std;

void CAudio::Init()
{
    if(!enabled)
        return;

    cout << "Init audio..." << endl;

    Mix_Init(MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
}

Mix_Chunk* CAudio::loadSound(char* path, bool music)
{
    if(!enabled)
        return NULL;

    if(loadedChunks.find(path) != loadedChunks.end())
    {
        return loadedChunks[path];
    }
    else
    {
        cout << "Loading " << (music ? "MUSIC":"SFX") << " from: " << path << endl;

        Mix_Chunk* newChunk = music ? (Mix_Chunk*)Mix_LoadMUS(path) : Mix_LoadWAV(path);
        if(newChunk != NULL)
        {
            loadedChunks[path] = newChunk;
            loadedMusic[newChunk] = music;
        }
        else
        {
            cout << "Error: " << Mix_GetError() << endl;
        }
        return newChunk;
    }
}

bool CAudio::isMusic(Mix_Chunk* chunk)
{
    return loadedMusic[chunk];
}

void CAudio::play(Mix_Chunk* chunk, int loops)
{
    if(!enabled)
        return;

    if(chunk != NULL)
    {
        if(isMusic(chunk))
        {
            Mix_PlayMusic((Mix_Music*)chunk, loops);
        }
        else
        {
            Mix_PlayChannel(-1, chunk, loops);
        }
    }
    else
    {
        cout << "Null sound chunk" << endl;
    }
}

bool CAudio::enabled = true;

std::map<Mix_Chunk*, bool> CAudio::loadedMusic;
std::map<char*, Mix_Chunk*> CAudio::loadedChunks;
