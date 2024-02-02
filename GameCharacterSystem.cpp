#include "GameCharacters.h"

#include <intrin.h>
#include <cstdint>
#include <malloc.h>

__m128* Position = NULL;
uint8_t* Health = NULL;

/*
* Called when we first Initialize a world with Character Systems.
*/
void GameCharacterSystem::InitializeCharacterSystem(const int intializer_size, const int alignment)
{
	//Aligns the intializer size to the next available N alignement amount. 
	const int size = ((intializer_size + alignment - 1) / alignment) * alignment;
	Position = static_cast<__m128*>(_aligned_malloc(sizeof(Position) * size, alignment));
	Health = static_cast<uint8_t*>(_aligned_malloc(sizeof(Health) * size, alignment));
}

/*
* Only to be called when Game Shuts Down or we Return to something like Main Menu where no characters are needed.
*/
void GameCharacterSystem::ShutdownCharacterSystem()
{
	_aligned_free(Health);
	_aligned_free(Position);
}
