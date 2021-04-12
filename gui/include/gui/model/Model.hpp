#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/hal/types.hpp>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    int16_t getScore()
    {
        return score;
    }

    int16_t getBestScore()
    {
        return bestScore;
    }

    void saveScore(int16_t currentScore)
    {
        score = currentScore;
        if (currentScore > bestScore)
            bestScore = currentScore;
    }

    void saveBest(int16_t currentScore)
    {
        bestScore = currentScore;
    }

    void tick();
protected:
    ModelListener* modelListener;
    int16_t score = 0;
    int16_t bestScore = 0;
};

#endif // MODEL_HPP
