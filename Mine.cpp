#include "Mine.h"
#include "Minesweeper.h"

// Constructor just calls tile constructor
Mine::Mine(std::string textureFilepath, sf::Vector2f pos, Minesweeper &game, std::string hiddenTextureFilepath, int xBoardPos, int yBoardPos)
    : Tile(textureFilepath, pos, game, hiddenTextureFilepath, xBoardPos, yBoardPos) {}

// No memory cleaning neccessary
Mine::~Mine() {}

// Overrides behaviour of firstTileClicked()
bool Mine::firstTileClicked() {
    if (game.getBoard()->getRevealedTiles() == 0) {
        game.getTimer()->startTimer();
        game.getBoard()->swapTiles(xBoardPos, yBoardPos);
        return true; // Swapped mine
    }
    return false; // No swapped mine
}

// Overrides behaviour of showTile()
void Mine::showTile() {
    // Only shows tile and ends game if a mine was not swapped
    if (!firstTileClicked()) {
        sprite.setTexture(hiddenTexture);
        shown = true;
        game.gameLose();
    }
}