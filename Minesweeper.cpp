#include "Minesweeper.h"

Minesweeper::Minesweeper(int size, std::string title) {
    window = new sf::RenderWindow(sf::VideoMode(size, size), title);
    timer = new Timer(Vector2f(300, 100), (*this));
}

Minesweeper::~Minesweeper() {
    delete window;
    delete timer;
}

void Minesweeper::run() {
    Number test(Vector2f(50, 50), *this, 0, 0, 5);
    Mine test1(Vector2f(100, 50), *this, 0, 0);
    NewGameButton newIcon(Vector2f(300, 50), *this);
    SaveButton saveIcon(Vector2f(200, 50), *this);
    LoadButton loadIcon(Vector2f(200, 100), *this);

    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window->close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                test.onClickEvent(window, event);
                test1.onClickEvent(window, event);
                newIcon.onClickEvent(window, event);
            }
        }

        window->clear();
        test.draw(window);
        test1.draw(window);
        timer->draw(window);
        newIcon.draw(window);
        saveIcon.draw(window);
        loadIcon.draw(window);
        window->display();
    }
}

void Minesweeper::gameWin() {}

//stop timer, show all mines
void Minesweeper::gameLose() {

    timer->stopTimer();
    board->revealMines();
    //Make it so you cant reveal tiles??

}

void Minesweeper::newBoard(int height, int width, int mines) {}

Board *Minesweeper::getBoard() {
    return board;
}

Timer *Minesweeper::getTimer() {
    return timer;
}