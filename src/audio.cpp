#include <iostream>
#include "audio.h"
// For reviewer: This whole file is an addition to the original Udacity repository.

// Create an audio object and initialize its members.
Audio::Audio() : gameMusic(NULL), gameOver(NULL), foodEaten(NULL), poisonEaten(NULL) {

  // Initialize audio and let us know if there's an error during initialization.
  if( SDL_Init(SDL_INIT_AUDIO) < 0){
    printf("SDL audio could not initialize! SDL Error: %s\n", SDL_GetError());
  }

  // Attempt to open an audio device.
  if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
  {
    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
  }
}

//PJG: free audio resources. TODO
//Audio::~Audio() {
//  Audio::FreeResources();
//}

// Controls game music. bool play acts as a signal for turning music on or off.
void Audio::GameMusic(bool play){
  gameMusic = Mix_LoadMUS(gameMusicPath); // Load music file.

  // Check for errors opening file.
  if(gameMusic == NULL ) {
    printf( "Failed to load game music! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  // If play is true turn on music, else turn off the music.
  if(play == true) {
    Mix_PlayMusic(gameMusic, -1);
  } else {
    Mix_HaltMusic();
  }
}

// Plays game over sound effect.
void Audio::GameOverSound(){
  gameOver = Mix_LoadWAV(gameOverMusicPath);
  if(gameOver == NULL ) {
    printf( "Failed to load game over music! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  Mix_PlayChannel( -1, gameOver, 0 );
}

// Plays sound effect when snake eats food (yellow block) and grows.
void Audio::EatSound(){
  foodEaten = Mix_LoadWAV(foodEatenSoundPath);
  if(foodEaten == NULL ){
    printf( "Failed to load food eaten sound! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  Mix_PlayChannel( -1, foodEaten, 0 );
}

// Plays sound effect when snake eats poison (red block) and shrinks.
void Audio::PoisonSound(){
  poisonEaten = Mix_LoadWAV(poisonEatenSoundPath);
  if(poisonEaten == NULL )
  {
    printf( "Failed to load poison eaten sound! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  Mix_PlayChannel( -1, poisonEaten, 0 );
}

// Plays sound effect when game is paused.
void Audio::Pause(){
  pauseSound = Mix_LoadWAV(pauseSoundPath);
  if(pauseSound == NULL ){
      printf( "Failed to load pause sound! SDL_mixer Error: %s\n", Mix_GetError() );
    }
  Mix_PlayChannel( -1, pauseSound, 0 );
}

// Plays sound to signal that the game has unpaused.
void Audio::Unpause(){
  unpauseSound = Mix_LoadWAV(unpauseSoundPath);
  if(unpauseSound == NULL ){
    printf( "Failed to load unpause sound! SDL_mixer Error: %s\n", Mix_GetError() );
  }
  Mix_PlayChannel( -1, unpauseSound, 0 );
}

//PJG: Free up the SDL resources used and quit mixer. TODO
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
