#!/usr/bin/env perl

# hexdump util
#
# Usage:
# $ ./hexdump.pl 64 $(which bash)
# 00000000  7f 45 4c 46 02 01 01 00  00 00 00 00 00 00 00 00
# 00000010  02 00 3e 00 01 00 00 00  b0 0a 42 00 00 00 00 00
# 00000020  40 00 00 00 00 00 00 00  d0 0b 0f 00 00 00 00 00
# 00000030  00 00 00 00 40 00 38 00  0a 00 40 00 1e 00 1d 00
#
# $ hexdump -C -n 64 $(which bash)
# 00000000  7f 45 4c 46 02 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
# 00000010  02 00 3e 00 01 00 00 00  b0 0a 42 00 00 00 00 00  |..>.......B.....|
# 00000020  40 00 00 00 00 00 00 00  d0 0b 0f 00 00 00 00 00  |@...............|
# 00000030  00 00 00 00 40 00 38 00  0a 00 40 00 1e 00 1d 00  |....@.8...@.....|

use strict;
use warnings;

my ($count, $binary) = @ARGV;
open my $file, "<:raw", $binary;
for (0 .. $count - 1) {
    printf "%08x ", $_ unless $_ % 16;   # show offset every 16 bytes
    read($file, my $byte, 1);            # read one byte
    printf " " unless $_ % 8;            # additional whitespace every 8 bytes
    printf "%02x ", ord $byte;           # print byte
    printf "\n" unless ($_ + 1) % 16;    # move to new line after 16 bytes
}
close $file;
