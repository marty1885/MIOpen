file(REMOVE_RECURSE
  "doxygen/output"
  "../../doc/html"
  "sphinx/_doctrees"
  "sphinx/_build"
  "CMakeFiles/doxygen"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/doxygen.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
