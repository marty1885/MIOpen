file(REMOVE_RECURSE
  "doxygen/output"
  "../../doc/html"
  "sphinx/_doctrees"
  "sphinx/_build"
  "CMakeFiles/copyover_installreadme"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/copyover_installreadme.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()