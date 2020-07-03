#ifndef SCORETEXT_HPP
#define SCORETEXT_HPP

#include <SFML/Graphics.hpp>
#include <string>

class ScoreText : public sf::Drawable{
private:
    sf::Font font;
    sf::Text text;
    int score;
    void internal_setScore();
public:
    ScoreText();
    void reset();
    void add(int a);
    void draw(sf::RenderTarget & t, sf::RenderStates states) const;
};

#endif // SCORETEXT_HPP
