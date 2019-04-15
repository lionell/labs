#!/usr/bin/env perl

# md5sum util
#
# Usage:
# $ ./md5sum.pl test.json
# 2bd2e3973c48e87576172ef59584f627
#
# $ cat test.json | ./md5sum.pl
# 2bd2e3973c48e87576172ef59584f627
#
# $ md5sum test.json
# 2bd2e3973c48e87576172ef59584f627  test.json

use strict;
use warnings;
use Digest::MD5 qw(md5_hex);

print md5_hex join '', <>;
