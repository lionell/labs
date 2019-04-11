#!/usr/bin/env perl

# Show process list via external call
#
# Usage:
# $ ./ps.pl
# USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
# lionell   2483  0.0  0.0 146924  3616 pts/1    S+   Apr08   0:00 tmux a -t main
# lionell   7231  0.0  0.0 300816  4872 pts/4    Ss+  Apr07   0:00 -fish
# lionell   7361  0.0  0.0 300816  4976 pts/5    Ss+  Apr07   0:00 -fish
# lionell   8568  0.0  0.0 115336 11624 ?        S    00:31   0:16 i3bar
# lionell   8569  0.0  0.0 605260  6084 ?        Sl   00:31   0:32 i3status
# lionell   9773  0.0  0.0 133504  2304 pts/6    R+   23:17   0:00 ps ux
# lionell  13356  0.0  0.0 311972  9944 pts/6    Ss   01:44   0:08 -fish
# lionell  30060  0.0  0.0 299200  7120 pts/3    Ss   Apr09   0:00 -fish
# lionell  30158  0.0  1.9 509316 324544 pts/3   S+   Apr09   0:13 perl -MCPAN -e shell
# lionell  31479  0.0  0.2 180748 36160 ?        Ss   Apr02   2:09 tmux new -s main
# lionell  31704  0.0  0.0 377932  8332 pts/2    Ss+  Apr02   0:27 -fish
# ...

use strict;
use warnings;

system ("ps", "ux");
