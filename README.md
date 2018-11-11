# Divination

This game started off as a weekend long Game Jam project while I was interning at Square. I decided to spend a couple more weeks to flesh out some more functionality for the game.


Divination is a fantasy card game played on the terminal. To play, clone this repo and compile the source code. You can do so with `g++`:

```
g++ -o divination.out -g source/*.cpp -Iheaders -std=c++11
```

Now, simply run `divination.out` from the command line and it will load the game. Cloning this repo should come with a `default.deck` file that contains a list of available cards.

## Gameplay

Divination is played with two players with access to the same terminal. Opposing players take turns playing cards, attacking the opponent, and using spells/abilities. Here is a list of commands:

```
help -- Display this message.
end -- End the current player's turn.
quit -- End the game.
attack minion target -- Orders minion to attack the target minion.
attack minion -- Orders minion to attack the opponent.
play card [player target] -- Play card, optionally targeting player's target minion.
use minion [player target] -- Use minion's special ability, optionally targeting player's target minion.
hand -- Describe all cards in your hand.
board -- Describe all cards on the board.
```

### Rules

Here is a quick rundown of the rules / flow of the game:
- Each Player starts with 2 magic, 20 health and 4 Cards.
- Player 1 starts first.
- At the beginning of each turn (except the first), the active Player gains 1 magic and draws 1 card (if they can).
- A turn consists of any number of valid commands and lasts until the active Player types "end".
- The first Player to 0 health loses.
  
### Keywords
**Magic**: The resource used to play cards.

**Graveyard**: Contains the most recent `Minion` that died for each Player.

**Deathrattle**: An effect that gets triggered when that specific `Minion` dies.

**Charges**: The number of activations remaining for a `Ritual`.

**Resurrect**: Bring a `Minion` back to life with its base stats.

**Summon**: Create a `Minion` and put it immediately into play (as long as there is room on the board).

### The Board
![An example Divination board](https://github.com/codetroopa/divination/raw/master/screenshots/example_board.png)


### Card Types

**Minions**: The primary type of cards in Divination to defeat your opponent. Each turn (including the turn they are first played), a `Minion` can either attack an opposing `Minion`, or attack the opposing Player. When attacking another `Minion`, each `Minion` deals its damage to each other and is removed to the `Graveyard` if its health falls to 0 or below.

![Minion](https://github.com/codetroopa/divination/raw/master/screenshots/example_minion.png)

**Rituals**: A special kind of card that has an inital cost, and an activation cost each time its special ability is triggered. Each player has room for one `Ritual` at a time. Playing a `Ritual` when one was already in play removes the older one.

![Ritual](https://github.com/codetroopa/divination/raw/master/screenshots/example_ritual.png)

**Spells**: One-time use cards that carry out the action described in its text.

**Enchantments**: A card that modifies the stats or capabilities of the selected `Minion`. Any `Enchantment` can be cast on either Player's `Minion`, unless indicated otherwise. `Enchantments` are applied in the same order they were played (if/when order matters).
