#ifndef OUGI_FONT_HPP
#define OUGI_FONT_HPP
#include <map>
#include <string>


namespace og {

    enum class FontId {
        Thin,
        Light,
        Regular,
        Bold
    };

    const std::map<og::FontId, std::string> fontPathById = {
        {og::FontId::Thin, "res/font/Roboto/Roboto-Thin.ttf"},
        {og::FontId::Light, "res/font/Roboto/Roboto-Light.ttf"},
        {og::FontId::Regular, "res/font/Roboto/Roboto-Regular.ttf"},
        {og::FontId::Bold, "res/font/Roboto/Roboto-Bold.ttf"}
    };    
    
    
} // namespace og


#endif