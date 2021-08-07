#pragma once

#include <tesla.hpp>

namespace Element
{
    typedef std::function<void(void)> ButtonCallback; 

    struct Button : public tsl::elm::Element
    {
        Button(short w, short h, const std::string &buttonText, uint16_t size);

        void setCallback(ButtonCallback callback);
        void runCallback();

        tsl::elm::Element *requestFocus(tsl::elm::Element *old, tsl::FocusDirection direction) override;
        void draw(tsl::gfx::Renderer *renderer) override;
        void layout(u16 px, u16 py, u16 pw, u16 ph) override;
        bool onClick(u64 keyPressed);

        private:
        std::string text;
        uint16_t fontSize;
        bool set;

        ButtonCallback callback;
    };
} // namespace Element
