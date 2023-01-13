# this bat file will compile the C program to *.gb

# compile to game
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFR_FOR_REG -o hello_world.o hello_world.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -DUSE_SFR_FOR_REG -c game.gb hello_world.o

# move it to the simulator directory
cp ./game.gb ~/gbdk/simulator/rom/game.gb