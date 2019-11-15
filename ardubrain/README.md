# ArduBrain
ArduBrain is an application for the arduboy that trains your brain and tracks the enhancements using minigames and tests.

# Tests

## Reflex
- [x] Press the A button as soon as the screen change color: the faster the reflex, the higher the score.
- [ ] The screen has the dpad (up-down-left-right) and buttons (A,B) on screen. Now and then one of the 6 onscreen buttons changes color and the player needs to click the button that matches the onscreen one as soon as possible and before the onscreen button reverts to its previous color.

## Attention
- [ ] There is an image in the screen, then another comes and the user should press A if it matches the previous, or B if it's new. As fast as possible.
- [ ] There are some arrows that points in one of the N,S,W,E directions traveling in one of the N,S,W,E directions: if the arrow is filled, the player should click the d-pad of pointing direction, if the arrow is only the outline, the player should click the d-pad of the traveling direction.

## Planning
- [x] Classic game with a 4x4 grid containing 15 numbers and a hole. The player has to sort the numbers.

## Cognitive
- [ ] Predict where a ball will hit. It could be a game about positioning a bucket to where a ball will fall. Higher difficulties could add pegs that bounce the ball.

## Auditory
- [ ] The arduboy generates a random sequence of notes and plays it. The player is then showed a grid of notes where it need to recreate the sequence. The fewer attempts, the higher the score.

## Focus
- [x] Breathing exercise where the user should follow his breath and press A while inhaling and releasing while exhaling. The app guides the user with how long to inhale and how long to exhale.

## Memory

### Numeric Memory
- [x] Show to the player a sequence of two digit numbers for some time and let it memorize it.  Then 4 two digit numbers appear on screen and the player need to choose the right one to recreate the sequence.  The longer it manages, the higher the score.

### Mnemonic major system
- [x] Show one number from 0 to 99 (or a word) and 4 words (or 4 numbers) and the player needs to choose the one that maps to the Major Memory System's right PEG.  Faster right answer, higher score.

### Visual Memory
- [x] There is a grid with some white squares. After one second all squares are black and the player needs to remember which ones changed.
- [ ] Some figures are shown for some time, then the player is shown a different set of figures and needs to identify which ones are new, or which ones are from the previous set.

### Verbal Memory
- [x] A word appears on the screen and the player needs to click A if it's new or B if it appeared before. Then more words appear. The 100 words from the Major Memory System's PEG can be reused here.

### Spatial Memory
- [x] A small maze is shown on screen completely, then the game start. The player needs to go from one point to another. The twist is that the field of view of the player is only 5x5 or 3x3 or 1x1 cells: every other cell of the town is hidden and the player needs to navigate by memory.

### Associative Memory
- [x] The application shows 20 pairs of random words for 10 seconds each and ask the user to make a small story with each pair. Then it follows with one minute of basics equations (bigger than or smaller than). Finally, the application shows one word from the pairs and 4 words, one of each is the correct one to match.
