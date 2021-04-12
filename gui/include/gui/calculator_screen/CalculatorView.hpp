#ifndef CALCULATORVIEW_HPP
#define CALCULATORVIEW_HPP

#include <gui_generated/calculator_screen/CalculatorViewBase.hpp>
#include <gui/calculator_screen/CalculatorPresenter.hpp>

class CalculatorView : public CalculatorViewBase
{
public:
    CalculatorView();
    virtual ~CalculatorView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void displayBuffer(int i);
    virtual void addDigit(int i);

    virtual void functionButton0();
    virtual void functionButton1();
    virtual void functionButton2();
    virtual void functionButton3();
    virtual void functionButton4();
    virtual void functionButton5();
    virtual void functionButton6();
    virtual void functionButton7();
    virtual void functionButton8();
    virtual void functionButton9();

    virtual void functionButtonAC();
    virtual void functionButtonEnt();
    virtual void functionButtonSup();
    virtual void functionButtonSwap();

    virtual void functionButtonPlus();
    virtual void functionButtonMinus();
    virtual void functionButtonTimes();
    virtual void functionButtonDivid();
private:
    int bufferValue[4] = {};
    int maxCheck;
    bool operationDone = false;
    int temp;
};

#endif // CALCULATORVIEW_HPP
