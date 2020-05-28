#ifndef AUDIO_H
#define AUDIO_H
#include <iostream>
#include "SDL.h"
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

class Audio {

public:
  Audio();
  void GameMusic(bool play);
  void GameOverSound();
  void EatSound();
  void PoisonSound();
  void Pause();
  void Unpause();
  void FreeResources();
  Mix_Music *gameMusic;
  Mix_Chunk *gameOver;
  Mix_Chunk *foodEaten;
  Mix_Chunk *poisonEaten;
  Mix_Chunk *pauseSound;
  Mix_Chunk *unpauseSound;

private:
  const char* gameMusicPath = "assets/snakegamemusic.wav";
  const char* gameOverMusicPath = "assets/gameover.wav";
  const char* foodEatenSoundPath = "assets/goodfood.wav";
  const char* poisonEatenSoundPath = "assets/badfood.wav";
  const char* pauseSoundPath = "assets/pause.wav";
  const char* unpauseSoundPath = "assets/unpause.wav";
};

#endif
