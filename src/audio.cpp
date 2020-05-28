#include <iostream>
#include "audio.h"
#include "SDL.h"
#include <SDL_mixer.h>

Audio::Audio() : gameMusic(NULL), gameOver(NULL), foodEaten(NULL), poisonEaten(NULL) {

  if( SDL_Init(SDL_INIT_AUDIO) < 0){
    printf("SDL audio could not initialize! SDL Error: %s\n", SDL_GetError());
  }
  if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
  {
    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
  }
}

void Audio::GameMusic(bool play){
  gameMusic = Mix_LoadMUS(gameMusicPath);
  if(gameMusic == NULL ) {
    printf( "Failed to load game music! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  if(play == true) {
    Mix_PlayMusic(gameMusic, -1);
  } else {
    Mix_HaltMusic();
  }
}

void Audio::GameOverSound(){
  gameOver = Mix_LoadWAV(gameOverMusicPath);
  if(gameOver == NULL ) {
    printf( "Failed to load game over music! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  Mix_PlayChannel( -1, gameOver, 0 );
}

void Audio::EatSound(){
  foodEaten = Mix_LoadWAV(foodEatenSoundPath);
  if(foodEaten == NULL ){
    printf( "Failed to load food eaten sound! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  Mix_PlayChannel( -1, foodEaten, 0 );
}

void Audio::PoisonSound(){
  poisonEaten = Mix_LoadWAV(poisonEatenSoundPath);
  if(poisonEaten == NULL )
  {
    printf( "Failed to load poison eaten sound! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  Mix_PlayChannel( -1, poisonEaten, 0 );
}

void Audio::Pause(){
  pauseSound = Mix_LoadWAV(pauseSoundPath);
  if(pauseSound == NULL ){
      printf( "Failed to load pause sound! SDL_mixer Error: %s\n", Mix_GetError() );
    }
  Mix_PlayChannel( -1, pauseSound, 0 );
}

void Audio::Unpause(){
  unpauseSound = Mix_LoadWAV(unpauseSoundPath);
  if(unpauseSound == NULL ){
    printf( "Failed to load unpause sound! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  Mix_PlayChannel( -1, unpauseSound, 0 );
}

void Audio::FreeResources(){
  Mix_FreeMusic(gameMusic);
  Mix_FreeChunk(gameOver);
  Mix_FreeChunk(foodEaten);
  Mix_FreeChunk(poisonEaten);
  Mix_FreeChunk(pauseSound);
  Mix_FreeChunk(unpauseSound);
  gameMusic = NULL;
  gameOver = NULL;
  foodEaten = NULL;
  poisonEaten = NULL;
  pauseSound = NULL;
  unpauseSound = NULL;
  Mix_Quit();
}
