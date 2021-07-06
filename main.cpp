#include <SFML\Graphics.hpp>
#include <iomanip>
#include <iostream>

#include "Structures.h"
#include "Evolution.h"
#include "ConsoleLifeTest.h"

using namespace std;

const size_t fieldSIZE = 65;							//array H && W
const size_t pxCELL_SIZE = 10;							// 1 cell siz
const size_t FSdivCS = fieldSIZE * pxCELL_SIZE;
sf::Color FillCell(0xDB, 0x70, 0x93);
sf::Color OutLine(204, 204, 204);
sf::Color GameField(102, 102, 102);
sf::Color DarkGray(0xA9, 0xA9, 0xA9);
sf::Color TEXTS(sf::Color::Black);
const Coordinates maxCoords{ fieldSIZE,fieldSIZE };

int main(){

    main_test();

    sf::Font font;
    font.loadFromFile(".//fonts//AGENCYB.TTF");

    Toad toa1({ 45,4 }, Direction::UP, maxCoords);
    Toad toa2({ 4,45 }, Direction::DOWN, maxCoords);
    Glider gli1({ 3,3 }, Direction::DOWN, maxCoords);
    Glider gli2({ 61,3 }, Direction::UP, maxCoords);
    Glider gli3({ 3,61 }, Direction::DOWN, maxCoords);
    Glider gli4({ 61,61 }, Direction::UP, maxCoords);
    RPentomino pent1({ 30,30 }, Direction::UP, maxCoords);

    vector<Colony> tgli { gli1, gli2, gli3, gli4 };
    vector<Colony> tpenta{ pent1 };
    vector<Colony> ttoad{ toa1, toa2 };

    Evolution E1(std::move(tgli));
    Evolution E2(std::move(ttoad));
    Evolution E3(std::move(tpenta));

    vector<vector<char>> mainField(maxCoords.x_);
    for (auto& vec : mainField) {
        vec.resize(maxCoords.y_);
    }

    //CELL FORM
    sf::Text cell("*", font, 15);
    cell.setFillColor(sf::Color::Black);
    cell.setStyle(sf::Style::Titlebar);
    //main windows FORM
    sf::RenderWindow mainwindow(sf::VideoMode(1024, 768), "LIFE");
    mainwindow.setFramerateLimit(65);
    //FIELD BORDER LINE FORM
    sf::RectangleShape shapeOUTTER(sf::Vector2f(FSdivCS, FSdivCS));
    shapeOUTTER.setPosition(180,50);
    shapeOUTTER.setOutlineThickness(5.f);
    shapeOUTTER.setOutlineColor(sf::Color::Black);
    shapeOUTTER.setFillColor(sf::Color::Transparent);
    //FIELD CELL FORM
    sf::RectangleShape shape(sf::Vector2f(fieldSIZE, fieldSIZE));
    shape.setFillColor(GameField);
    shape.setSize(sf::Vector2f(pxCELL_SIZE, pxCELL_SIZE));

    while (mainwindow.isOpen()) {
        mainwindow.clear(DarkGray);
        sf::Event mainev;
        while (mainwindow.pollEvent(mainev)) {
            if (mainev.type == sf::Event::Closed) {
                mainwindow.close();
            }
            if (mainev.type == sf::Event::KeyPressed) {
                if (mainev.key.code == sf::Keyboard::Escape) {
                    mainwindow.close();
                }
            }
            if (mainev.type == sf::Event::MouseButtonPressed) {
                mainwindow.close();
            }
        }
        for (size_t ptr = 0; ptr < fieldSIZE; ptr++) {
            for (size_t ptr1 = 0; ptr1 < fieldSIZE; ptr1++) {
                sf::Vector2f position(180 + (ptr % fieldSIZE * pxCELL_SIZE), 50 + (ptr1 % fieldSIZE * pxCELL_SIZE));
                shape.setPosition(position);
                mainwindow.draw(shape);
                for (const auto& colony : E1.GetColonys()) {
                    for (const Cell& cl : colony.GetColony()) {
                        if(cl.Coords_.x_ == (int)ptr && cl.Coords_.y_ == (int)ptr1) {
                            cell.setPosition(position);
                            mainwindow.draw(cell);
                        }
                    }
                }
            }

        }
        E1.LifeCircle(maxCoords);
        mainwindow.draw(shapeOUTTER);
        mainwindow.display();
        if(E1.Static() || E1.GetLifeTime() > 20.0){
            break;
        }
    }

    while (mainwindow.isOpen()) {
        mainwindow.clear(DarkGray);
        sf::Event mainev;
        while (mainwindow.pollEvent(mainev)) {
            if (mainev.type == sf::Event::Closed) {
                mainwindow.close();
            }
            if (mainev.type == sf::Event::KeyPressed) {
                if (mainev.key.code == sf::Keyboard::Escape) {
                    mainwindow.close();
                }
            }
            if (mainev.type == sf::Event::MouseButtonPressed) {
                mainwindow.close();
            }
        }
        for (size_t ptr = 0; ptr < fieldSIZE; ptr++) {
            for (size_t ptr1 = 0; ptr1 < fieldSIZE; ptr1++) {
                sf::Vector2f position(180 + (ptr % fieldSIZE * pxCELL_SIZE), 50 + (ptr1 % fieldSIZE * pxCELL_SIZE));
                shape.setPosition(position);
                mainwindow.draw(shape);
                for (const auto& colony : E2.GetColonys()) {
                    for (const Cell& cl : colony.GetColony()) {
                        if(cl.Coords_.x_ == (int)ptr && cl.Coords_.y_ == (int)ptr1) {
                            cell.setPosition(position);
                            mainwindow.draw(cell);
                        }
                    }
                }
            }

        }
        E2.LifeCircle(maxCoords);
        mainwindow.draw(shapeOUTTER);
        mainwindow.display();
        if(E2.Static() || E2.GetLifeTime() > 10.0){
            break;
        }
    }

    while (mainwindow.isOpen()) {
        mainwindow.clear(DarkGray);
        sf::Event mainev;
        while (mainwindow.pollEvent(mainev)) {
            if (mainev.type == sf::Event::Closed) {
                mainwindow.close();
            }
            if (mainev.type == sf::Event::KeyPressed) {
                if (mainev.key.code == sf::Keyboard::Escape) {
                    mainwindow.close();
                }
            }
            if (mainev.type == sf::Event::MouseButtonPressed) {
                mainwindow.close();
            }
        }
        for (size_t ptr = 0; ptr < fieldSIZE; ptr++) {
            for (size_t ptr1 = 0; ptr1 < fieldSIZE; ptr1++) {
                sf::Vector2f position(180 + (ptr % fieldSIZE * pxCELL_SIZE), 50 + (ptr1 % fieldSIZE * pxCELL_SIZE));
                shape.setPosition(position);
                mainwindow.draw(shape);
                for (const auto& colony : E3.GetColonys()) {
                    for (const Cell& cl : colony.GetColony()) {
                        if(cl.Coords_.x_ == (int)ptr && cl.Coords_.y_ == (int)ptr1) {
                            cell.setPosition(position);
                            mainwindow.draw(cell);
                        }
                    }
                }
            }

        }
        E3.LifeCircle(maxCoords);
        mainwindow.draw(shapeOUTTER);
        mainwindow.display();
        if(E2.Static() || E2.GetLifeTime() > 50.0){
            break;
        }
    }

    cout << "GFX TEST'S END OK" << endl;
    cout << "ALL TEST'S ARE DONE OK :)" << endl;
    return 0;
}
