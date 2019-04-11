#!/usr/bin/env perl

# factor util (multithreaded)
#
# Usage:
# $ time -p ./factor.pl 1125899839733759 1125899839733759 1125899839733759
# real 4.47
# user 12.04
# sys 0.00

use strict;
use warnings;
use feature "say";
use threads;

sub factor {
    my $num = shift;
    my $id = threads->tid();
    print "[$id] $num = ";

    my @factors = ();
    for (my $i = 2; $i * $i <= $num; $i++) {
        until ($num % $i) {
            $num /= $i;
            push @factors, $i;
        }
    }
    push @factors, $num if $num > 1;
    say join " * ", @factors;
}

my @threads = ();
for (@ARGV) {
    push @threads, threads->create(sub { factor $_; threads->exit(); });
}
for (@threads) {
    $_->join();
}
