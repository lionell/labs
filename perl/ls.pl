#!/usr/bin/env perl

# List directory
#
# Usage:
# $ ./ls.pl
# rwxr-xr-x lionell users 768     Apr 10 00:08 pretty_print.pl
# rwxr-xr-x lionell users 255     Apr 10 01:30 date.pl
# rwxr-xr-x lionell users 1400    Apr 10 02:38 hello.pl
# rw-r--r-- lionell users 290     Apr 10 00:10 out.txt
# rwxr-xr-x lionell users 655     Apr 08 21:16 currency.pl
# rw-r--r-- lionell users 145     Apr 09 23:46 test.json
# rwxr-xr-x lionell users 1680    Apr 10 02:39 ls.pl
# rwxr-xr-x lionell users 976     Apr 10 00:52 time.pl
#
# $ ./ls.pl /root
# Permission denied at ./ls.pl line 22.
#
# $ sudo ./ls.pl /root
# rwxr-xr-x root root 4096        Feb 16 00:17 .local
# rw-r--r-- root root 45          Oct 18 09:40 .nix-channels
# rwx------ root root 4096        Apr 09 20:00 .nix-defexpr
# rw------- root root 20661       Mar 23 21:59 .viminfo
# rwx------ root root 4096        Feb 16 00:17 .emacs.d
# rw------- root root 4825        Apr 01 22:58 .bash_history
# rw------- root root 50          Feb 16 00:17 .Xauthority
# rwxr-xr-x root root 4096        Feb 16 00:17 .compose-cache
# rwx------ root root 4096        Feb 16 00:17 .dbus
# rwxr-xr-x root root 4096        Oct 30 06:45 .cache

use strict;
use warnings;
use feature "say";
use experimental qw(switch);
use Fcntl qw(:mode);
use POSIX qw(strftime);
use File::stat;
use File::Spec;

sub perms {
    given (shift @_) {
        when (7) { 'rwx' }
        when (6) { 'rw-' }
        when (5) { 'r-x' }
        when (4) { 'r--' }
        when (3) { '-wx' }
        when (2) { '-w-' }
        when (1) { '--x' }
        when (0) { '---' }
        default { die "Invalid file permissions"; }
    }
}

sub fmt {
    my $path = shift @_;
    my $stats = stat $path;
    my $str = '';
    $str .= perms(($stats->mode & S_IRWXU) >> 6); # user perms
    $str .= perms(($stats->mode & S_IRWXG) >> 3); # group perms
    $str .= perms($stats->mode & S_IRWXO);        # other perms
    $str .= " " . getpwuid $stats->uid;           # user name
    $str .= " " . getgrgid $stats->gid;           # group name
    $str .= " " . -s $path;                       # file size
    $str .= "\t" . strftime "%b %d %H:%M", localtime $stats->mtime;
    $str .= " " . (split '/', $path)[-1];         # file name
}

my $dir = shift || '.';
opendir DIR, $dir or die $!;
for (sort readdir DIR) {
    my $path = File::Spec->join($dir, $_);
    next if $_ eq '.' or $_ eq '..' or -l $path; # skip '.', '..' and symbolic links
    say fmt $path;
}
closedir(DIR);
