#!/usr/bin/env perl

# xargs util
# $ cat file
# Lorem ipsum.
# Sit dolor.
# Amet
#
# $ cat file | ./xargs util -n
# Lorem ipsum.Sit dolor.Amet

use strict;
use warnings;

for (<STDIN>) {
    chomp;
    my @cmd = @ARGV;
    push @cmd, $_;
    system @cmd;
}
