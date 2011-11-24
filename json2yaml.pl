#!/usr/bin/perl -w

use strict;
use YAML::Syck;
use JSON;

local $/;
open( my $readfh, '<', 'history.json' );
open(my $writefh, '>', 'history.yaml');
my $json_text   = <$readfh>;
my  $data = decode_json( $json_text );
DumpFile($writefh,$data);
