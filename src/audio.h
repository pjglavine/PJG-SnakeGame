#ifndef AUDIO_H
#define AUDIO_H
#include <iostream>
#include "SDL.h"
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

// For reviewer: This whole file is an addition to the original Udacity repository.

//Audio class to provide in-game music and event sounds.

class Audio {

public:
  Audio(); // Constructor
  void GameMusic(bool play); // Plays game music.

  // Sound effect functions.
  void GameOverSound();
  void EatSound();
  void PoisonSound();
  void Pause();
  void Unpause();

  void FreeResources(); // Reclaim SDL resources

  //SDL Mixer objects for in game sounds
  Mix_Music *gameMusic;
  Mix_Chunk *gameOver;
  Mix_Chunk *foodEaten;
  Mix_Chunk *poisonEaten;
  Mix_Chunk *pauseSound;
  Mix_Chunk *unpauseSound;

private:

  // paths to game sound assets.
  const char* gameMusicPath = "assets/snakegamemusic.wav";
  const char* gameOverMusicPath = "assets/gameover.wav";
  const char* foodEatenSoundPath = "assets/goodfood.wav";
  const char* poisonEatenSoundPath = "assets/badfood.wav";
  const char* pauseSoundPath = "assets/pause.wav";
  const char* unpauseSoundPath = "assets/unpause.wav";
};

#endif
