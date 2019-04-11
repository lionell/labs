#!/usr/bin/env perl

# curl util
#
# Usage:
# $ ./curl.pl 'http://wttr.in?format=3'
# Kyiv, Ukraine: +9°C

use strict;
use warnings;
use HTTP::Tiny;

my $response = HTTP::Tiny->new->get(shift);
if ($response->{success}) {
    print $response->{content};
} else {
    die "Failed $response->{status} $response->{reason}";
}
