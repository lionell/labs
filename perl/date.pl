#!/usr/bin/env perl

# date util
#
# Usage:
# $ ./date.pl
# Wed Apr 10 00:51:58 EEST 2019
#
# $ date
# Wed Apr 10 00:51:58 EEST 2019

use strict;
use warnings;
use POSIX qw(strftime);
use feature "say";

say strftime "%a %b %e %H:%M:%S %Z %Y", localtime;
