#include "GameCharacters.h"

/*
* GameCharacterSystem C Includes
*/
#include <intrin.h>
#include <cstdint>
#include <malloc.h>


/*
* GameCharacterSytstem Variables
*/
__m128* Position = NULL;  //Position can contain the X,Y,Z and Face Direction Angle the Entity/Character is Facing.
 uint8_t* Health = NULL;  //Health can be a value between 0 and 100.


/*
* GameCharacterSystem Functions
*/
void GameCharacterSystem::InitializeCharacterSystem(const int intializer_size, const int alignment)
{
	//Aligns the intializer size to the next available N alignement amount. 
	const int size = ((intializer_size + alignment - 1) / alignment) * alignment;
	Position = static_cast<__m128*>(_aligned_malloc(sizeof(Position) * size, alignment));
	Health = static_cast<uint8_t*>(_aligned_malloc(sizeof(Health) * size, alignment));
}

void GameCharacterSystem::ShutdownCharacterSystem()
{
	_aligned_free(Health);
	_aligned_free(Position);
}
