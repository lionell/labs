#!/usr/bin/env perl

# Count files in parallel (multiprocess)
#
# Usage:
# $ ./count.pl /home/lionell/dev
# PID     Count   Path
# 25064   2       /home/lionell/dev/bluck
# 25056   160     /home/lionell/dev/site
# 25063   64      /home/lionell/dev/pagerank
# 25060   67      /home/lionell/dev/smart-pacmans
# 25061   46      /home/lionell/dev/resume
# 25055   596     /home/lionell/dev/algorithmix
# 25058   510     /home/lionell/dev/slides
# 25057   2142    /home/lionell/dev/labs
# 25059   11534   /home/lionell/dev/sandbox
# 25062   15677   /home/lionell/dev/go

use strict;
use warnings;
use feature "say";
use File::Spec;

sub cnt {
    my $path = shift;
    return 1 unless -d $path;
    my $res = 0;
    for (list_dir($path)) {
        $res += cnt(File::Spec->join($path, $_));
    }
    return $res;
}

sub list_dir {
    opendir my $dir, shift or die $!;
    my @lst = grep { !/^\.{1,2}$/ } readdir $dir;
    closedir $dir;
    return @lst;
}

say "PID\tCount\tPath";
my $path = shift || '.';
my @lst = list_dir($path);
for (@lst) {
    if (not fork) {
        my $new = File::Spec->join($path, $_);
        my $count = cnt($new);
        say "$$\t$count\t$new";
        exit;
    }
}
wait for (0 .. $#lst);
