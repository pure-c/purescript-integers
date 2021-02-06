{ name = "integers"
, dependencies = [ "math", "maybe", "prelude", "assert", "console", "partial" ]
, packages = ../pure-c/package-sets/packages.dhall
, sources = [ "src/**/*.purs", "test/**/*.purs" ]
}
