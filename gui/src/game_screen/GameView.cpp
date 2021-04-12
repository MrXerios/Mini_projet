#include <gui/game_screen/GameView.hpp>

GameView::GameView()
{

}

void GameView::setupScreen()
{
    GameViewBase::setupScreen();
}

void GameView::tearDownScreen()
{
    GameViewBase::tearDownScreen();
}

void GameView::functionButtonUp()
{
    if (!pauseFlag)
    {
        tilePos = tilePos - tileVelocity;
        if (tilePos < 10)
            tilePos = 10;

        drawTile = true;

        if (tilePos == 10)
            buttonState(false,true);
        else
            buttonState(true,true);
    }
}

void GameView::functionButtonDown()
{
    if (!pauseFlag)
    {
        tilePos = tilePos + tileVelocity;
        if (tilePos > 262 - tileSize)
            tilePos = 262;

        drawTile = true;

        if (tilePos == 262)
            buttonState(true,false);
        else
            buttonState(true,true);

    }
}

void GameView::buttonState(bool upState, bool downState)
{
    buttonUp.setTouchable(upState);
    buttonDown.setTouchable(downState);
}

void GameView::functionButtonPause()
{
    pauseFlag = true;
}

void GameView::functionButtonPlay()
{
    pauseFlag = false;
}

void GameView::handleTickEvent()
{
    if (drawTile)
    {
        tile.setPosition(350,tilePos,10,tileSize);
        tile.invalidate();
        //boxGame.invalidate();
    }
    if (!pauseFlag)
    {
        xball = xball + xVelocity;
        yball = yball + yVelocity;

        if (yball <= 10)
        {
            yVelocity = -yVelocity;
            yball = 10 + (10-yball);
        }
        else if (yball > 262 - ballSize)
        {
            yVelocity = -yVelocity;
            yball = 262 - ballSize - (yball-262+ballSize);
        }

        if (xball <= 10)
        {
            xVelocity = -xVelocity;
            xball = 10 + (10-xball);
        }
        else if (xball > 350 - ballSize)
        {
            if ((yball < tilePos-ballSize/2) || (yball > tilePos + tileSize-ballSize/2))
            {
                presenter->saveScore(score);
                lose();
            }
            score++;
            Unicode::snprintf(scoreAreaBuffer,SCOREAREA_SIZE, "%d", score);
            scoreArea.invalidate();

            if ((score == 10) || (score == 50))
            {
                xVelocity = xVelocity * 2;
                yVelocity = yVelocity * 2;
            }

            xVelocity = -xVelocity;
            xball = 350 - ballSize - (xball-350+ballSize);
        }
        ball.setPosition(xball,yball,ballSize,ballSize);
        ball.invalidate();
        boxGame.invalidate();
    }
}
