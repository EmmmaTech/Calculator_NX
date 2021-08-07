#pragma once

#include <tesla.hpp>

namespace Element
{
    struct Button;

    struct CalculatorElement : public tsl::elm::Element
    {
        CalculatorElement();
        ~CalculatorElement();

        tsl::elm::Element *requestFocus(tsl::elm::Element *old, tsl::FocusDirection dir);
        void draw(tsl::gfx::Renderer *renderer);
        void layout(u16 px, u16 py, u16 pw, u16 ph);
        bool onTouch(tsl::elm::TouchEvent event, s32 curX, s32 curY, s32 preX, s32 preY, s32 initX, s32 initY);

        private:
        void addTextToExpression(char c);

        // Number buttons
        Button *NineButton;
        Button *EightButton;
        Button *SevenButton;
        Button *SixButton;  
        Button *FiveButton; 
        Button *FourButton; 
        Button *ThreeButton;
        Button *TwoButton;  
        Button *OneButton;  
        Button *ZeroButton;
        // Operator buttons
        Button *PlusButton;
        Button *MinusButton;
        Button *MultiplyButton;
        Button *DivideButton;
        Button *EqualButton;
        Button *DotButton;

        std::string currrentExpr, screenBuffer;
    };
} // namespace Element
