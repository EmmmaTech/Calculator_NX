#include <CalculatorElement.hpp>

#include <Button.hpp>
#include <calculator.hpp>

namespace Element
{
    /*
        '                '
        '9'  '8'  '7'  '+'
        '6'  '5'  '4'  '-'
        '3'  '2'  '1'  '*'
        '.'  '0'  '='  '/'
    */

    #define BUTTON_WIDTH 80
    #define BUTTON_HEIGHT 80
    #define FONT_SIZE 20

    #define PADDING_WIDTH (BUTTON_WIDTH + 10)
    #define PADDING_HEIGHT BUTTON_HEIGHT * 2

    CalculatorElement::CalculatorElement() : tsl::elm::Element()
    {
        // Number buttons
        NineButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "9", FONT_SIZE);
        NineButton->setParent(this);
        NineButton->setCallback([this]{this->addTextToExpression('9');});

        EightButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "8", FONT_SIZE);
        EightButton->setParent(this);
        EightButton->setCallback([this]{this->addTextToExpression('8');});

        SevenButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "7", FONT_SIZE);
        SevenButton->setParent(this);
        SevenButton->setCallback([this]{this->addTextToExpression('7');});

        SixButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "6", FONT_SIZE);
        SixButton->setParent(this);
        SixButton->setCallback([this]{this->addTextToExpression('6');});

        FiveButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "5", FONT_SIZE);
        FiveButton->setParent(this);
        FiveButton->setCallback([this]{this->addTextToExpression('5');});

        FourButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "4", FONT_SIZE);
        FourButton->setParent(this);
        FourButton->setCallback([this]{this->addTextToExpression('4');});

        ThreeButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "3", FONT_SIZE);
        ThreeButton->setParent(this);
        ThreeButton->setCallback([this]{this->addTextToExpression('3');});

        TwoButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "2", FONT_SIZE);
        TwoButton->setParent(this);
        TwoButton->setCallback([this]{this->addTextToExpression('2');});

        OneButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "1", FONT_SIZE);
        OneButton->setParent(this);
        OneButton->setCallback([this]{this->addTextToExpression('1');});

        ZeroButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "0", FONT_SIZE);
        ZeroButton->setParent(this);
        ZeroButton->setCallback([this]{this->addTextToExpression('0');});

        // Operator buttons
        PlusButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "+", FONT_SIZE);
        PlusButton->setParent(this);
        PlusButton->setCallback([this]{this->addTextToExpression('+');});

        MinusButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "-", FONT_SIZE);
        MinusButton->setParent(this);
        MinusButton->setCallback([this]{this->addTextToExpression('-');});

        MultiplyButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "*", FONT_SIZE);
        MultiplyButton->setParent(this);
        MultiplyButton->setCallback([this]{this->addTextToExpression('*');});

        DivideButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "/", FONT_SIZE);
        DivideButton->setParent(this);
        DivideButton->setCallback([this]{this->addTextToExpression('/');});

        DotButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, ".", FONT_SIZE);
        DotButton->setParent(this);
        DotButton->setCallback([this]{this->addTextToExpression('.');});

        EqualButton = new Button(BUTTON_WIDTH, BUTTON_HEIGHT, "=", FONT_SIZE);
        EqualButton->setParent(this);
        EqualButton->setCallback([this] {
            if (this->currrentExpr != "")
            {
                double result = Calculator::getInstance().evaluateExpression(this->currrentExpr);
                this->screenBuffer += "\n= " + std::to_string(result);
                this->currrentExpr = ""; 
            }
        });
    }

    CalculatorElement::~CalculatorElement()
    {
        delete NineButton;
        delete EightButton;
        delete SevenButton;
        delete SixButton;
        delete FiveButton;
        delete FourButton;
        delete ThreeButton;
        delete TwoButton;
        delete OneButton;
        delete ZeroButton;
        delete PlusButton;
        delete MinusButton;
        delete MultiplyButton;
        delete DivideButton;
        delete DotButton;
        delete EqualButton;
    }

    tsl::elm::Element *CalculatorElement::requestFocus(tsl::elm::Element *old, tsl::FocusDirection dir)
    {
        switch (dir)
        {
            case tsl::FocusDirection::None:
                return NineButton->requestFocus(old, dir);

            case tsl::FocusDirection::Left:
                if (old == PlusButton)
                    return SevenButton->requestFocus(old, dir);
                else if (old == SevenButton)
                    return EightButton->requestFocus(old, dir);
                else if (old == EightButton)
                    return NineButton->requestFocus(old, dir);
                
                else if (old == MinusButton)
                    return FourButton->requestFocus(old, dir);
                else if (old == FourButton)
                    return FiveButton->requestFocus(old, dir);
                else if (old == FiveButton)
                    return SixButton->requestFocus(old, dir);

                else if (old == MultiplyButton)
                    return OneButton->requestFocus(old, dir);
                else if (old == OneButton)
                    return TwoButton->requestFocus(old, dir);
                else if (old == TwoButton)
                    return ThreeButton->requestFocus(old, dir);

                else if (old == DivideButton)
                    return EqualButton->requestFocus(old, dir);
                else if (old == EqualButton)
                    return ZeroButton->requestFocus(old, dir);
                else if (old == ZeroButton)
                    return DotButton->requestFocus(old, dir);
                break;

            case tsl::FocusDirection::Right:
                if (old == NineButton)
                    return EightButton->requestFocus(old, dir);
                else if (old == EightButton)
                    return SevenButton->requestFocus(old, dir);
                else if (old == SevenButton)
                    return PlusButton->requestFocus(old, dir);

                else if (old == SixButton)
                    return FiveButton->requestFocus(old, dir);
                else if (old == FiveButton)
                    return FourButton->requestFocus(old, dir);
                else if (old == FourButton)
                    return MinusButton->requestFocus(old, dir);

                else if (old == ThreeButton)
                    return TwoButton->requestFocus(old, dir);
                else if (old == TwoButton)
                    return OneButton->requestFocus(old, dir);
                else if (old == OneButton)
                    return MultiplyButton->requestFocus(old, dir);

                else if (old == DotButton)
                    return ZeroButton->requestFocus(old, dir);
                else if (old == ZeroButton)
                    return EqualButton->requestFocus(old, dir);
                else if (old == EqualButton)
                    return DivideButton->requestFocus(old, dir);
                break;

            case tsl::FocusDirection::Up:
                if (old == DotButton)
                    return ThreeButton->requestFocus(old, dir);
                else if (old == ThreeButton)
                    return SixButton->requestFocus(old, dir);
                else if (old == SixButton)
                    return NineButton->requestFocus(old, dir);

                else if (old == ZeroButton)
                    return TwoButton->requestFocus(old, dir);
                else if (old == TwoButton)
                    return FiveButton->requestFocus(old, dir);
                else if (old == FiveButton)
                    return EightButton->requestFocus(old, dir);

                else if (old == EqualButton)
                    return OneButton->requestFocus(old, dir);
                else if (old == OneButton)
                    return FourButton->requestFocus(old, dir);
                else if (old == FourButton)
                    return SevenButton->requestFocus(old, dir);

                else if (old == DivideButton)
                    return MultiplyButton->requestFocus(old, dir);
                else if (old == MultiplyButton)
                    return MinusButton->requestFocus(old, dir);
                else if (old == MinusButton)
                    return PlusButton->requestFocus(old, dir);
                break;

            case tsl::FocusDirection::Down:
                if (old == NineButton)
                    return SixButton->requestFocus(old, dir);
                else if (old == SixButton)
                    return ThreeButton->requestFocus(old, dir);
                else if (old == ThreeButton)
                    return DotButton->requestFocus(old, dir);

                else if (old == EightButton)
                    return FiveButton->requestFocus(old, dir);
                else if (old == FiveButton)
                    return TwoButton->requestFocus(old, dir);
                else if (old == TwoButton)
                    return ZeroButton->requestFocus(old, dir);

                else if (old == SevenButton)
                    return FourButton->requestFocus(old, dir);
                else if (old == FourButton)
                    return OneButton->requestFocus(old, dir);
                else if (old == OneButton)
                    return EqualButton->requestFocus(old, dir);

                else if (old == PlusButton)
                    return MinusButton->requestFocus(old, dir);
                else if (old == MinusButton)
                    return MultiplyButton->requestFocus(old, dir);
                else if (old == MultiplyButton)
                    return DivideButton->requestFocus(old, dir);
                break;
        }

        return old->requestFocus(old, dir);
    }

    void CalculatorElement::draw(tsl::gfx::Renderer *renderer)
    {
        renderer->drawRect(this->getX(), this->getY(), PADDING_WIDTH * 4, BUTTON_HEIGHT, tsl::Color(53, 53, 53, 0xF));
        renderer->drawString(this->screenBuffer.c_str(), false, this->getX(), this->getY() + BUTTON_HEIGHT / 2, 20, tsl::style::color::ColorText);

        NineButton->frame(renderer);
        EightButton->frame(renderer);
        SevenButton->frame(renderer);
        SixButton->frame(renderer);
        FiveButton->frame(renderer);
        FourButton->frame(renderer);
        ThreeButton->frame(renderer);
        TwoButton->frame(renderer);
        OneButton->frame(renderer);
        ZeroButton->frame(renderer);

        PlusButton->frame(renderer);
        MinusButton->frame(renderer);
        MultiplyButton->frame(renderer);
        DivideButton->frame(renderer);
        DotButton->frame(renderer);
        EqualButton->frame(renderer);
    }

    void CalculatorElement::layout(u16 px, u16 py, u16 pw, u16 ph)
    {
        NineButton->    setBoundaries(this->getX(),                     this->getY() + BUTTON_HEIGHT,                      BUTTON_WIDTH, BUTTON_HEIGHT);
        EightButton->   setBoundaries(this->getX() + PADDING_WIDTH,     this->getY() + BUTTON_HEIGHT,                      BUTTON_WIDTH, BUTTON_HEIGHT);
        SevenButton->   setBoundaries(this->getX() + PADDING_WIDTH * 2, this->getY() + BUTTON_HEIGHT,                      BUTTON_WIDTH, BUTTON_HEIGHT);
        PlusButton->    setBoundaries(this->getX() + PADDING_WIDTH * 3, this->getY() + BUTTON_HEIGHT,                      BUTTON_WIDTH, BUTTON_HEIGHT);
        SixButton->     setBoundaries(this->getX(),                     this->getY() + PADDING_HEIGHT,                     BUTTON_WIDTH, BUTTON_HEIGHT);
        FiveButton->    setBoundaries(this->getX() + PADDING_WIDTH,     this->getY() + PADDING_HEIGHT,                     BUTTON_WIDTH, BUTTON_HEIGHT);
        FourButton->    setBoundaries(this->getX() + PADDING_WIDTH * 2, this->getY() + PADDING_HEIGHT,                     BUTTON_WIDTH, BUTTON_HEIGHT);
        MinusButton->   setBoundaries(this->getX() + PADDING_WIDTH * 3, this->getY() + PADDING_HEIGHT,                     BUTTON_WIDTH, BUTTON_HEIGHT);
        ThreeButton->   setBoundaries(this->getX(),                     this->getY() + PADDING_HEIGHT + BUTTON_HEIGHT,     BUTTON_WIDTH, BUTTON_HEIGHT);
        TwoButton->     setBoundaries(this->getX() + PADDING_WIDTH,     this->getY() + PADDING_HEIGHT + BUTTON_HEIGHT,     BUTTON_WIDTH, BUTTON_HEIGHT);
        OneButton->     setBoundaries(this->getX() + PADDING_WIDTH * 2, this->getY() + PADDING_HEIGHT + BUTTON_HEIGHT,     BUTTON_WIDTH, BUTTON_HEIGHT);
        MultiplyButton->setBoundaries(this->getX() + PADDING_WIDTH * 3, this->getY() + PADDING_HEIGHT + BUTTON_HEIGHT,     BUTTON_WIDTH, BUTTON_HEIGHT);
        DotButton->     setBoundaries(this->getX(),                     this->getY() + PADDING_HEIGHT + BUTTON_HEIGHT * 2, BUTTON_WIDTH, BUTTON_HEIGHT);
        ZeroButton->    setBoundaries(this->getX() + PADDING_WIDTH,     this->getY() + PADDING_HEIGHT + BUTTON_HEIGHT * 2, BUTTON_WIDTH, BUTTON_HEIGHT);
        EqualButton->   setBoundaries(this->getX() + PADDING_WIDTH * 2, this->getY() + PADDING_HEIGHT + BUTTON_HEIGHT * 2, BUTTON_WIDTH, BUTTON_HEIGHT);
        DivideButton->  setBoundaries(this->getX() + PADDING_WIDTH * 3, this->getY() + PADDING_HEIGHT + BUTTON_HEIGHT * 2, BUTTON_WIDTH, BUTTON_HEIGHT);
    }

    bool CalculatorElement::onTouch(tsl::elm::TouchEvent event, s32 curX, s32 curY, s32 preX, s32 preY, s32 initX, s32 initY)
    {
        if (event != tsl::elm::TouchEvent::Release)
            return false;

        if (curX > NineButton->getX() && curX < NineButton->getX() + BUTTON_WIDTH 
        && curY > NineButton->getY() && curY < NineButton->getY() + BUTTON_HEIGHT)
        {
            NineButton->runCallback();
            return true;
        }
        else if (curX > EightButton->getX() && curX < EightButton->getX() + BUTTON_WIDTH 
        && curY > EightButton->getY() && curY < EightButton->getY() + BUTTON_HEIGHT)
        {
            EightButton->runCallback();
            return true;
        }
        else if (curX > SevenButton->getX() && curX < SevenButton->getX() + BUTTON_WIDTH 
        && curY > SevenButton->getY() && curY < SevenButton->getY() + BUTTON_HEIGHT)
        {
            SevenButton->runCallback();
            return true;
        }
        else if (curX > SixButton->getX() && curX < SixButton->getX() + BUTTON_WIDTH 
        && curY > SixButton->getY() && curY < SixButton->getY() + BUTTON_HEIGHT)
        {
            SixButton->runCallback();
            return true;
        }
        else if (curX > FiveButton->getX() && curX < FiveButton->getX() + BUTTON_WIDTH 
        && curY > FiveButton->getY() && curY < FiveButton->getY() + BUTTON_HEIGHT)
        {
            FiveButton->runCallback();
            return true;
        }
        else if (curX > FourButton->getX() && curX < FourButton->getX() + BUTTON_WIDTH 
        && curY > FourButton->getY() && curY < FourButton->getY() + BUTTON_HEIGHT)
        {
            FourButton->runCallback();
            return true;
        }
        else if (curX > ThreeButton->getX() && curX < ThreeButton->getX() + BUTTON_WIDTH 
        && curY > ThreeButton->getY() && curY < ThreeButton->getY() + BUTTON_HEIGHT)
        {
            ThreeButton->runCallback();
            return true;
        }
        else if (curX > TwoButton->getX() && curX < TwoButton->getX() + BUTTON_WIDTH 
        && curY > TwoButton->getY() && curY < TwoButton->getY() + BUTTON_HEIGHT)
        {
            TwoButton->runCallback();
            return true;
        }
        else if (curX > OneButton->getX() && curX < OneButton->getX() + BUTTON_WIDTH 
        && curY > OneButton->getY() && curY < OneButton->getY() + BUTTON_HEIGHT)
        {
            OneButton->runCallback();
            return true;
        }
        else if (curX > ZeroButton->getX() && curX < ZeroButton->getX() + BUTTON_WIDTH 
        && curY > ZeroButton->getY() && curY < ZeroButton->getY() + BUTTON_HEIGHT)
        {
            ZeroButton->runCallback();
            return true;
        }

        else if (curX > PlusButton->getX() && curX < PlusButton->getX() + BUTTON_WIDTH 
        && curY > PlusButton->getY() && curY < PlusButton->getY() + BUTTON_HEIGHT)
        {
            PlusButton->runCallback();
            return true;
        }
        else if (curX > MinusButton->getX() && curX < MinusButton->getX() + BUTTON_WIDTH 
        && curY > MinusButton->getY() && curY < MinusButton->getY() + BUTTON_HEIGHT)
        {
            MinusButton->runCallback();
            return true;
        }
        else if (curX > MultiplyButton->getX() && curX < MultiplyButton->getX() + BUTTON_WIDTH 
        && curY > MultiplyButton->getY() && curY < MultiplyButton->getY() + BUTTON_HEIGHT)
        {
            MultiplyButton->runCallback();
            return true;
        }
        else if (curX > DivideButton->getX() && curX < DivideButton->getX() + BUTTON_WIDTH 
        && curY > DivideButton->getY() && curY < DivideButton->getY() + BUTTON_HEIGHT)
        {
            DivideButton->runCallback();
            return true;
        }
        else if (curX > EqualButton->getX() && curX < EqualButton->getX() + BUTTON_WIDTH 
        && curY > EqualButton->getY() && curY < EqualButton->getY() + BUTTON_HEIGHT)
        {
            EqualButton->runCallback();
            return true;
        }
        else if (curX > DotButton->getX() && curX < DotButton->getX() + BUTTON_WIDTH 
        && curY > DotButton->getY() && curY < DotButton->getY() + BUTTON_HEIGHT)
        {
            DotButton->runCallback();
            return true;
        }

        return false;
    }

    void CalculatorElement::addTextToExpression(char c)
    {
        currrentExpr += c;
        screenBuffer = currrentExpr;
    }
} // namespace Element
