// Player 
// By David Cheung
// Contains information about the main player

#include "Player.h"

using namespace std;


Player::Player()
{
	pMaxHealth = pHealth = 100;
	pLevel = 1;
	pGold = 0;

    pPosition.x = START_X;
	pPosition.y = START_Y;
}

Player::~Player()
{
    // Do nothing
}

// Temporary placeholder function (work in progress)
bool Player::inMap(int x, int y)
{
    return true;
}

// Player movement function
// By David Cheung
void Player::move(int direction)
{
	if(direction == keyDown)
	{
	    pDirection = keyDown;
		if(inMap(pPosition.x, pPosition.y - 1))
		{
			pPosition.y -= 0.5;
		}
	}
	else if(direction == keyUp)
	{
	    pDirection = keyUp;
		if(inMap(pPosition.x, pPosition.y + 1))
		{
			pPosition.y += 0.5;
		}
	}
	else if(direction == keyLeft)
	{
	    pDirection = keyLeft;
		if(inMap(pPosition.x - 1, pPosition.y))
		{
			pPosition.x -= 0.5;
		}
	}
	else if(direction == keyRight)
	{
	    pDirection = keyRight;
		if(inMap(pPosition.x + 1, pPosition.y))
		{
			pPosition.x += 0.5;
		}
	}
}

// Player draw function
// By David Cheung
void Player::draw()
{
    // Draw head
    worldDrawCircle(pPosition, 2.0, true, ColourRgb(1.0, 1.0, 1.0));
    
    
    // Draw hands and eyes relative to direction the player is facing
    if(pDirection == keyDown)
    {
        // Draw eyes
        worldDrawCircle(PointC((pPosition.x - 1.0), pPosition.y - 0.3), 0.3, true, ColourRgb(1.0, 1.0, 1.0));
        worldDrawCircle(PointC((pPosition.x + 1.0), pPosition.y - 0.3), 0.3, true, ColourRgb(1.0, 1.0, 1.0));
        
        // Hands        
        worldDrawCircle(PointC((pPosition.x - 2.5), pPosition.y - 0.5), 0.5, true, ColourRgb(1.0, 1.0, 1.0));
        worldDrawCircle(PointC((pPosition.x + 2.5), pPosition.y - 0.5), 0.5, true, ColourRgb(1.0, 1.0, 1.0));
    }
    else if(pDirection == keyUp)
    {
        // Draw eyes
        worldDrawCircle(PointC((pPosition.x - 1.0), pPosition.y + 0.3), 0.3, true, ColourRgb(1.0, 1.0, 1.0));
        worldDrawCircle(PointC((pPosition.x + 1.0), pPosition.y + 0.3), 0.3, true, ColourRgb(1.0, 1.0, 1.0));    
        
        // Hands
        worldDrawCircle(PointC((pPosition.x - 2.5), pPosition.y + 0.5), 0.5, true, ColourRgb(1.0, 1.0, 1.0));
        worldDrawCircle(PointC((pPosition.x + 2.5), pPosition.y + 0.5), 0.5, true, ColourRgb(1.0, 1.0, 1.0));    
    }
    else if(pDirection == keyLeft)
    {
        // Draw eyes
        worldDrawCircle(PointC((pPosition.x - 0.3), pPosition.y - 1.0), 0.3, true, ColourRgb(1.0, 1.0, 1.0));
        worldDrawCircle(PointC((pPosition.x - 0.3), pPosition.y + 1.0), 0.3, true, ColourRgb(1.0, 1.0, 1.0));    
        
        // Hands
        worldDrawCircle(PointC((pPosition.x - 0.5), pPosition.y + 2.5), 0.5, true, ColourRgb(1.0, 1.0, 1.0));
        worldDrawCircle(PointC((pPosition.x - 0.5), pPosition.y - 2.5), 0.5, true, ColourRgb(1.0, 1.0, 1.0));        
    }
    else if(pDirection == keyRight)
    {
        // Draw eyes
        worldDrawCircle(PointC((pPosition.x + 0.3), pPosition.y - 1.0), 0.3, true, ColourRgb(1.0, 1.0, 1.0));
        worldDrawCircle(PointC((pPosition.x + 0.3), pPosition.y + 1.0), 0.3, true, ColourRgb(1.0, 1.0, 1.0));
        
        // Hands
        worldDrawCircle(PointC((pPosition.x + 0.5), pPosition.y + 2.5), 0.5, true, ColourRgb(1.0, 1.0, 1.0));
        worldDrawCircle(PointC((pPosition.x + 0.5), pPosition.y - 2.5), 0.5, true, ColourRgb(1.0, 1.0, 1.0));        
    }        
}
