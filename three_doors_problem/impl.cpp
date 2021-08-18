/*
The following contents are copied from:
https://betterexplained.com/articles/understanding-the-monty-hall-problem/

The Monty Hall problem (or the Three Doors Problem)
is a counter-intuitive statistics puzzle:
1. There are 3 doors, behind which are two goats and a car.
2. You pick a door (call it door A). You¡¯re hoping for the car of course.
3. Monty Hall, the game show host, examines the other doors (B & C) and opens one with a goat. (If both doors have goats, he picks randomly.)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	constexpr size_t EPOCH = 100000;
	size_t changeDoor = 0, notChangeDoor = 0;

	srand(time(NULL));

	for (size_t i = 0; i < EPOCH; i++)
	{
		size_t doorOfCar = rand() % 3;
		size_t firstGuess = rand() % 3;

		if (doorOfCar == firstGuess)
			notChangeDoor++;
		else if (doorOfCar != firstGuess)
			changeDoor++;
	}
	printf("Guess correctly if do not change the door: %d, rate of correctness: %.2f%%\n", notChangeDoor, (float)notChangeDoor/ EPOCH * 100);
	printf("Guess correctly if change the door: %d, rate of correctness: %.2f%%", changeDoor, (float)changeDoor / EPOCH * 100);

	// WAIT! Why this implementation is CORRECT??
	/*
	Let's say if the player picked the correct door, then the strategy of not change the door will win.
	As we know that there are three doors, so the player will have 1/3 of possibility to get the right door and 2/3 of possibility to get the wrong door.
	So we can directly add 1 (for correct guess) to "notChangeDoor" if the guess == the answer.
	And if the player choose to change the door, he will definitely get a WRONG ANSWER.
	NOW, forget about the first strategy.
	In the remaining 2/3 of posibility, the HOST WILL REMOVE AN INCORRECT ANSWER
	So there are 2 ramaining doors, 1 correct door and 1 door of the first guess.
	As the player use the strategy of change the door in the first guess.
	He/She will definitely get the correct answer!
	Therefore we can directly add 1 to "changeDoor" if the first guess is not correct.
	*/
}


