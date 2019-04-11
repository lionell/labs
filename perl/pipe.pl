#!/usr/bin/env perl

# Process communication via named pipe
#
# Usage:
# $ ./pipe.pl
# [27555] Named pipe 'pipe.p' created.
# [27555] 'Ping' sent.
# [27555] 'Ping' sent.
# [27555] 'Ping' sent.
# [27555] 'Ping' sent.
# [27555] 'Ping' sent.
# [27556] 'Ping' received.
# [27556] 'Ping' received.
# [27556] 'Ping' received.
# [27556] 'Ping' received.
# [27556] 'Ping' received.
# [27555] Named pipe 'pipe.p' removed.

use strict;
use warnings;
use feature "say";
use POSIX qw(mkfifo);

my $filename = "named.pipe";
mkfifo($filename, 0700) or die $!;
say "[$$] Named pipe '$filename' created.";
if (fork) {
    # Parent
    open my $out, ">", $filename or die $!;
    for (1 .. 5) {
        say "[$$] 'Ping' sent.";
        say $out "Ping";
    }
    close $out;
    wait;
    unlink($filename) or die $!;
    say "[$$] Named pipe '$filename' removed.";
} else {
    # Child
    open my $in, "<", $filename or die $!;
    while (<$in>) {
        chomp;
        say "[$$] '$_' received.";
    }
    close $in;
}
