#!/usr/bin/env perl

# Archive into .tar.gz
#
# Usage:
# $ ./tar.pl test.tar.gz ls.pl ps.pl
# Files successfully archived into 'test.tar.gz'
#
# $ tar tf test.tar.gz
# ping.pl
# pipe.pl

use strict;
use warnings;
use feature "say";
use Archive::Tar;

my $file = shift;
my $tar = Archive::Tar->new;
$tar->add_files(@ARGV);
$tar->write($file, COMPRESS_GZIP);
say "Files successfully archived into '$file'";
