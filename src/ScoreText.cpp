#include "ScoreText.hpp"

ScoreText::ScoreText(){
    font.loadFromFile("assets/bariol.otf");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.move(400,0);
    reset();
}

void ScoreText::internal_setScore() {
    std::string scoreText = "";
    scoreText += "Score : ";
    scoreText += std::to_string(score);
    text.setString(scoreText.c_str());
}

void ScoreText::reset(){
    score = 0;
    internal_setScore();
}

void ScoreText::add(int a){
    score += a;
    internal_setScore();
}

void ScoreText::draw(sf::RenderTarget & t, sf::RenderStates states) const{
    t.draw(text);
}
