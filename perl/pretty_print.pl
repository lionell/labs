#!/usr/bin/env perl

# JSON pretty printer
#
# Usage:
# $ cat test.json
# {"classes":["Chemistry","Math","Litreture"],"gender":null,"name":"Foo Bar","email":"foo@bar.com","address":{"city":"Fooville","planet":"Earth"}}
# $ ./pretty_print.pl test.json
# {
#     "address" : {
#         "city" : "Fooville",
#          "planet" : "Earth"
#     },
#     "classes" : [
#         "Chemistry",
#         "Math",
#         "Litreture"
#     ],
#     "email" : "foo@bar.com",
#     "gender" : null,
#     "name" : "Foo Bar"
# }
#
# Alternative usage:
# $ cat test.json | ./pretty_print.pl

use strict;
use warnings;
use JSON::MaybeXS;

print JSON::MaybeXS
    ->new(pretty => 1, sort_by => 1)
    ->encode(JSON::MaybeXS::decode_json join "", <>);
