#!/usr/bin/env perl

use strict;
use warnings;
use feature "say";
use File::Spec;
use File::Copy;

while (<STDIN>) {
    chomp;
    die "Can't parse the name '$_'" unless $_ =~ /([A-Z]{2}\d{4})\/(\w+)\//;
    my $code = $1;
    my $problem = lc $2;
    my $to = "processed/$problem";
    mkdir $to unless -e $to;
    $to .= "/$code.cc";
    copy($_, $to) or die "File: '$_' $!";
}
