#!/usr/bin/env perl

# Handle system signals
#
# Usage:
# $ ./signal.pl
# Going into sleep for 20 seconds.
# Press Ctrl-C to interrupt.
# Try killing the process(pid: 5212).
# ^CCaught a SIGINT at ./signal.pl line 25.
#
# $ ./signal.pl & kill 5213
# Going into sleep for 20 seconds.
# Press Ctrl-C to interrupt.
# Try killing the process(pid: 5213).
# Caught a SIGTERM at ./signal.pl line 26.

use strict;
use warnings;
use feature "say";

$SIG{INT} = sub { die "Caught a SIGINT"; };
$SIG{TERM} = sub { die "Caught a SIGTERM"; };

say "Going into sleep for 20 seconds.";
say "Press Ctrl-C to interrupt.";
say "Try killing the process(pid: $$).";
sleep(20);
say "Finished successfully!"
