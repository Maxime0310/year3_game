//Main.cpp
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include "ship.h"
#include "game.h"


using namespace sf;
using namespace std;
const int gameWidth = 800;
const int gameHeight = 600;
sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship*> ships;


void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));
    

    int row = 5;
    int column = 12;

    int rs = 0;
    int cs = 0;

    int tc = 0;
    for (int i = 0; i < column; i++)
    {
        if (tc < column)
        {
            Invader* inv = new Invader(sf::IntRect(cs, 0, 32, 32), { 100,100 });
            ships.push_back(inv);
            cs = cs + 32;
            tc = +1;
        } 
    }

}

void Update() {
    static Clock clock;
    float dt = clock.restart().asSeconds();

    for (auto& s : ships) {
        s->Update(dt);
    };
}

void Render(RenderWindow& window) {
    window.draw(invader);

    for (const auto s : ships) {
        window.draw(*s);
    }

}


int main() {
    RenderWindow window(VideoMode(gameWidth, gameHeight), "Space_Invaders");
    Load();
    while (window.isOpen()) {
        window.clear();
        //Update(window);
        Render(window);
        window.display();
    }
    return 0;
}