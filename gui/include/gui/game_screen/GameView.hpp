#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include <gui_generated/game_screen/GameViewBase.hpp>
#include <gui/game_screen/GamePresenter.hpp>

class GameView : public GameViewBase
{
public:
    GameView();
    virtual ~GameView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void functionButtonUp();
    virtual void functionButtonDown();
    virtual void buttonState(bool, bool);

    virtual void functionButtonPause();
    virtual void functionButtonPlay();

    virtual void handleTickEvent();
protected:
    int tickCounter = 0;

    bool pauseFlag = true;
    bool drawTile = false;

    int xball = 141;
    int yball = 74;
    int xVelocity = -1;
    int yVelocity = -1;

    int tilePos = 116;
    int tileVelocity = 1;

    const int ballSize = 16;
    const int tileSize = 40;

    int16_t score = 0;

};

#endif // GAMEVIEW_HPP
