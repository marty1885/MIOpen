file(REMOVE_RECURSE
  "doxygen/output"
  "../../doc/html"
  "sphinx/_doctrees"
  "sphinx/_build"
  "CMakeFiles/delete_miopenexporthtml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/delete_miopenexporthtml.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
