#!/usr/bin/env perl

# sort util
#
# Usage:
# $ cat in.txt
# Lorem ipsum.
# Sit dolor.
# Amet
#
# $ ./sort.pl in.txt
# Amet
# Lorem ipsum.
# Sit dolor.
#
# $ cat in.txt | ./sort.pl
# Amet
# Lorem ipsum.
# Sit dolor.

use strict;
use warnings;
use Algorithm::Diff;
