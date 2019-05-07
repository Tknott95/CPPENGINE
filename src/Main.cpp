#include "Game.cpp"


// void PauseGame(sf::RenderWindow& window, Scene& scene) {
//   game_mode = PAUSED;
//   scene.GetCurMusic().setVolume(GetVol());
//   UnlockMouse(window);
//   scene.SetExposure(0.5f);
// }

int windowInit()
{
 //Load the font   
  Game game;
  game.run();
  return 0;
}

int main()
{
  windowInit();
}
