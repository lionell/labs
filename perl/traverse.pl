#!/usr/bin/env perl

# Recursively traverse directory
#
# Usage:
# $ ./traverse.pl
# ./README.md
# ./currency.pl
# ./date.pl
# ./env.pl
# ./hello.pl
# ./id.pl
# ./ls.pl
# ./out.txt
# ./pretty_print.pl
# ./pwent.pl
# ./signal.pl
# ./test.json
# ./time.pl
# ./traverse.pl
#
# $ ./traverse.pl ~/dev/labs/os
# /home/lionell/dev/labs/os/lab1
# /home/lionell/dev/labs/os/lab1/Makefile
# /home/lionell/dev/labs/os/lab1/in.txt
# /home/lionell/dev/labs/os/lab1/main.cc
# /home/lionell/dev/labs/os/lab2
# /home/lionell/dev/labs/os/lab2/Makefile
# /home/lionell/dev/labs/os/lab2/child.cc
# /home/lionell/dev/labs/os/lab2/main.cc
# /home/lionell/dev/labs/os/lab2/main.o
# /home/lionell/dev/labs/os/lab2/pipes.cc

use strict;
use warnings;
use feature "say";
use File::Spec;

sub traverse {
    my $path = shift;
    return unless -d $path;
    opendir my $dir, $path or die $!;
    for (sort readdir $dir) {
        next if $_ eq '.' or $_ eq '..';
        my $new = File::Spec->join($path, $_);
        say $new;
        traverse($new);
    }
    closedir $dir;
}

traverse (shift || '.');
