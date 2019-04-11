#!/usr/bin/env perl

# kill util
#
# $ ./signal.pl &
# Going into sleep for 20 seconds.
# Press Ctrl-C to interrupt.
# Try killing the process(pid: 18277).
#
# $ ./kill.pl 18277
# Caught a SIGTERM at ./signal.pl line 23.

use strict;
use warnings;

kill SIGTERM => shift;
