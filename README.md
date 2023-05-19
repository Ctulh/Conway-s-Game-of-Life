# Conway-s-Game-of-Life

## [Wiki](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

![Gif](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExNTNjMjU3YWIwNjY1MGM5NTA4NmM1MjVhZWY5MmQ3NGUxNTE3ZjNjOSZlcD12MV9pbnRlcm5hbF9naWZzX2dpZklkJmN0PWc/18pbqQTu8AudHJJEFo/giphy.gif)

Environmental requirements
---------------------
* CMake
* GCC / Clang (>= C++20)
* SDL2


Build
---------------------
```
git clone https://github.com/Ctulh/Conway-s-Game-of-Life
cd Conway-s-Game-of-Life
mkdir build && cd build
cmake ..
cmake --build .
```
## Arguments
| Argument number | Meaning                                   |
|-----------------|-------------------------------------------|
| 1st             | Amount of cells columns. By default - 10. | 
| 2nd             | Amount of cells rows. By default - 10.    |    
| 3rd             | Window width. By default - 800.           |
| 4th             | Window height. By default - 800.          |        

## Actions

| Key          | Action                                         |
|--------------|------------------------------------------------|
| Space        | Pause/Unpause game. By default game is paused. |
| Mouse Button | Place/Remove cells.                            |
| C            | Toggle grid                                    |
