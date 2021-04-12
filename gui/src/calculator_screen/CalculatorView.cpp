#include <gui/calculator_screen/CalculatorView.hpp>



CalculatorView::CalculatorView()
{

}

void CalculatorView::setupScreen()
{
    CalculatorViewBase::setupScreen();
    maxCheck = 1;
    for(int i = 0; i < TEXTBUFFER0_SIZE-2; i++)
        maxCheck = maxCheck*10;
}

void CalculatorView::tearDownScreen()
{
    CalculatorViewBase::tearDownScreen();
    displayBuffer(0);
}

void CalculatorView::displayBuffer(int i)
{
    switch(i)
    {
        case 0 : Unicode::snprintf(textBuffer0Buffer,TEXTBUFFER0_SIZE, "%d", bufferValue[i]);
                textBuffer0.invalidate();
                break;
        case 1 : Unicode::snprintf(textBuffer1Buffer,TEXTBUFFER1_SIZE, "%d", bufferValue[i]);
                textBuffer1.invalidate();
                break;
        case 2 : Unicode::snprintf(textBuffer2Buffer,TEXTBUFFER2_SIZE, "%d", bufferValue[i]);
                textBuffer2.invalidate();
                break;
        case 3 : Unicode::snprintf(textBuffer3Buffer,TEXTBUFFER3_SIZE, "%d", bufferValue[i]);
                textBuffer3.invalidate();
                break;
    }

    touchgfx_printf("%d\n", bufferValue[i]);
}

void CalculatorView::addDigit(int i)
{
    if(operationDone)
    {
        functionButtonEnt();
        operationDone = false;
    }

    if (bufferValue[0] <= maxCheck)
    {
        bufferValue[0] = bufferValue[0]*10+i;
    }
}

void CalculatorView::functionButton0()
{
    addDigit(0);
    displayBuffer(0);
}

void CalculatorView::functionButton1()
{
    addDigit(1);
    displayBuffer(0);
}

void CalculatorView::functionButton2()
{
    addDigit(2);
    displayBuffer(0);
}

void CalculatorView::functionButton3()
{
    addDigit(3);
    displayBuffer(0);
}

void CalculatorView::functionButton4()
{
    addDigit(4);
    displayBuffer(0);
}
void CalculatorView::functionButton5()
{
    addDigit(5);
    displayBuffer(0);
}
void CalculatorView::functionButton6()
{
    addDigit(6);
    displayBuffer(0);
}

void CalculatorView::functionButton7()
{
    addDigit(7);
    displayBuffer(0);
}

void CalculatorView::functionButton8()
{
    addDigit(8);
    displayBuffer(0);
}

void CalculatorView::functionButton9()
{
    addDigit(9);
    displayBuffer(0);
}


void CalculatorView::functionButtonAC()
{
    bufferValue[0] = 0;
    displayBuffer(0);
    operationDone = false;
}


void CalculatorView::functionButtonEnt()
{
    bufferValue[3] = bufferValue[2];
    bufferValue[2] = bufferValue[1];
    bufferValue[1] = bufferValue[0];
    bufferValue[0] = 0;
    displayBuffer(3);
    displayBuffer(2);
    displayBuffer(1);
    displayBuffer(0);
}

void CalculatorView::functionButtonSup()
{
    bufferValue[0] = (int)(bufferValue[0]/10);
    displayBuffer(0);
}

void CalculatorView::functionButtonSwap()
{
    temp = bufferValue[0];
    bufferValue[0] = bufferValue[1];
    bufferValue[1] = temp;

    displayBuffer(0);
    displayBuffer(1);
}

void CalculatorView::functionButtonPlus()
{
    bufferValue[0] = bufferValue[0] + bufferValue[1];
    bufferValue[1] = bufferValue[2];
    bufferValue[2] = bufferValue[3];
    bufferValue[3] = 0;
    displayBuffer(3);
    displayBuffer(2);
    displayBuffer(1);
    displayBuffer(0);

    operationDone = true;
}

void CalculatorView::functionButtonMinus()
{
    if (bufferValue[1] >= bufferValue[0])
    {
        bufferValue[0] = bufferValue[1] - bufferValue[0];
        bufferValue[1] = bufferValue[2];
        bufferValue[2] = bufferValue[3];
        bufferValue[3] = 0;
        displayBuffer(3);
        displayBuffer(2);
        displayBuffer(1);
        displayBuffer(0);

        operationDone = true;
    }
}

void CalculatorView::functionButtonTimes()
{
    bufferValue[0] = bufferValue[0] * bufferValue[1];
    bufferValue[1] = bufferValue[2];
    bufferValue[2] = bufferValue[3];
    bufferValue[3] = 0;
    displayBuffer(3);
    displayBuffer(2);
    displayBuffer(1);
    displayBuffer(0);

    operationDone = true;
}

void CalculatorView::functionButtonDivid()
{
    if (bufferValue[0] != 0)
    {
        bufferValue[0] = bufferValue[1]/bufferValue[0];
        bufferValue[1] = bufferValue[2];
        bufferValue[2] = bufferValue[3];
        bufferValue[3] = 0;
        displayBuffer(3);
        displayBuffer(2);
        displayBuffer(1);
        displayBuffer(0);

        operationDone = true;
    }
}
