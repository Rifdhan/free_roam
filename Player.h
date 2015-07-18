// Player
// By David Cheung
// Contains information about the main player

#ifndef PLAYER_H
#define PLAYER_H

#include "primitives.h"
#include <string>
#include "graphics.h"
#include <math.h>
#include <GL/glut.h>

#define START_X 0
#define START_Y 0   


// Direction constants that we use for moving the character
enum eDirections
{
	keyDown = 0,
	keyUp,
	keyLeft,
	keyRight
};

// Main player class
// By David Cheung
class Player
{
public:
    // Constructors and destructors
    Player();
    //Player(std::string name);
    ~Player();


    // Setters and getters
    void setName(std::string newName)		    { pName = newName; }
	void setHealth(int newHealth)			    { pHealth = newHealth; }
	void setMaxHealth(int maxHealth)			{ pMaxHealth = maxHealth; }
    void setExperience(int experience)			{ pExperience = experience; }
	void setLevel(int level)					{ pLevel = level; }
	void setGold(int gold)						{ pGold = gold; }

    int getHealth()								{ return pHealth; }
	int getMaxHealth()							{ return pMaxHealth; }
	int getExperience()							{ return pExperience; }
	int getLevel()								{ return pLevel; }
	int getGold()								{ return pGold; }
	std::string getName()						{ return pName; }
    double getAngle()                           { return playerAngle; }

    PointC getPosition()						{ return pPosition; }
	void setPosition(PointC newPosition)		{ pPosition = newPosition; }

    bool isAlive()								{ return (pHealth > 0); }
    void move(int direction);
    bool inMap(int x, int y);

    void angleRotate(double mouseX, double mouseY);
    // Draw player
    void draw();

protected:
	PointC pPosition;	// Player's position
	std::string pName;	// Player's name
    int pMaxHealth;	    // Player's max health
    int pHealth;		// Player's current health

    int pGold;			// Player's gold
	int pExperience;	// Player's experience points
	int pLevel;		    // Player's level
    int pDirection;     // Player's direction  
    float playerAngle; // Player's direction (angle) 
};

#endif // PLAYER_H
